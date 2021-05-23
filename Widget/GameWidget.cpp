#include "GameWidget.h"
#include "ui_GameWidget.h"
#include "../Constants.h"

GameWidget::GameWidget(GameBoard* gameBoard, QWidget *parent) :
    QWidget(parent), gameBoard(gameBoard),
    ui(new Ui::GameWidget)
{
    ui->setupUi(this);
    gameBoard->setup(this, ui->graphicsView);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(qDoTick()));
    timer->start(1000/ Config::fps);
}

GameWidget::~GameWidget()
{
    delete ui;
}

void GameWidget::mousePressEvent(QMouseEvent *event) {
    gameBoard->mouseEvent(event->x(), event->y());
}

void GameWidget::qDoTick() {
    gameBoard->doTick();
}

