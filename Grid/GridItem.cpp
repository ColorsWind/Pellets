//
// Created by colors_wind on 2021/3/17.
//

#include "GridItem.h"

QRectF GridItem::boundingRect() const {
    return rect;
}

void GridItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(QBrush(color, Qt::BrushStyle::SolidPattern));
    painter->drawRect(rect);
    painter->drawText(rect, Qt::AlignCenter, label);
}

QPainterPath GridItem::shape() const {
    QPainterPath path;
    path.addRect(rect);
    return path;
}

GridItem::GridItem(Grid* grid, int left, int top, int width, int height, const QColor &color,
                   const QString &label, QGraphicsItem *parent) : grid(grid), QGraphicsItem(parent), left(left), top(top),
                                                                  width(width), height(height),
                                                                  color(color), label(label),
                                                                  rect(QRect(left, top, width, height)) {
}

void GridItem:: updateItem(int left, int top, int width, int height, QColor color, QString label) {
    rect = {left, top, width, height};
    this->color = color;
    this->label = label;
    prepareGeometryChange();
}

