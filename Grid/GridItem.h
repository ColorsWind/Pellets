//
// Created by colors_wind on 2021/3/17.
//

#ifndef PELLETS_GRIDITEM_H
#define PELLETS_GRIDITEM_H

#include <QGraphicsItem>
#include <QPainter>
class GridItem : public QGraphicsItem {
private:
    int left;
    int top;
    int width;
    int height;
    QColor color;
    QString label;
    QRect rect;
public:
    GridItem(int left, int top, int width, int height, const QColor &color,
             const QString &label, QGraphicsItem *parent = nullptr);

    QRectF boundingRect() const override;

    QPainterPath shape() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};


#endif //PELLETS_GRIDITEM_H
