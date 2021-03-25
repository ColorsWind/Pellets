//
// Created by colors_wind on 2021/3/16.
//

#include "HPGrid.h"
#include <iostream>
#include <cmath>
//using namespace std;
void HPGrid::draw(QGraphicsScene *scene) {
    if (gridItem) {
        //cout << "draw\t" << gridItem << endl;
        scene->addItem(gridItem);
    }
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


HPGrid::HPGrid(const Location &point, int health) : AbstractGrid(point), health(health), gridItem(
        new GridItem(this, point.getGridX(), point.getGridY(), 50, 50, getColor(), QString::number(health))) {
}

bool HPGrid::isAlive() {
    return health > 0;
}

using namespace std;
bool HPGrid::colliding(Pellet *pellet) {
    const Vector velocity = pellet->getVelocity();
    const Vector delta = Vector(this->getCentre(), pellet->getCentre());
    bool xColliding = signbit(delta.vectorX) == signbit(velocity.vectorX);
    bool yColliding = signbit(delta.vectorY) == signbit(velocity.vectorY);
    if (xColliding && yColliding) {
        cout << "xy" << endl;
        health--;
        pellet->reflectY();
        pellet->reflectX();
        //pellet->fixLocationX(location);
        //pellet->fixLocationY(location);
    } else if (xColliding) {
        cout << "x" << endl;
        health--;
        pellet->reflectX();
        //pellet->fixLocationY(location);
    } else if (yColliding) {
        cout << "y" << endl;
        health--;
        pellet->reflectY();
        //pellet->fixLocationX(location);
    } else {
        cout << "ERROR" << endl;
        return false;
    }

    return true;
}

PelletResult HPGrid::hit(int damage) {
    health -= damage;
    return PelletResult::REFLECT;
}
