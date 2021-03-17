#ifndef GAMEBOXWIDGET_H
#define GAMEBOXWIDGET_H

#include <QWidget>
#include "Board.h"

namespace Ui {
class GameBoxWidget;
}

class GameBoxWidget : public QWidget
{
    Q_OBJECT

public:
    GameBoxWidget(Board gameboard, QWidget *parent = nullptr);
    ~GameBoxWidget();
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void drawGridlines(QPainter* painter);

    void drawPellets(QPainter *painter);

    void drawGrids(QPainter *painter);
private:
    Ui::GameBoxWidget *ui;
    Board gameboard;



};

#endif // GAMEBOXWIDGET_H
