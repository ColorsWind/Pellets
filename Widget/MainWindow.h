//
// Created by colors_wind on 2021/5/23.
//

#ifndef PELLETS_MAINWINDOW_H
#define PELLETS_MAINWINDOW_H

#include <QWidget>
#include "GameWindow.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget {
    Q_OBJECT

public slots:
    void start();
public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
    GameWindow *game;
};


#endif //PELLETS_MAINWINDOW_H
