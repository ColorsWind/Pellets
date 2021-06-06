//
// Created by colors_wind on 2021/5/23.
//

#include "GameBoardView.h"
#include <QMouseEvent>
#include "Board.h"
void GameBoardView::mousePressEvent(QMouseEvent *event) {
    gameBoard->mouseEvent(event->x(), event->y());
}

void GameBoardView::scrollContentsBy(int dx, int dy) {

}

void GameBoardView::wheelEvent(QWheelEvent *event) {

}

void GameBoardView::setup(GameBoard *board) {
    this -> gameBoard = board;
}

GameBoardView::GameBoardView(QWidget *widget) : QGraphicsView(widget) {}
