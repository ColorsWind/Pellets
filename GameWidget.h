#ifndef GAMEWIDGETT_H
#define GAMEWIDGETT_H

#include <QWidget>
#include "GameBoard.h"
#include <QMouseEvent>

namespace Ui {
class GameWidget;
}
class GameBoard;
class GameWidget : public QWidget
{
    Q_OBJECT

public slots:
    void qDoTick();
public:
    GameWidget(GameBoard* gameBoard, QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event) override;
    ~GameWidget();

private:
    Ui::GameWidget *ui;
    GameBoard *gameBoard;
    QTimer *timer;
};

#endif // GAMEWIDGETT_H
