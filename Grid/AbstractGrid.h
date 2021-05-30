//
// Created by colors_wind on 2021/3/16.
//

#ifndef PELLETS_ABSTRACTGRID_H
#define PELLETS_ABSTRACTGRID_H


#include "Grid.h"
#include "GridItem.h"

class AbstractGrid : public Grid {
protected:
    Location location;
public:
    Location getLocation() const override;

    void move(Vector vector) override;

    explicit AbstractGrid(const Location &point);

    Location getCentre() const override;

    void setLocation(Location location) override;



};

#endif //PELLETS_ABSTRACTGRID_H