//
// Created by colors_wind on 2021/3/17.
//

#include "GridItem.h"
#include "../Constants.h"

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

GridItem::GridItem(Grid *grid, const QColor &color,
                   const QString &label, QGraphicsItem *parent) : grid(grid), QGraphicsItem(parent),
                                                                  color(color), label(label),
                                                                  rect({grid->getLocation().getGridX(),
                                                                        grid->getLocation().getGridY(),
                                                                        Config::grid_size, Config::grid_size}) {
}


void GridItem::updateItem(int left, int top, int width, int height, QColor color, QString label) {
    rect = {left, top, width, height};
    this->color = color;
    this->label = label;
    prepareGeometryChange();
}


