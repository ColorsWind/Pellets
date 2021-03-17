//
// Created by colors_wind on 2021/3/17.
//

#include "SolidPellet.h"


Vector SolidPellet::getVelocity() const {
    return velocity;
}

SolidPellet::SolidPellet(const Location &initial, const Vector &velocity) : location(initial), velocity(velocity) {}


Location SolidPellet::getLocation() const {
    return location;
}

void SolidPellet::move(double interval) {
    location = location.add(velocity * interval);
}

void SolidPellet::draw(QGraphicsScene *scene) {
    QRectF rect(location.pointX, location.pointY, 30, 30);
    //scene->addBrush(QBrush(QColor(250, 210, 20, 250), Qt::BrushStyle::SolidPattern));
    scene->addEllipse(rect);
}
