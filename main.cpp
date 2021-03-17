#include <QApplication>
#include <QPushButton>
#include <iostream>
#include "GameBoxWidget.h"

using namespace std;
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    GameBoxWidget* window = new GameBoxWidget(Board(12,16));
    window->show();
    return QApplication::exec();
}
