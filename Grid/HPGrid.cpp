//
// Created by colors_wind on 2021/3/16.
//

#include "HPGrid.h"
#include "GridItem.h"

void HPGrid::draw(QGraphicsScene *scene) {
    QRect rect(point.getGridX(), point.getGridY(), 50, 50);
    QColor color;
    if (health > 20) {
        color = QColor(255, 128, 128, 196);
    } else if (health > 10) {
        color = QColor(255, 255, 0, 196);
    } else {
        color = QColor(120, 145, 200, 196);
    }
    scene->addItem(new GridItem(point.getGridX(), point.getGridY(), 50, 50, color, QString::number(health)));
}

HPGrid::HPGrid(const Location &point, int health) : FixedGrid(point), health(health) {}

Grid *HPGrid::move(Location point) {
    return new HPGrid(point, health);
}
