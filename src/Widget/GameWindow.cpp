//
// Created by colors_wind on 2021/5/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GameWindow.h" resolved

#include "GameWindow.h"
#include "MainWindow.h"
#include "RecordWindow.h"
#include <QTimer>
#include <QMouseEvent>
#include <QLineEdit>
#include <QInputDialog>
#include "GetUserDialog.h"
#include "ui_GameWindow.h"
#include "Constants.h"


GameWindow::GameWindow(MainWindow *main, RecordWindow *records, QWidget *parent) :
        QWidget(parent), ui(new Ui::GameWindow), gameBoard(),
        main(main), records(records) {
    ui->setupUi(this);
    ui->label_own_pellets->setNum(Config::initial_pellets);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(qDoTick()));

}

GameWindow::~GameWindow() {
    delete ui;
    delete gameBoard;
}

void GameWindow::init() {
    delete gameBoard;
    gameBoard = new GameBoard(Config::board_row, Config::board_col);
    this->setPellets(gameBoard->getOwnedPellets());
    this->setScore(gameBoard->getScore());
    this->setRound(gameBoard->getRound());
    timer->start(1000 / Config::fps);
    ui->graphicsView->setup(gameBoard);
    gameBoard->setup(this, ui->graphicsView);
}


void GameWindow::qDoTick() {
    gameBoard->doTick();
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

void GameWindow::closeEvent(QCloseEvent *e) {
    GetUserDialog dialog(this);
    dialog.deleteLater();
    timer->stop();
    if (dialog.exec()) {
        if (dialog.record) {
            records->addRecord({QDateTime::currentDateTime(),
                                dialog.user,
                                gameBoard->getRound(),
                                gameBoard->getScore()});
            records->saveData();
        }
        main->show();
        e->accept();
    } else {
        e->ignore();
        timer->start(1000 / Config::fps);
    }

}

void GameWindow::gameForceEnd() {
    timer->stop();
    GetUserDialog dialog(this);
    dialog.deleteLater();
    if (dialog.exec()) {
        if (dialog.record) {
            records->addRecord(
                    {QDateTime::currentDateTime(), dialog.user, gameBoard->getRound(), gameBoard->getScore()});
            records->saveData();
        }
        setVisible(false);
        main->setVisible(true);
    }

}



