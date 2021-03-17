#ifndef GAMEBOXWIDGET_H
#define GAMEBOXWIDGET_H

#include <QWidget>
#include <QTimer>
#include "Board.h"

const static int FPS = 30;
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
    Location getLaunchLocation();
private:
    Ui::GameBoxWidget *ui;
    QTimer *timer;
    Board gameboard;
public slots:
    void doTick();


};

#endif // GAMEBOXWIDGET_H
