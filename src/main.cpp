#include <QApplication>
#include <QTextCodec>
#include "Widget/MainWindow.h"

int main(int argc, char *argv[]) {
    qunsetenv("QT_DEVICE_PIXEL_RATIO");
    qputenv("QT_SCALE_FACTOR", "2.0");
    QApplication a(argc, argv);
    MainWindow window(nullptr);
    window.show();
    return QApplication::exec();
}


