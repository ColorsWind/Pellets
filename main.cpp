#include <QApplication>
#include <QPushButton>
#include <iostream>
#include "GameWidget.h"

using namespace std;
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    GameBoard gameBoard(16,12);
    GameWidget* window = new GameWidget(&gameBoard);
    //Ui_GameBoxWidget widget;
    //widget.setupUi(window);
    window->show();
    return QApplication::exec();
}
