//
// Created by colors_wind on 2021/5/23.
//

#ifndef PELLETS_MAINWINDOW_H
#define PELLETS_MAINWINDOW_H

class GameWindow;
class RecordWindow;
struct Record;

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * 主窗体
 */
class MainWindow : public QWidget {
    Q_OBJECT

public slots:
    void startGame();
    void exitGame();
    void openRecord();
public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
    GameWindow *game;
    RecordWindow *record;


};



#endif //PELLETS_MAINWINDOW_H
