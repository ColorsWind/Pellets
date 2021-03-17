//
// Created by colors_wind on 2021/3/17.
//

#include "PelletItem.h"

PelletItem::PelletItem(int left, int top, int width, int height, QGraphicsItem *parent) : left(left), top(top), width(width), height(height), QGraphicsItem(parent), rect(left, top, width, height) {}

QRectF PelletItem::boundingRect() const {
    return rect;
}

void PelletItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(QBrush(QColor(250, 210, 20, 250), Qt::BrushStyle::SolidPattern));
    painter->drawEllipse(rect);
}

QPainterPath PelletItem::shape() const {
    QPainterPath path;
    path.addEllipse(QRect(top, left, width, height));
    return path;
}


