//
// Created by colors_wind on 2021/3/16.
//

#ifndef PELLETS_GRID_H
#define PELLETS_GRID_H

class Board;
class Pellet;

#include <QPainter>
#include <QGraphicsScene>
#include "Coordinate.h"
#include "Pellet.h"
#include "GridItem.h"

enum PelletResult;


class Grid {
public:
    virtual Location getLocation() const = 0;

    virtual void setLocation(Location location) = 0;

    virtual Location getCentre() const = 0;

    virtual int getIndexX() const = 0;

    virtual int getIndexY() const = 0;

    virtual void draw(QGraphicsScene *scene) = 0;

    virtual void remove(QGraphicsScene *scene) = 0;

    virtual void update(QGraphicsScene *scene) = 0;

    virtual void move(Vector vector) = 0;

    virtual bool isAlive() = 0;

    virtual PelletResult
    damageBy(Board *board, int damage, QGraphicsScene *scene, Pellet *pelletSource, Grid *gridSource) = 0;

    virtual ~Grid() = default;
};

class AbstractGrid : public Grid {
protected:
    Location location;
public:
    Location getLocation() const override;

    int getIndexX() const override;

    int getIndexY() const override;

    void move(Vector vector) override;

    explicit AbstractGrid(Location point);

    Location getCentre() const override;

    void setLocation(Location loc) override;

};

class AirGrid : public AbstractGrid {
public:
    explicit AirGrid(const Location &point);

    void draw(QGraphicsScene *scene) override;

    void remove(QGraphicsScene *scene) override;

    void update(QGraphicsScene *scene) override;

    bool isAlive() override;

    PelletResult
    damageBy(Board *board, int damage, QGraphicsScene *scene, Pellet *pelletSource, Grid *gridSource) override;


};

class HPGrid : public AbstractGrid {
protected:
    GridItem* gridItem = nullptr;
public:
    int health;

    void draw(QGraphicsScene *scene) override;

    void remove(QGraphicsScene *scene) override;

    void update(QGraphicsScene *scene) override;

    HPGrid(const Location &point, int health);

    virtual QColor getColor() const;

    virtual QString getLabel() const;

    bool isAlive() override;

    PelletResult
    damageBy(Board *board, int damage, QGraphicsScene *scene, Pellet *pelletSource, Grid *gridSource) override;

    virtual GridItem* initGridItem();
};


class RandomGrid : public HPGrid {

public:
    RandomGrid(const Location &point, int health);

    PelletResult
    damageBy(Board *board, int damage, QGraphicsScene *scene, Pellet *pelletSource, Grid *gridSource) override;

    GridItem *initGridItem() override;


    QString getLabel() const override;
};


class RewardGrid : public HPGrid {

public:
    RewardGrid(const Location &point, int health);


    PelletResult
    damageBy(Board *board, int damage, QGraphicsScene *scene, Pellet *pelletSource, Grid *gridSource) override;

    QColor getColor() const override;

    QString getLabel() const override;

    GridItem *initGridItem() override;

};

class AbsorbGrid : public HPGrid {
public:
    AbsorbGrid(const Location &point, int health);

    PelletResult
    damageBy(Board *board, int damage, QGraphicsScene *scene, Pellet *pelletSource, Grid *gridSource) override;

    QColor getColor() const override;

    QString getLabel() const override;
};

class ExplosiveGrid : public HPGrid {

protected:
    int power;
    int radius;
public:
    ExplosiveGrid(const Location &point, int health, int damage, int radius);

    PelletResult
    damageBy(Board *board, int damage, QGraphicsScene *scene, Pellet *pelletSource, Grid *gridSource) override;

    QColor getColor() const override;

    QString getLabel() const override;
};

#endif //PELLETS_GRID_H
