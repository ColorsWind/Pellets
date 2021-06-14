//
// Created by colors_wind on 2021/3/17.
//

#ifndef PELLETS_GRIDITEM_H
#define PELLETS_GRIDITEM_H

class Grid;
#include <QGraphicsItem>
#include <QPainter>

/**
 * 负责 普通方块(方形) 的显示
 */
class GridItem : public QGraphicsItem {
protected:
    QColor color;
    QString label;
    Grid* grid;
    QRect rect;
public:
    GridItem(Grid* grid, QColor color,
             QString label, QGraphicsItem *parent = nullptr);


    virtual QRectF boundingRect() const override;

    virtual QPainterPath shape() const override;

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    virtual void updateItem(int left, int top, int width, int height, QColor qColor, QString qLabel);

};

/**
 * 负责 奖励方块(圆形) 的显示
 */
class RewardGridItem : public GridItem {
public:
    RewardGridItem(Grid* grid, const QColor &color,
                   const QString &label, QGraphicsItem *parent = nullptr);

    QRectF boundingRect() const override;

    QPainterPath shape() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif //PELLETS_GRIDITEM_H
