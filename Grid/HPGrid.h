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
    int health;
    GridItem* gridItem;
    int mod = 0;
public:
    void draw(QGraphicsScene *scene) override;

    void remove(QGraphicsScene *scene) override;

    void update(QGraphicsScene *scene) override;

    HPGrid(const Location &point, int health);
    QColor getColor() const;

    bool colliding(Pellet *pellet) override;

    bool isAlive() override;

};


#endif //PELLETS_HPGRID_H
