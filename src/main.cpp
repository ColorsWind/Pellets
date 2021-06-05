#include <QApplication>
#include <QPushButton>
#include "Widget/MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow window(nullptr);
    window.show();
    return QApplication::exec();
}