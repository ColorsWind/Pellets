//
// Created by colors_wind on 2021/3/26.
//

#ifndef PELLETS_RANDOMPELLET_H
#define PELLETS_RANDOMPELLET_H


#include <random>
#include "AbstractPellet.h"

class RandomPellet : public AbstractPellet {
protected:
    int minDamage;
    int maxDamage;
public:
    RandomPellet(const Location &location, const Vector &velocity,
                 int minDamage, int maxDamage);
    PelletResult hit(Board *board, Grid *grid) override;


};


#endif //PELLETS_RANDOMPELLET_H
