//
// Created by colors_wind on 2021/5/23.
//

#ifndef PELLETS_GAMEWINDOW_H
#define PELLETS_GAMEWINDOW_H

class MainWindow;
class RecordWindow;
#include <QWidget>
#include "Board.h"


QT_BEGIN_NAMESPACE
namespace Ui { class GameWindow; }
QT_END_NAMESPACE

/**
 * 游戏窗体
 */
class GameWindow : public QWidget {
Q_OBJECT


public slots:

    void qDoTick();

public:
    explicit GameWindow(MainWindow *main, RecordWindow *records, QWidget *parent = nullptr);

    ~GameWindow() override;

    void init();

    void setScore(int n);

    void setPellets(int n);

    void setRound(int n);

    void closeEvent(QCloseEvent *e) override;

    void gameForceEnd();

private:
    GameBoard* gameBoard = nullptr;
    Ui::GameWindow *ui;
    QTimer *timer;
    RecordWindow *records;
    MainWindow *main;


};


#endif //PELLETS_GAMEWINDOW_H
