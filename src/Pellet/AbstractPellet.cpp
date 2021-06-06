//
// Created by colors_wind on 2021/3/25.
//

#include "Pellet.h"
#include "Board.h"
#include "Constants.h"

AbstractPellet::AbstractPellet(const Location &location, const Vector &velocity) :
        location(location), velocity(velocity) {
}


void AbstractPellet::reflectY() {
    velocity.vectorX = -velocity.vectorX;

}

void AbstractPellet::reflectX() {
    velocity.vectorY = -velocity.vectorY;
}

void AbstractPellet::setVelocity(Vector vector) {
    velocity = vector;
}

void AbstractPellet::move(double interval) {
    location = location.add(velocity * interval);
}
#include <iostream>

using namespace std;
void AbstractPellet::draw(QGraphicsScene *scene) {
    update(scene);
}

void AbstractPellet::remove(QGraphicsScene *scene) {
    if (!pelletItem) return;
    scene->removeItem(pelletItem);
    pelletItem = nullptr;
}

void AbstractPellet::update(QGraphicsScene *scene) {
    if (pelletItem) {
        pelletItem->updateItem(location.pointX, location.pointY, Config::pellet_size, Config::pellet_size);
        pelletItem->update();
    } else {
        pelletItem = new PelletItem(location.pointX, location.pointY, double(Config::pellet_size), double(Config::pellet_size),
                                    getColor());
        scene->addItem(pelletItem);
    }

}

const PelletItem *AbstractPellet::getItem() const {
    return pelletItem;
}

Location AbstractPellet::getLocation() const {
    return location;
}

void AbstractPellet::setLocation(Location location) {
    this->location = location;
}

Location AbstractPellet::getCentre() const {
    return location.add({Config::pellet_size / 2.0, Config::pellet_size / 2.0});
}

Vector AbstractPellet::getVelocity() const {
    return velocity;
}

void AbstractPellet::handleHit(Board *board, Grid *grid) {
    hitCount++;
}

void AbstractPellet::leaveBoard() {
    hitCount = -1;
}

bool AbstractPellet::inBoard() {
    return hitCount >= 0;
}


