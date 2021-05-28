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
    GridItem* gridItem;
public:
    Location getLocation() const override;

    void move(Vector vector) override;

    AbstractGrid(const Location &point, GridItem* gridItem = nullptr);

    Location getCentre() const override;

    void setLocation(const Location location) override;

    virtual GridItem* initGridItem() = 0;
};

#endif //PELLETS_ABSTRACTGRID_H