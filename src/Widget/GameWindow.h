//
// Created by colors_wind on 2021/5/23.
//

#ifndef PELLETS_GAMEWINDOW_H
#define PELLETS_GAMEWINDOW_H

#include <QWidget>
#include "Board.h"


QT_BEGIN_NAMESPACE
namespace Ui { class GameWindow; }
QT_END_NAMESPACE

class GameWindow : public QWidget {
Q_OBJECT

public slots:

    void qDoTick();

public:
    explicit GameWindow(QWidget *parent = nullptr);

    ~GameWindow() override;

    void setScore(int n);

    void setPellets(int n);

    void setRound(int n);

    void closeEvent(QCloseEvent *e) override;

private:
    GameBoard gameBoard;
    Ui::GameWindow *ui;
    QTimer *timer;
};


#endif //PELLETS_GAMEWINDOW_H
