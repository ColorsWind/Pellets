//
// Created by colors_wind on 2021/3/17.
//

#ifndef PELLETS_GRIDITEM_H
#define PELLETS_GRIDITEM_H

#include <QGraphicsItem>
#include <QPainter>
#include "Grid.h"

class GridItem : public QGraphicsItem {
protected:
    int left;
    int top;
    int width;
    int height;
    QColor color;
    QString label;
    Grid* grid;
    QRect rect;
public:
    GridItem(Grid* grid, int left, int top, int width, int height, const QColor &color,
             const QString &label, QGraphicsItem *parent = nullptr);

    virtual QRectF boundingRect() const override;

    virtual QPainterPath shape() const override;

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    virtual void updateItem(int left, int top, int width, int height, QColor color, QString label);

};


#endif //PELLETS_GRIDITEM_H
