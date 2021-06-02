//
// Created by colors_wind on 2021/3/17.
//

#include "PelletItem.h"
#include "Constants.h"
#include <iostream>
using namespace std;
PelletItem::PelletItem(double left, double top, double width, double height, QColor color, QGraphicsItem *parent)
        : left(left), top(left), width(width), height(height), color(color), QGraphicsItem(parent), rect(left, top, width, height) {
}


QRectF PelletItem::boundingRect() const {
    return {left - 2 * Config::relative_velocity,
            top - 2 * Config::relative_velocity,
            Config::pellet_size + 4 * Config::relative_velocity,
            Config::pellet_size + 4 * Config::relative_velocity};
}


void PelletItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(QBrush(color, Qt::BrushStyle::SolidPattern));
    painter->drawEllipse(rect);
    //painter->drawText(rect, Qt::AlignCenter, "L");
}

QPainterPath PelletItem::shape() const {
    QPainterPath path;
    path.addEllipse(rect);
    return path;
}


void PelletItem::updateItem(double left, double top, double width, double height) {
    prepareGeometryChange();
    this -> left = left;
    this -> top = top;
    this -> width = width;
    this -> height = height;
    rect = {left, top, width, height};


}


