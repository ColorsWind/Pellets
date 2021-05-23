//
// Created by colors_wind on 2021/5/23.
//

#ifndef PELLETS_GAMEBOARDVIEW_H
#define PELLETS_GAMEBOARDVIEW_H

#include <QGraphicsView>
class GameBoardView : public QGraphicsView {
public:
    GameBoardView(QWidget* widget) : QGraphicsView(widget) {}
protected:
    void mousePressEvent(QMouseEvent *event) override;

    void wheelEvent(QWheelEvent *event) override;

    void scrollContentsBy(int dx, int dy) override;
};


#endif //PELLETS_GAMEBOARDVIEW_H
