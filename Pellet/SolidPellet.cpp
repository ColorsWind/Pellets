//
// Created by colors_wind on 2021/3/17.
//

#include "SolidPellet.h"

Point SolidPellet::getLocation() const {
    return location;
}

void SolidPellet::draw(QPainter *painter) {
    QRectF rect(location.pointX, location.pointY, 50, 50);
    painter->setBrush(QBrush(QColor(250,210,20, 250), Qt::BrushStyle::SolidPattern));
    painter->drawEllipse(rect);
}

Vector SolidPellet::getVelocity() const {
    return velocity;
}

SolidPellet::SolidPellet(const Point &initial, const Vector &velocity) : location(initial), velocity(velocity) {}
