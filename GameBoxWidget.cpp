#include "GameBoxWidget.h"
#include "ui_GameBoxWidget.h"
#include "Pellet/SolidPellet.h"
#include <QPainter>
#include <QMouseEvent>

GameBoxWidget::GameBoxWidget(Board board, QWidget *parent) :
        QWidget(parent),
        gameboard(board), ui(new Ui::GameBoxWidget) {
    ui->setupUi(this);
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(doTick()));
    timer->start(1000 / 30); // 30 fps
}

GameBoxWidget::~GameBoxWidget() {
    delete ui;
}

void GameBoxWidget::drawGridlines(QPainter *painter) {
    for (int x = 1; x < gameboard.n; x++)
        painter->drawLine(x * 50, 0, x * 50, 800);
    for (int y = 1; y < gameboard.m; y++)
        painter->drawLine(0, y * 50, 600, y * 50);
}

void GameBoxWidget::drawGrids(QPainter *painter) {
    for (int x = 0; x < gameboard.m; x++)
        for (int y = 0; y < gameboard.n; y++)
            gameboard.at(x, y)->draw(painter);
}

void GameBoxWidget::drawPellets(QPainter *painter) {
    for (auto pellet : gameboard.pellets)
        pellet->draw(painter);

}


void GameBoxWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    drawGridlines(&painter);
    drawGrids(&painter);
    drawPellets(&painter);
}

void GameBoxWidget::mousePressEvent(QMouseEvent *event) {
    //gameboard.nextRound();
    if (gameboard.pellets.empty()) {
        auto launch = getLaunchLocation();
        gameboard.pellets.push_back(
                new SolidPellet(launch,
                Vector(
                        event->x() - launch.pointX,
                        event->y() - launch.pointY
                        ).normalize(600.0)));
    }
    update();
}

Location GameBoxWidget::getLaunchLocation() {
    return Location((gameboard.n - 1) * 50 / 2, (gameboard.m - 1) * 50);
}

void GameBoxWidget::doTick() {
    for (auto pellet : gameboard.pellets) {
        pellet->move(1 / 30.0);
    }
    update();
}
