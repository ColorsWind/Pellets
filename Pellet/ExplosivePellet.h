//
// Created by colors_wind on 2021/3/25.
//

#ifndef PELLETS_EXPLOSIVEPELLET_H
#define PELLETS_EXPLOSIVEPELLET_H


#include "AbstractPellet.h"

class ExplosivePellet : public AbstractPellet {
protected:
    int damage;
    int radius;
public:
    ExplosivePellet(const Location &location, const Vector &velocity, int damage, int radius);

    PelletResult hit(Board *board, Grid *grid) override;

    inline int max(int x, int y);

    inline int min(int x, int y);

    inline int square(int x);
};


#endif //PELLETS_EXPLOSIVEPELLET_H
