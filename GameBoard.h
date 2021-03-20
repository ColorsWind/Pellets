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

class GameBoard : public Board {


private:
    QRectF region;
    QGraphicsScene *scene;
    bool shootMode = false;
public:
    GameBoard(int row, int col);


    Location getLaunchLocation();

    void setup(QWidget *widget);

    void launch();

    void doTick();

    void mouseEvent(int x, int y);

    void nextRound() override;


    bool collidingPellet(Pellet *pellet);
};


#endif //PELLETS_GAMEBOARD_H
