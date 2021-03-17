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
    double left;
    double top;
    double width;
    double height;
    QRectF rect;
public:
    PelletItem(int left, int top, int width, int height, QGraphicsItem *parent = nullptr);

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    QPainterPath shape() const override;
};


#endif //PELLETS_PELLETITEM_H
