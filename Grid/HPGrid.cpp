//
// Created by colors_wind on 2021/3/16.
//

#include "HPGrid.h"
void HPGrid::draw(QPainter* painter) {
    QRect rect(point.getGridX(), point.getGridY(), 50, 50);
    if (health > 20) {
        painter->setBrush(QBrush(QColor(255,128,128, 196), Qt::BrushStyle::SolidPattern));
    } else if (health > 10) {
        painter->setBrush(QBrush(QColor(255,255,0, 196), Qt::BrushStyle::SolidPattern));
    } else {
        painter->setBrush(QBrush(QColor(120,145,200, 196), Qt::BrushStyle::SolidPattern));
    }
    painter->drawRect(rect);
    painter->drawText(rect, Qt::AlignCenter, QString::number(health));
}

HPGrid::HPGrid(const Point &point, int health) : FixedGrid(point), health(health) {}
