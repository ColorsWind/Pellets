//
// Created by colors_wind on 2021/3/26.
//

#ifndef PELLETS_ABSORBGRID_H
#define PELLETS_ABSORBGRID_H


#include "HPGrid.h"

class AbsorbGrid : public HPGrid {
public:
    AbsorbGrid(const Location &point, int health);

    PelletResult hit(Board *board, int damage) override;

    QColor getColor() const override;

    QString getLabel() const override;
};


#endif //PELLETS_ABSORBGRID_H
