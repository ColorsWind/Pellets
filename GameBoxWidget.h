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
private:
    Ui::GameBoxWidget *ui;
    Board gameboard;

    void drawGridlines(QPainter* painter);


    void drawGrids(QPainter *painter);

    void drawPellets(QPainter *painter);
};

#endif // GAMEBOXWIDGET_H
