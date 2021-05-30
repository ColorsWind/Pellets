//
// Created by colors_wind on 2021/5/28.
//

#ifndef PELLETS_EXPLOSIVEGRID_H
#define PELLETS_EXPLOSIVEGRID_H

#include "HPGrid.h"

class ExplosiveGrid : public HPGrid {

protected:
    int damage;
    int radius;
public:
    ExplosiveGrid(const Location &point, int health, int damage, int radius);

    PelletResult hit(Board *board, int damage) override;

    QColor getColor() const override;

    QString getLabel() const override;
};


#endif //PELLETS_EXPLOSIVEGRID_H
