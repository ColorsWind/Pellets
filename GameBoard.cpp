//
// Created by colors_wind on 2021/3/18.
//

#include "GameBoard.h"
#include <QGraphicsView>
#include "Grid/Grid.h"
#include "Grid/AirGrid.h"
#include "Grid/HPGrid.h"
#include "Constants.h"
#include <random>
void GameBoard::doTick() {
    for (auto pellet : existsPellets)
        collidingPellet(pellet);
    for (auto iter = existsPellets.begin(); iter != existsPellets.cend();) {
        auto pellet = *iter;
        if (collidingPellet(pellet)) {
            iter++;
            pellet->move(1.0);
            pellet->update(scene);
        } else {
            iter = existsPellets.erase(iter);
            pellet->remove(scene);
            delete pellet;
        }
    }
    if (shootMode && launchPellets < maxPellets && tick % 10 == 0) {
        auto pellet = shoot();
        pellet->draw(scene);
        launchPellets++;
    }

    if (existsPellets.empty() && launchPellets == maxPellets) {
        nextRound();
        launchPellets = 0;
        shootMode = false;
    }
    scene->update();
    tick++;
}

#include <iostream>

using namespace std;

bool GameBoard::collidingPellet(Pellet *pellet) {
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

    if (velocity.vectorX > 0 && velocity.vectorY < 0) {
        Grid *up = atOrNull(int(pelletCentre.pointX / 50), int(pelletCentre.pointY / 50) - 1);
        Grid *right = atOrNull(int(pelletCentre.pointX / 50) + 1, int(pelletCentre.pointY / 50));
        if (up && up->isAlive() &&
            pelletCentre.pointY - Config::pellet_size / 2 < up->getCentre().pointY + Config::grid_size / 2) {
            //up->colliding(pellet);
            up->hit(pellet);
            pellet->reflectX();
            up->update(scene);
        }
        else if (right && right->isAlive() &&
                 pelletCentre.pointX + Config::pellet_size / 2 > right->getCentre().pointX - Config::grid_size / 2) {
            //right->colliding(pellet);
            right->hit(pellet);
            pellet->reflectY();
            right->update(scene);
        }
    } else if (velocity.vectorX > 0 && velocity.vectorY > 0) {
        Grid *down = atOrNull(int(pelletCentre.pointX / 50), int(pelletCentre.pointY / 50) + 1);
        Grid *right = atOrNull(int(pelletCentre.pointX / 50) + 1, int(pelletCentre.pointY / 50));
        if (down && down ->isAlive() &&
            pelletCentre.pointY + Config::pellet_size / 2 > down ->getCentre().pointY - Config::grid_size / 2) {
            //down->colliding(pellet);
            down->hit(pellet);
            pellet->reflectX();
            down->update(scene);
        }
        else if (right && right->isAlive() &&
                 pelletCentre.pointX + Config::pellet_size / 2 > right->getCentre().pointX - Config::grid_size / 2) {
            //right->colliding(pellet);
            right->hit(pellet);
            pellet->reflectY();
            right->update(scene);
        }
    } else if (velocity.vectorX < 0 && velocity.vectorY < 0) {
        Grid *up = atOrNull(int(pelletCentre.pointX / 50), int(pelletCentre.pointY / 50) - 1);
        Grid *left = atOrNull(int(pelletCentre.pointX / 50) - 1, int(pelletCentre.pointY / 50));
        if (up && up->isAlive() &&
            pelletCentre.pointY - Config::pellet_size / 2 < up->getCentre().pointY + Config::grid_size / 2) {
            //up->colliding(pellet);
            up->hit(pellet);
            pellet->reflectX();
            up->update(scene);
        }
        else if (left && left->isAlive() &&
                 pelletCentre.pointX - Config::pellet_size / 2 < left->getCentre().pointX + Config::grid_size / 2) {
            //left->colliding(pellet);
            left->hit(pellet);
            pellet->reflectY();
            left->update(scene);
        }
    } else if (velocity.vectorX < 0 && velocity.vectorY > 0) {
        Grid *down = atOrNull(int(pelletCentre.pointX / 50), int(pelletCentre.pointY / 50) + 1);
        Grid *left = atOrNull(int(pelletCentre.pointX / 50) - 1, int(pelletCentre.pointY / 50));
        if (down && down ->isAlive() &&
            pelletCentre.pointY + Config::pellet_size / 2 > down ->getCentre().pointY - Config::grid_size / 2) {
            //down->colliding(pellet);
            down->hit(pellet);
            pellet->reflectX();
            pellet->hit(this, down);
            down->update(scene);
        }
        else if (left && left->isAlive() &&
                 pelletCentre.pointX - Config::pellet_size / 2 < left->getCentre().pointX + Config::grid_size / 2) {
            //left->colliding(pellet);
            left->hit(pellet);
            pellet->reflectY();
            left->update(scene);
        }
    } else {
        Grid* curr =atOrNull(int(pelletCentre.pointX / 50), int(pelletCentre.pointY / 50));
        if (curr && curr->isAlive()) {
            curr->colliding(pellet);
            curr->update(scene);
            cout << "A" << endl;
        }
    }
    pellet->update(scene);
    return true;
}


void GameBoard::nextRound() {
    for (int x = 0; x < col; x++) {
        Grid* grid = grids[row - 1][x];
        grid->remove(scene);
        if (grid->isAlive()) cout << "游戏结束" << endl;
        delete grid;
    }
    for (int y = row - 1; y > 0; y--) {
        Grid **from = grids[y - 1];
        Grid **to = grids[y];
        for (int x = 0; x < col; x++) {
            to[x] = from[x];
            to[x]->move(Vector{0, 50});
            to[x]->update(scene);
        }
    }
    // generate grids

    double pi = acos(-1);
    double possibility = (1 / (1 + exp(-round/20.0 + 1))) * abs(cos(double(round % 16) * pi / 17));
    cout<<possibility<<endl;
    for (int x = 0; x < col; x++) {
        std::uniform_int_distribution<int> intGenerator(1, 2 * round + 1);
        if (doubleGenerator(randomEngine) < possibility) {
            grids[0][x] = new HPGrid(Location{double(x * 50), 0.0}, intGenerator(randomEngine));
            grids[0][x]->draw(scene);
        } else {
            grids[0][x] = new AirGrid(Location{double(x * 50), 0.0});
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
    for (int y = 0; y < row; y++)
        for (int x = 0; x < col; x++)
            grids[y][x]->draw(scene);
    nextRound();

}

GameBoard::GameBoard(int row, int col) : Board(row, col),
                                         region(0, 0, col * 50, row * 50) {
    std::random_device rd;
    randomEngine = std::mt19937(rd());
    doubleGenerator = std::uniform_real_distribution<double>(0.0,1.0);
}

void GameBoard::mouseEvent(int x, int y) {
    if (!shootMode) {
        target = {(double) x, (double) y};
        shootMode = true;
    }
}


