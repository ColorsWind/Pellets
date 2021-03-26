//
// Created by colors_wind on 2021/3/17.
//

#ifndef PELLETS_SOLIDPELLET_H
#define PELLETS_SOLIDPELLET_H


#include <QPainter>
#include <QGraphicsScene>
#include "Pellet.h"
#include "../Location.h"
#include "PelletItem.h"
#include "AbstractPellet.h"

class SolidPellet : public AbstractPellet {
private:
    int damage;
public:
    SolidPellet(const Location &location, const Vector &velocity, int damage=1);

    PelletResult hit(Board *board, Grid *grid) override;


};


#endif //PELLETS_SOLIDPELLET_H
