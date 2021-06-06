//
// Created by colors_wind on 2021/3/17.
//

#include "GridItem.h"
#include "Constants.h"
#include "Grid.h"
QRectF GridItem::boundingRect() const {
    return rect;
}

#include <iostream>
#include <utility>
using namespace std;
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

GridItem::GridItem(Grid *grid, QColor color,
                   QString label, QGraphicsItem *parent) : grid(grid), QGraphicsItem(parent),
                                                                  color(std::move(color)), label(std::move(label)),
                                                                  rect({grid->getLocation().getGridX(),
                                                                        grid->getLocation().getGridY(),
                                                                        Config::grid_size, Config::grid_size}) {
}


void GridItem::updateItem(int left, int top, int width, int height, QColor qColor, QString qLabel) {
    prepareGeometryChange();
    rect = {left, top, width, height};
    this->color = std::move(qColor);
    this->label = std::move(qLabel);


}


