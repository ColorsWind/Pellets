//
// Created by colors_wind on 2021/3/26.
//

#ifndef PELLETS_REWARDGRIDITEM_H
#define PELLETS_REWARDGRIDITEM_H


#include "GridItem.h"

class RewardGridItem : public GridItem {
public:
    RewardGridItem(Grid* grid, const QColor &color,
    const QString &label, QGraphicsItem *parent = nullptr);

    QRectF boundingRect() const override;

    QPainterPath shape() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};


#endif //PELLETS_REWARDGRIDITEM_H
