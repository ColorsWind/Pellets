#include <QApplication>
#include <QTextCodec>
#include <QDesktopWidget>
#include "Widget/MainWindow.h"

#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")

int main(int argc, char *argv[]) {

    qunsetenv("QT_DEVICE_PIXEL_RATIO");
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling, true);
    //QRect deskRect = QApplication::desktop()->availableGeometry();
    //qputenv("QT_SCALE_FACTOR", "2.0");
    QApplication a(argc, argv);
    MainWindow window(nullptr);
    window.show();
    return QApplication::exec();
}


