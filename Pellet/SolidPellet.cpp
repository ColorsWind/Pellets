//
// Created by colors_wind on 2021/3/17.
//

#include "SolidPellet.h"

Vector SolidPellet::getVelocity() const {
    return velocity;
}

SolidPellet::SolidPellet(const Location &initial, const Vector &velocity) :
        location(initial), velocity(velocity),
        pelletItem(new PelletItem{initial.pointX, initial.pointY, 30.0, 30.0}) {
}


Location SolidPellet::getLocation() const {
    return location;
}

void SolidPellet::move(double interval) {
    location = location.add(velocity * interval);
    pelletItem->left = location.pointX;
    pelletItem->top = location.pointY;
}

void SolidPellet::draw(QGraphicsScene *scene) {
    scene->addItem(pelletItem);
}

void SolidPellet::remove(QGraphicsScene *scene) {
    scene->removeItem(pelletItem);
}

void SolidPellet::update(QGraphicsScene *scene) {
    remove(scene);
    pelletItem->updateItem(location.pointX, location.pointY, 30.0, 30.0);
    draw(scene);
}

void SolidPellet::reflectY() {
    velocity.vectorX = - velocity.vectorX;

}

void SolidPellet::reflectX() {
    velocity.vectorY = - velocity.vectorY;
}

const PelletItem *SolidPellet::getItem() const {
    return pelletItem;
}
