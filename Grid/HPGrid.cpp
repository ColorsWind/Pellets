//
// Created by colors_wind on 2021/3/16.
//

#include "HPGrid.h"
#include <iostream>
//using namespace std;
void HPGrid::draw(QGraphicsScene *scene) {
    if (gridItem) {
        //cout << "draw\t" << gridItem << endl;
        scene->addItem(gridItem);
    }
}

void HPGrid::remove(QGraphicsScene *scene) {
    if (gridItem) {
        //mod++;
        //cout << "remove\t" << gridItem << "\t" <<  mod << endl;
        scene->removeItem(gridItem);
        //delete gridItem;
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


HPGrid::HPGrid(const Location &point, int health) : AbstractGrid(point), health(health), gridItem(
        new GridItem(this, point.getGridX(), point.getGridY(), 50, 50, getColor(), QString::number(health))) {
}

bool HPGrid::isAlive() {
    return health > 0;
}

bool HPGrid::colliding(Pellet *pellet) {
    const Vector velocity = pellet->getVelocity();
    const Vector delta = Vector(pellet->getCentre(), this -> getCentre());
    bool xColliding = signbit(delta.vectorX) == signbit(velocity.vectorX);
    bool yColliding = signbit(delta.vectorY) == signbit(velocity.vectorY);
    if (xColliding && yColliding) {
        health--;
        if (abs(delta.vectorX) < abs(delta.vectorY)) pellet->reflectX();
        else pellet->reflectY();
    } else if (xColliding) {
        health--;
        pellet->reflectX();
    } else if (yColliding) {
        health--;
        pellet->reflectY();
    } else return false;
    return true;
}

