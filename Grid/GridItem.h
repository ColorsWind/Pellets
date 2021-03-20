//
// Created by colors_wind on 2021/3/17.
//

#ifndef PELLETS_GRIDITEM_H
#define PELLETS_GRIDITEM_H

#include <QGraphicsItem>
#include <QPainter>
#include "Grid.h"

class GridItem : public QGraphicsItem {
private:
    int left;
    int top;
    int width;
    int height;
    QColor color;
    QString label;
    QRect rect;
    Grid* grid;
public:
    GridItem(Grid* grid, int left, int top, int width, int height, const QColor &color,
             const QString &label, QGraphicsItem *parent = nullptr);

    QRectF boundingRect() const override;

    QPainterPath shape() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void updateItem(int left, int top, int width, int height, QColor color, QString label);

};


#endif //PELLETS_GRIDITEM_H
