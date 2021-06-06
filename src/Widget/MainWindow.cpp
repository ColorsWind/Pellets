//
// Created by colors_wind on 2021/5/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "MainWindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    game = new GameWindow(nullptr);
    record = new RecordWindow(nullptr);
    connect(ui->button_start, SIGNAL(clicked()), this, SLOT(startGame()));
    connect(ui->button_quit, SIGNAL(clicked()), this, SLOT(exitGame()));
    connect(ui->button_record, SIGNAL(clicked()), this, SLOT(openRecord()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::startGame() {
    setVisible(false);
    game->show();
}

void MainWindow::exitGame() {
    QApplication::exit();
}

void MainWindow::openRecord() {
    record->setVisible(true);
}

