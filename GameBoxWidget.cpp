#include "GameBoxWidget.h"
#include "ui_GameBoxWidget.h"
#include "Pellet/SolidPellet.h"
#include "Grid/HPGrid.h"
#include <QPainter>
#include <QMouseEvent>
#include <QGraphicsView>
GameBoxWidget::GameBoxWidget(Board board, QWidget *parent) :
        QWidget(parent),
        gameboard(board), ui(new Ui::GameBoxWidget), scene(this) {
    ui->setupUi(this);
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(doTick()));
    timer->start(1000 / 30); // 30 fps

    auto grid = new HPGrid(Location{0,0}, 5);
    grid->draw(&scene);
    auto graphicsView = new QGraphicsView(this);
    graphicsView->setScene(&scene);
    graphicsView->setFixedSize(610,815);
    graphicsView->show();

}

GameBoxWidget::~GameBoxWidget() {
    delete ui;
}

void GameBoxWidget::drawGridlines(QGraphicsScene *scene) {
    for (int x = 1; x < gameboard.n; x++)
        scene->addLine(x * 50, 0, x * 50, 800);
    for (int y = 1; y < gameboard.m; y++)
        scene->addLine(0, y * 50, 600, y * 50);

}

void GameBoxWidget::drawGrids(QGraphicsScene *scene) {
    for (int x = 0; x < gameboard.m; x++)
        for (int y = 0; y < gameboard.n; y++)
            gameboard.at(x, y)->draw(scene);
}

void GameBoxWidget::drawPellets(QGraphicsScene *scene) {
    for (auto pellet : gameboard.existPellets)
        pellet->draw(scene);

}


void GameBoxWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    drawGridlines(&scene);
    drawGrids(&scene);
    drawPellets(&scene);
}

void GameBoxWidget::mousePressEvent(QMouseEvent *event) {
    //gameboard.nextRound();
    if (gameboard.numPellets > 0) {
        auto launch = getLaunchLocation();
        gameboard.existPellets.push_back(
                new SolidPellet(launch,
                                Vector(
                                        event->x() - launch.pointX,
                                        event->y() - launch.pointY
                                ).normalize(600.0)));
        gameboard.numPellets--;

    } else if (gameboard.existPellets.empty()) {
        gameboard.numPellets = 3;
        gameboard.nextRound();
    }
    update();
}

Location GameBoxWidget::getLaunchLocation() {
    return Location((gameboard.n - 1) * 50 / 2, (gameboard.m - 1) * 50);
}

void GameBoxWidget::doTick() {
    for (auto pellet : gameboard.existPellets) {
        pellet->move(1 / 30.0);

    }
    update();
}
