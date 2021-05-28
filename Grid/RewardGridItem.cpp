//
// Created by colors_wind on 2021/3/26.
//

#include "RewardGridItem.h"

RewardGridItem::RewardGridItem(Grid *grid, const QColor &color,
                               const QString &label, QGraphicsItem *parent) : GridItem(grid, color, label, parent) {
}

QRectF RewardGridItem::boundingRect() const {
    return GridItem::boundingRect();
}

QPainterPath RewardGridItem::shape() const {
    QPainterPath path;
    path.addEllipse(rect);
    return path;
}

void RewardGridItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush({color, Qt::BrushStyle::SolidPattern});
    painter->drawEllipse(rect);
    painter->drawText(rect, Qt::AlignCenter, label);
}
