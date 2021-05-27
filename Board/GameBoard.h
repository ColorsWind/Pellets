//
// Created by colors_wind on 2021/3/18.
//

#ifndef PELLETS_GAMEBOARD_H
#define PELLETS_GAMEBOARD_H


#include "Board.h"
#include "../Pellet/SolidPellet.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QRectF>
#include <QWidget>
#include <random>
class GameWindow;
class GameBoard : public Board {


private:
    QRectF region;
    SolidPellet* launchIndicate;
    QGraphicsScene *scene = nullptr;
    bool launchLocationUpdate = false;
    bool shootMode = false; // 标记是否正在发射弹珠
    GameWindow *gameWindow;
    QGraphicsView *graphicsView;
public:
    GameBoard(int row, int col);

    void setup(GameWindow* gameWindow, QGraphicsView *graphicsView);

    void doTick();

    void mouseEvent(int x, int y);

    void nextRound() override;


    void handleShoot();

    void addOwnPellets(int n) override;

    void addScore(int n) override;



};


#endif //PELLETS_GAMEBOARD_H
