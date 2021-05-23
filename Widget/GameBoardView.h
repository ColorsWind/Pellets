//
// Created by colors_wind on 2021/5/23.
//

#ifndef PELLETS_GAMEBOARDVIEW_H
#define PELLETS_GAMEBOARDVIEW_H

#include <QGraphicsView>
class GameBoard;
class GameBoardView : public QGraphicsView {
private:
    GameBoard* gameBoard = nullptr;
public:
    GameBoardView(QWidget* widget) : QGraphicsView(widget) {}

    void setup(GameBoard* gameBoard);

protected:
    void mousePressEvent(QMouseEvent *event) override;

    void wheelEvent(QWheelEvent *event) override;

    void scrollContentsBy(int dx, int dy) override;

};


#endif //PELLETS_GAMEBOARDVIEW_H
