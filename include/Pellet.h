//
// Created by colors_wind on 2021/3/15.
//

#ifndef PELLETS_PELLET_H
#define PELLETS_PELLET_H


#include "Coordinate.h"
#include "PelletItem.h"
#include "Grid.h"

class Grid;

class Board;

enum PelletResult {
    DISAPPEAR, REFLECT, TRANSFORM, NONE
};

/**
 * 弹球的最小化接口，刻画了弹球需要实现的方法。
 */
class Pellet {
public:
    virtual void draw(QGraphicsScene *scene) = 0;

    virtual void remove(QGraphicsScene *scene) = 0;

    virtual void update(QGraphicsScene *scene) = 0;

    virtual Location getLocation() const = 0;

    virtual void setLocation(Location location) = 0;

    virtual Location getCentre() const = 0;

    virtual Vector getVelocity() const = 0;

    virtual void setVelocity(Vector vector) = 0;

    virtual void reflectY() = 0;

    virtual void reflectX() = 0;

    virtual Pellet *transform(Board *board) = 0;

    virtual void move(double interval) = 0;

    virtual const PelletItem *getItem() const = 0;

    virtual PelletResult damageGrid(Board *board, Grid *grid, QGraphicsScene *scene) = 0;

    virtual void leaveBoard() = 0;

    virtual bool inBoard() = 0;

    virtual ~Pellet() = default;
};

/**
 * 弹球的抽象类，包含了弹球常用属性（位置，速度）的定义和相关方法的实现；还实现了 Qt 图形绘制的相关内容。
 */
class AbstractPellet : public Pellet {
protected:
    Location location;
    Vector velocity;
    PelletItem *pelletItem = nullptr;
    int hitCount = 0;

public:
    AbstractPellet(const Location &location, const Vector &velocity);

    Location getLocation() const override;

    Location getCentre() const override;

    void setLocation(Location location) override;

    void draw(QGraphicsScene *scene) override;

    void remove(QGraphicsScene *scene) override;

    void update(QGraphicsScene *scene) override;

    const PelletItem *getItem() const override;

    Vector getVelocity() const override;

    void move(double interval) override;

    void reflectY() override;

    void reflectX() override;

    void handleHit(Board *board, Grid *grid);

    void leaveBoard() override;

    bool inBoard() override;

    void setVelocity(Vector vector) override;

    virtual QColor getColor() const = 0 ;
    virtual QString getLabel() const = 0;

};

/**
 * 普通弹球。
 */
class SolidPellet : public AbstractPellet {
private:
    int damage;
public:
    SolidPellet(const Location &location, const Vector &velocity, int damage = 1);

    PelletResult damageGrid(Board *board, Grid *grid, QGraphicsScene *scene) override;

    Pellet *transform(Board *board) override;

    QColor getColor() const override;

    QString getLabel() const override;


};

/**
 * 随机弹球。
 */
class RandomPellet : public AbstractPellet {
protected:
    int minDamage;
    int maxDamage;
    int rollbackDamage;
public:
    RandomPellet(const Location &location, const Vector &velocity, int minDamage, int maxDamage,
                 int rollbackDamage = -1);

    PelletResult damageGrid(Board *board, Grid *grid, QGraphicsScene *scene) override;

    Pellet *transform(Board *board) override;

    QColor getColor() const override;

    QString getLabel() const override;


};

/**
 * 爆炸弹球。
 */
class ExplosivePellet : public AbstractPellet {
protected:
    double damage;
    double radius;
    int rollbackDamage;
public:
    ExplosivePellet(const Location &location, const Vector &velocity, double damage, double radius,
                    int rollbackDamage = -1);

    PelletResult damageGrid(Board *board, Grid *grid, QGraphicsScene *scene) override;

    Pellet *transform(Board *board) override;

    QColor getColor() const override;

    QString getLabel() const override;
};

#endif //PELLETS_PELLET_H
