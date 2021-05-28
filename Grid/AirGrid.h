//
// Created by colors_wind on 2021/3/17.
//

#ifndef PELLETS_AIRGRID_H
#define PELLETS_AIRGRID_H


#include "AbstractGrid.h"

class AirGrid : public AbstractGrid {
public:
    AirGrid(const Location &point);

    void draw(QGraphicsScene *scene) override;

    void remove(QGraphicsScene *scene) override;

    void update(QGraphicsScene *scene) override;

    bool isAlive() override;

    PelletResult hit(Board *board, int damage) override;



};


#endif //PELLETS_AIRGRID_H
