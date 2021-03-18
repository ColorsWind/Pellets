//
// Created by colors_wind on 2021/3/18.
//

#include "GameBoard.h"
#include <QGraphicsView>
#include "Pellet/SolidPellet.h"



void GameBoard::doTick() {

    for (auto iter = existsPellets.begin(); iter != existsPellets.cend();) {
        auto pellet = *iter;
        pellet->move(1 / 30.0);
        pellet->update(scene);
        auto location = pellet->getLocation();
        if (location.pointY < 0) {
            pellet->reflectX();
            iter++;
        } else if (location.pointX < 0 || location.pointX > 600) {
            pellet->reflectY();
            iter++;
        } else if (location.pointY > 800) {
            iter = existsPellets.erase(iter);
        } else iter++;
    }
    if (shootMode && launchPellets < maxPellets && tick % 5 == 0) {
        auto pellet = shoot();
        pellet->draw(scene);
        launchPellets++;
    }
    if (existsPellets.empty() && launchPellets == maxPellets) {
        nextRound();
        launchPellets = 0;
        shootMode = false;
    }
    tick++;
}



void GameBoard::setup(QWidget *widget) {
    scene = new QGraphicsScene(widget);
    auto graphicsView = new QGraphicsView(widget);
    graphicsView->setScene(scene);
    graphicsView->setSceneRect(region);
    //graphicsView->setFixedSize(600, 800);
    graphicsView->show();

}

GameBoard::GameBoard(int m, int n) : Board(m, n),
                                     region(0, 0, m * 50, n * 50) {}

void GameBoard::mouseEvent(int x, int y) {
    if (!shootMode) {
        target = {(double)x, (double)y};
        shootMode = true;
    }
}


