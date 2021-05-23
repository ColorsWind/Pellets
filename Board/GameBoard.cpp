//
// Created by colors_wind on 2021/3/18.
//

#include "GameBoard.h"
#include <QGraphicsView>
#include "../Grid/AirGrid.h"
#include "../Grid/HPGrid.h"
#include "../Constants.h"
#include "../Grid/RewardGrid.h"
#include <random>

void GameBoard::doTick() {
    bool hasPellet = !existsPellets.empty();
    for (auto iter = existsPellets.begin(); iter != existsPellets.cend();) {
        Pellet *pellet = *iter;
        if (handlePellet(pellet)) {
            iter++;
            pellet->move(1.0);
            pellet->update(scene);
        } else {
            iter = existsPellets.erase(iter);
            pellet->remove(scene);
            if (!launchLocationUpdate) {
                launchLocationUpdate = true;
                launchLocation = pellet->getLocation();
                launchIndicate->setLocation(launchLocation);
                launchIndicate->update(scene);
            }
            delete pellet;
        }
    }
    handleShoot();
    if (hasPellet && existsPellets.empty() && !shootMode) {
        nextRound();
    }
    scene->update();
    tick++;
}

#include <iostream>

using namespace std;

bool GameBoard::isCollided(int sign, double pelletCentreComponent, double gridCentreComponent) {
    return sign * (pelletCentreComponent + sign * Config::pellet_size / 2) >
           sign * (gridCentreComponent - sign * Config::grid_size / 2);
}

int GameBoard::locationToIndex(double locationComponent) {
    return int(locationComponent / Config::grid_size);
}

int GameBoard::signOfComponent(double component) {
    return component > 0 ? 1 :
           (component == 0) ? 0 : -1;
}

bool GameBoard::handlePellet(Pellet *pellet) {
    Vector velocity = pellet->getVelocity();
    Location pelletCentre = pellet->getCentre();
    // boundary check
    if (velocity.vectorY < 0 && pelletCentre.pointY - Config::pellet_size / 2 < 0) {
        pellet->reflectX();
        return true;
    } else if ((velocity.vectorX < 0 && pelletCentre.pointX - Config::pellet_size / 2 < 0)
               || (velocity.vectorX > 0
                   && pelletCentre.pointX + Config::pellet_size / 2 > Config::board_col * Config::grid_size)) {
        pellet->reflectY();
        return true;
    } else if (velocity.vectorY > 0 &&
               pelletCentre.pointY - Config::pellet_size / 2 > Config::board_row * Config::grid_size) {
        return false;
    }
    // grids check
    int signX = signOfComponent(velocity.vectorX);
    int signY = signOfComponent(velocity.vectorY);
    int indexX = locationToIndex(pelletCentre.pointX);
    int indexY = locationToIndex(pelletCentre.pointY);
    Grid *gridX = getOrNull(indexX + signX, indexY);
    Grid *gridY = getOrNull(indexX, indexY + signY);
    Grid *gridXY = getOrNull(indexX + signX, indexX + indexY);
    bool collideX = gridX && isCollided(signX, pelletCentre.pointX, gridX->getCentre().pointX);
    bool collideY = gridY && isCollided(signY, pelletCentre.pointY, gridY->getCentre().pointY);
    PelletResult result = NONE;
    if (gridX && collideX && gridX->isAlive()) {
        result = pellet->hit(this, gridX);
        if (result == REFLECT) pellet->reflectY();
        gridX->update(scene);
    } else if (gridY && collideY && gridY->isAlive()) {
        result = pellet->hit(this, gridY);
        if (result == REFLECT) pellet->reflectX();
        gridY->update(scene);
    } else if (gridXY && collideX && collideY && gridXY->isAlive()) {
        result = pellet->hit(this, gridXY);
        if (result == REFLECT) {
            pellet->reflectX();
            pellet->reflectY();
        }
        gridXY->update(scene);
    }
    pellet->update(scene);
    return result != DISAPPEAR;
}


void GameBoard::nextRound() {
    for (int x = 0; x < col; x++) {
        Grid *grid = grids[row - 1][x];
        grid->remove(scene);
        if (grid->isAlive()) cout << "游戏结束" << endl;
        delete grid;
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
    // generate grids
    double pi = acos(-1);
    int x = round;
    double possibility = (1 / (1 + exp(-x / 20.0 + 1))) * abs(cos(double(x % 16) * pi / 17));
    cout << possibility << endl;
    int numHPGrids = 0;
    for (int x = 0; x < Config::board_col; x++) {
        std::uniform_int_distribution<int> intGenerator(1, 2 * round + 1);
        Location location = {double(x * 50), 0.0};
        if (doubleGenerator(randomEngine) < possibility) {
            grids[0][x] = new HPGrid{location, intGenerator(randomEngine)};
            grids[0][x]->draw(scene);
            numHPGrids++;
        } else {
            grids[0][x] = nullptr;
        }
    }
    if (numHPGrids < Config::board_col) {
        int indexToGenerate = std::uniform_int_distribution<int>(0, numHPGrids)(randomEngine);
        for (int x = 0; x < Config::board_col; x++) {
            Location location = {double(x * 50), 0.0};
            if (grids[0][x]) continue;
            if (indexToGenerate == 0) {
                grids[0][x] = new RewardGrid(location, 1);
                grids[0][x]->draw(scene);
            } else {
                grids[0][x] = new AirGrid(location);
            }
            indexToGenerate--;
        }
    }
    round++;
}


void GameBoard::setup(QWidget *widget) {
    scene = new QGraphicsScene(widget);
    auto graphicsView = new QGraphicsView(widget);
    graphicsView->setScene(scene);
    graphicsView->setSceneRect(region);
    //graphicsView->setFixedSize(600, 800);
    graphicsView->show();
    launchIndicate->draw(scene);
    for (int y = 0; y < row; y++)
        for (int x = 0; x < col; x++)
            grids[y][x]->draw(scene);
    nextRound();

}

GameBoard::GameBoard(int row, int col) : Board(row, col),
                                         region(0, 0, col * Config::grid_size, row * Config::grid_size),
                                         launchIndicate(new SolidPellet(launchLocation, {0.0, 0.0})) {
}

void GameBoard::mouseEvent(int x, int y) {
    if (shootMode || !existsPellets.empty()) return;
    if (x != 0 && abs(double(Config::board_row * Config::grid_size - y) / x) <= Config::min_angle) return;
    if (!shootMode && existsPellets.empty()) {
        pelletsToLaunch = maxPellets;
        targetLocation = {(double) x, (double) y};
        shootMode = true;
        launchLocationUpdate = false;
    }
}

void GameBoard::handleShoot() {
    if (shootMode && pelletsToLaunch > 0 && tick % 10 == 0) {
        auto pellet = shoot();
        pellet->draw(scene);
        pelletsToLaunch--;
        if (pelletsToLaunch == 0) shootMode = false;
    }
}


