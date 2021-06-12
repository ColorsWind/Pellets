//
// Created by colors_wind on 2021/3/18.
//

#include "Board.h"
#include <QGraphicsView>
#include "Backend.h"
#include "../Widget/GameWindow.h"
#include <QApplication>
#include <random>

GameBoard::GameBoard(int row, int col) : Board(row, col),
                                         launchIndicate(new SolidPellet(launchLocation, {0.0, 0.0})) {
}

void GameBoard::doTick() {
    // shoot
    if (shootMode && pelletsToLaunch > 0 && tick % 10 == 0) {
        auto pellet = shoot();
        pellet->draw(scene);
        pelletsToLaunch--;
        if (pelletsToLaunch == 0) // nothing to shoot
            shootMode = false;
    }
    // highlight
    for(const auto & grid : highlightGrids) {
        grid->draw(scene);
    }
    highlightGrids.clear();

    if (!trackingPellets.empty()) {
        // process all pellets
        for (auto iter = trackingPellets.begin(); iter != trackingPellets.cend();) {
            Pellet *pellet = *iter;
            // update pellet status
            PelletResult result = updatePellet(this, pellet, this->scene, launchLocationUpdate);
            Pellet *transPellet;
            switch (result) {
                case DISAPPEAR:
                    // disappear
                    iter = trackingPellets.erase(iter);
                    pellet->remove(scene);
                    if (!launchLocationUpdate) {
                        // first pellet
                        launchIndicate->remove(scene);
                        launchLocationUpdate = true;
                        launchLocation.pointX = pellet->getLocation().pointX;
                        launchIndicate->setLocation(launchLocation);
                        launchIndicate->draw(scene);
                        launchIndicate->update(scene);

                    }
                    delete pellet;
                    break;
                case TRANSFORM:
                    // transform
                    transPellet = pellet->transform(this);
                    if (transPellet != pellet) {
                        pellet->remove(scene);
                        transPellet->move(1.0);
                        transPellet->draw(scene);
                        *iter = transPellet;
                    } else {
                        pellet->move(1.0);
                        pellet->update(scene);
                    }
                    iter++;
                    break;
//                case REFLECT:
//                    iter++;
//                    break;
                default:
                    // move
                    iter++;
                    pellet->move(1.0);
                    pellet->update(scene);
                    break;
            }
        }

        // next round
        if (trackingPellets.empty() && !shootMode) {
            nextRound();
        }
        //scene->update();

    }
    tick++;
}


void GameBoard::nextRound() {
    bool end = false;
    for (int x = 0; x < col; x++) {
        Grid *grid = grids[row - 1][x];
        grid->remove(scene);
        if (grid->isAlive())
            end = true;
        delete grid;
    }
    if (end) {
        gameWindow->gameForceEnd();
        return;
    }
    for (int y = row - 1; y > 0; y--) {
        Grid **from = grids[y - 1];
        Grid **to = grids[y];
        for (int x = 0; x < Config::board_col; x++) {
            to[x] = from[x];
            to[x]->move(Vector{0, 50});
            to[x]->update(scene);
        }
    }
    round++;
    ::nextRound(this, grids, grids[0]);
    for (int x = 0; x < Config::board_col; x++) {
        grids[0][x]->setLocation({double(x * 50), 0.0});
        grids[0][x]->draw(scene);
    }
    gameWindow->setRound(round);
}


void GameBoard::mouseEvent(int x, int y) {
    if (shootMode || !trackingPellets.empty())
        // 检查是否正处于发射模式或者是否有尚未计算完的弹珠
        return;
    if (x != 0 && abs(double(Config::board_row * Config::grid_size - y) / x) <= Config::min_angle)
        // 检查发射角度是否过小
        return;
    pelletsToLaunch = maxPellets;
    targetLocation = {(double) x, (double) y};
    shootMode = true;
    launchLocationUpdate = false;
}

void GameBoard::setup(GameWindow *window, QGraphicsView *view) {
    this->scene = new QGraphicsScene(0, 0, Config::board_col * Config::grid_size, Config::board_row * Config::grid_size,
                                     nullptr);
    this->gameWindow = window;
    this->graphicsView = view;
    view->setScene(scene);

    view->setSceneRect(scene->sceneRect());
    launchIndicate->draw(scene);
    for (int y = 0; y < row; y++)
        for (int x = 0; x < col; x++)
            grids[y][x]->draw(scene);
    nextRound();
}

void GameBoard::addOwnPellets(int n) {
    Board::addOwnPellets(n);
    gameWindow->setPellets(maxPellets);
}

void GameBoard::addScore(int n) {
    Board::addScore(n);
    gameWindow->setScore(score);
}




