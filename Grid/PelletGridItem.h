//
// Created by colors_wind on 2021/3/26.
//

#ifndef PELLETS_PELLETGRIDITEM_H
#define PELLETS_PELLETGRIDITEM_H


#include "GridItem.h"

class PelletGridItem : public GridItem {
public:
    PelletGridItem(Grid* grid, int left, int top, int width, int height, const QColor &color,
    const QString &label, QGraphicsItem *parent = nullptr);

    QRectF boundingRect() const override;

    QPainterPath shape() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};


#endif //PELLETS_PELLETGRIDITEM_H
