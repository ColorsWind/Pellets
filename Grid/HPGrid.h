//
// Created by colors_wind on 2021/3/16.
//

#ifndef PELLETS_HPGRID_H
#define PELLETS_HPGRID_H


#include "AbstractGrid.h"
#include "GridItem.h"
#include "../Pellet/Pellet.h"
#include <QGraphicsScene>

class HPGrid : public AbstractGrid {
protected:
    GridItem* gridItem;
public:
    int health;

    void draw(QGraphicsScene *scene) override;

    void remove(QGraphicsScene *scene) override;

    void update(QGraphicsScene *scene) override;

    HPGrid(const Location &point, int health);
    virtual QColor getColor() const;

    bool colliding(Pellet *pellet) override;

    bool isAlive() override;

    PelletResult hit(int damage) override;

};


#endif //PELLETS_HPGRID_H
