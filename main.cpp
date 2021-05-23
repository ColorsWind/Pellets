#include <QApplication>
#include <QPushButton>
#include <iostream>
#include "Widget/GameWidget.h"
#include "Widget/MainWindow.h"

using namespace std;
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow window(nullptr);
    window.show();
    return QApplication::exec();
}
