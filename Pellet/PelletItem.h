//
// Created by colors_wind on 2021/3/17.
//

#ifndef PELLETS_PELLETITEM_H
#define PELLETS_PELLETITEM_H


#include <QGraphicsItem>
#include <QPainterPath>
#include <QRectF>
#include <QPainter>

class PelletItem : public QGraphicsItem {

private:
    QRectF rect;
    QColor color;
    double width, height, left, top;
public:


    PelletItem(double left, double top, double width, double height, QColor color, QGraphicsItem *parent= nullptr);

    void updateItem(double left, double top, double width, double height);

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    QPainterPath shape() const override;




};


#endif //PELLETS_PELLETITEM_H
