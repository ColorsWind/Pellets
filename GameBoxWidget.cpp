#include "GameBoxWidget.h"
#include "ui_GameBoxWidget.h"
#include "Point.h"
#include "Grid/HPGrid.h"
#include <QPainter>

GameBoxWidget::GameBoxWidget(Board board, QWidget *parent) :
        QWidget(parent),
        gameboard(board), ui(new Ui::GameBoxWidget) {
    ui->setupUi(this);
}

GameBoxWidget::~GameBoxWidget() {
    delete ui;
}

void GameBoxWidget::drawGridlines(QPainter *painter) {
    for(int x=1; x < gameboard.m - 1; x++)
        painter->drawLine(x * 50, 0, x * 50, 800);
    for(int y=1; y < gameboard.n - 1; y++)
        painter->drawLine(0, y * 50, 600, y * 50);
}

void GameBoxWidget::drawGrids(QPainter *painter) {
    for(int x=0; x< gameboard.m; x++)
        for (int y=0;y<gameboard.n; y++)
            gameboard.at(x, y)->draw(painter);
}

void GameBoxWidget::drawPellets(QPainter *painter) {
    for(auto iter=gameboard.pellets.cbegin();iter != gameboard.pellets.cend();iter++)
        (*iter)->draw(painter);
}


void GameBoxWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    drawGridlines(&painter);
    drawGrids(&painter);
    drawPellets(&painter);
}