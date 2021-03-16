#include "GameBoxWidget.h"
#include "ui_GameBoxWidget.h"
#include <QPainter>

GameBoxWidget::GameBoxWidget(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::GameBoxWidget) {
    ui->setupUi(this);
}

GameBoxWidget::~GameBoxWidget() {
    delete ui;
}

void QWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawLine(50, 50, 50, 600);

}