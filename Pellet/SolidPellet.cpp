//
// Created by colors_wind on 2021/3/17.
//

#include "SolidPellet.h"
#include "../Constants.h"

Vector SolidPellet::getVelocity() const {
    return velocity;
}

SolidPellet::SolidPellet(const Location &initial, const Vector &velocity) :
        location(initial), velocity(velocity),
        pelletItem(new PelletItem{initial.pointX, initial.pointY, double(Config::pellet_size), double(Config::pellet_size)}) {
}


Location SolidPellet::getLocation() const {
    return location;
}

void SolidPellet::setLocation(Location location) {
    this -> location = location;
}

void SolidPellet::move(double interval) {
    location = location.add(velocity * interval);
}

void SolidPellet::draw(QGraphicsScene *scene) {
    scene->addItem(pelletItem);
}

void SolidPellet::remove(QGraphicsScene *scene) {
    scene->removeItem(pelletItem);
}

void SolidPellet::update(QGraphicsScene *scene) {
    //remove(scene);
    pelletItem->updateItem(location.pointX, location.pointY, Config::pellet_size, Config::pellet_size);
    pelletItem->update();
}

void SolidPellet::reflectY() {
    velocity.vectorX = - velocity.vectorX;

}

void SolidPellet::reflectX() {
    velocity.vectorY = - velocity.vectorY;
}

void SolidPellet::fixLocationX(Location base) {
    if (velocity.vectorX > 0) {
        this->location.pointX = base.pointX + Config::grid_size + Config::pellet_size / 2;
    } else {
        this->location.pointX = base.pointX + Config::pellet_size / 2;
    }
    location.pointY = base.pointY + Config::grid_size / 2;
}

void SolidPellet::fixLocationY(Location base) {
    if (velocity.vectorY > 0) {
        this->location.pointY = base.pointY + Config::grid_size + Config::pellet_size / 2;
    } else {
        this->location.pointY = base.pointY + Config::pellet_size / 2;
    }
    location.pointX = base.pointX + Config::grid_size / 2;
}

const PelletItem *SolidPellet::getItem() const {
    return pelletItem;
}

Location SolidPellet::getCentre() const {
    return location.add({15,15});
}

