//
// Created by colors_wind on 2021/5/28.
//

#ifndef PELLETS_EXPLOSIVEGIRD_H
#define PELLETS_EXPLOSIVEGIRD_H

#include "HPGrid.h"

class ExplosiveGird : public HPGrid {

protected:
    int damage;
    int radius;
public:
    ExplosiveGird(const Location &point, int health, int damage, int radius);

    PelletResult hit(Board *board, int damage) override;

    QColor getColor() const override;
};


#endif //PELLETS_EXPLOSIVEGIRD_H
