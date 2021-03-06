//
// Created by colors_wind on 2021/3/16.
//

#include "Grid.h"
#include "Backend.h"
#include <iostream>
#include <cmath>

void HPGrid::draw(QGraphicsScene *scene) {
    if (!isAlive())
        return;
    if (gridItem)
        return;
    gridItem = initGridItem();
    scene->addItem(gridItem);
}

void HPGrid::remove(QGraphicsScene *scene) {
    if (gridItem) {
        //gridItem->hide();
        scene->removeItem(gridItem);
        gridItem = nullptr;
    }
}

void HPGrid::update(QGraphicsScene *scene) {
    if (isAlive()) {
        //cout << "update\t" << gridItem << endl;
        gridItem->updateItem(location.getGridX(), location.getGridY(), 50, 50, getColor(), getLabel());
        gridItem->update();
    } else if (gridItem) remove(scene);
}


QColor HPGrid::getColor() const {
    if (health > 100) {
        return {250, 110, 45, 196};
    } else if (health > 50) {
        return {160, 65, 250, 196};
    } else if (health > 20) {
        return {255, 128, 128, 196};
    } else if (health > 10) {
        return {255, 255, 0, 196};
    } else if (health > 0) {
        return {120, 145, 200, 196};
    }
    return {0, 0, 0, 0};
}


HPGrid::HPGrid(const Location &point, int health) : AbstractGrid(point), health(health) {
}

bool HPGrid::isAlive() {
    return health > 0;
}


PelletResult HPGrid::damageBy(Board *board, int damage, QGraphicsScene *scene, Pellet *pelletSource, Grid *gridSource) {
    damage = min(this->health, damage);
    this->health -= damage;
    board->addScore(damage);
    this->remove(scene);
    board->highlight(this);
    return PelletResult::REFLECT;
}

GridItem *HPGrid::initGridItem() {
    return new GridItem(this,
                        getColor(),
                        getLabel());
}

QString HPGrid::getLabel() const {
    return QString::number(health);
}


