//
// Created by colors_wind on 2021/3/18.
//

#ifndef PELLETS_GAMEBOARD_H
#define PELLETS_GAMEBOARD_H


#include "Board.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QRectF>
#include <QWidget>
#include <random>
class GameBoard : public Board {


private:
    QRectF region;
    QGraphicsScene *scene;
    bool shootMode = false;
    std::mt19937 randomEngine;
    std::uniform_real_distribution<double> doubleGenerator;
public:
    GameBoard(int row, int col);


    Location getLaunchLocation();

    void setup(QWidget *widget);

    void launch();

    void doTick();

    void mouseEvent(int x, int y);

    void nextRound() override;


    bool collidingPellet(Pellet *pellet);

    inline bool isCollided(int sign, double pelletCentreComponent, double gridCentreComponent);

    inline int locationToIndex(double locationComponent);

    int signOfComponent(double component);
};


#endif //PELLETS_GAMEBOARD_H
