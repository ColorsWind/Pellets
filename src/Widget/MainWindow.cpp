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
    connect(ui->button_start, SIGNAL(clicked()), this, SLOT(start()));
}

MainWindow::~MainWindow() {
    delete ui;
}

#include <iostream>
using namespace std;
void MainWindow::start() {
    setVisible(false);
    game->show();
    cout << "Start" << endl;
}

