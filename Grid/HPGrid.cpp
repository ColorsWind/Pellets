//
// Created by colors_wind on 2021/3/16.
//

#include "HPGrid.h"
#include <iostream>
#include <cmath>

//using namespace std;
void HPGrid::draw(QGraphicsScene *scene) {
    if (!gridItem)
        gridItem = initGridItem();
    scene->addItem(gridItem);
}

void HPGrid::remove(QGraphicsScene *scene) {
    if (gridItem) {
        gridItem->hide();
        scene->removeItem(gridItem);
        gridItem = nullptr;
    }
}

void HPGrid::update(QGraphicsScene *scene) {
    if (isAlive()) {
        //cout << "update\t" << gridItem << endl;
        gridItem->updateItem(location.getGridX(), location.getGridY(), 50, 50, getColor(), QString::number(health));
        gridItem->update();
    } else if (gridItem) remove(scene);
}


QColor HPGrid::getColor() const {
    if (health > 20) {
        return {255, 128, 128, 196};
    } else if (health > 10) {
        return {255, 255, 0, 196};
    } else {
        return {120, 145, 200, 196};
    }
}



HPGrid::HPGrid(const Location &point, int health) : AbstractGrid(point), health(health) {

}

bool HPGrid::isAlive() {
    return health > 0;
}


PelletResult HPGrid::hit(Board *board, int damage) {
    health -= damage;
    return PelletResult::REFLECT;
}

GridItem *HPGrid::initGridItem() {
    return new GridItem(this,
                        getColor(),
                        QString::number(health));
}

