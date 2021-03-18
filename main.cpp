#include <QApplication>
#include <QPushButton>
#include <iostream>
#include "GameWidget.h"
#include "ui_GameBoxWidget.h"
#include "GameBoard.h"

using namespace std;
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    GameBoard gameBoard(12,16);
    GameWidget* window = new GameWidget(&gameBoard);
    //Ui_GameBoxWidget widget;
    //widget.setupUi(window);
    window->show();
    return QApplication::exec();
}
