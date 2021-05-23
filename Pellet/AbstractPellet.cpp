//
// Created by colors_wind on 2021/3/25.
//

#include "AbstractPellet.h"
#include "../Board/Board.h"
#include "../Constants.h"

AbstractPellet::AbstractPellet(const Location &location, const Vector &velocity) :
        location(location), velocity(velocity), pelletItem(
        new PelletItem{location.pointX, location.pointY, double(Config::pellet_size), double(Config::pellet_size)}) {
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

void AbstractPellet::draw(QGraphicsScene *scene) {
    scene->addItem(pelletItem);
}

void AbstractPellet::remove(QGraphicsScene *scene) {
    scene->removeItem(pelletItem);
}

void AbstractPellet::update(QGraphicsScene *scene) {
    pelletItem->updateItem(location.pointX, location.pointY, Config::pellet_size, Config::pellet_size);
    pelletItem->update();
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
    return location.add({Config::grid_size / 2.0, Config::grid_size / 2.0});
}

void AbstractPellet::fixLocationX(Location base) {
    if (velocity.vectorX > 0) {
        this->location.pointX = base.pointX + Config::grid_size + Config::pellet_size / 2;
    } else {
        this->location.pointX = base.pointX + Config::pellet_size / 2;
    }
    location.pointY = base.pointY + Config::grid_size / 2;
}

void AbstractPellet::fixLocationY(Location base) {
    if (velocity.vectorY > 0) {
        this->location.pointY = base.pointY + Config::grid_size + Config::pellet_size / 2;
    } else {
        this->location.pointY = base.pointY + Config::pellet_size / 2;
    }
    location.pointX = base.pointX + Config::grid_size / 2;
}

Vector AbstractPellet::getVelocity() const {
    return velocity;
}

void AbstractPellet::handleHit(Board *board, Grid *grid) {
    hitCount++;
    board->addScore(1);
}

void AbstractPellet::leaveBoard() {
    hitCount = -1;
}

bool AbstractPellet::inBoard() {
    return hitCount >= 0;
}

