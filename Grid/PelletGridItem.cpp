//
// Created by colors_wind on 2021/3/26.
//

#include "PelletGridItem.h"

PelletGridItem::PelletGridItem(Grid *grid, int left, int top, int width, int height, const QColor &color,
                               const QString &label, QGraphicsItem *parent) : GridItem(grid, left, top, width, height,
                                                                                       color, label, parent) {
}

QRectF PelletGridItem::boundingRect() const {
    return GridItem::boundingRect();
}

QPainterPath PelletGridItem::shape() const {
    QPainterPath path;
    path.addEllipse(rect);
    return path;
}

void PelletGridItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush({color, Qt::BrushStyle::SolidPattern});
    painter->drawEllipse(rect);
    painter->drawText(rect, Qt::AlignCenter, label);
}
