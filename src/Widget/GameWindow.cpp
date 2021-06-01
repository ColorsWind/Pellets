//
// Created by colors_wind on 2021/5/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GameWindow.h" resolved

#include "GameWindow.h"
#include <QTimer>
#include <QMouseEvent>
#include "ui_GameWindow.h"
#include "Constants.h"


GameWindow::GameWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::GameWindow), gameBoard(16, 12) {
    ui->setupUi(this);
    ui->label_own_pellets->setNum(Config::initial_pellets);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(qDoTick()));
    timer->start(1000/ Config::fps);
    ui->graphicsView->setup(&gameBoard);
    gameBoard.setup(this, ui->graphicsView);
}

GameWindow::~GameWindow() {
    delete ui;
}



void GameWindow::qDoTick() {
    gameBoard.doTick();
}

void GameWindow::setScore(int n) {
    ui->label_score->setNum(n);
}

void GameWindow::setPellets(int n) {
    ui->label_own_pellets->setNum(n);
}

void GameWindow::setRound(int n) {
    ui->label_round->setNum(n);
}


