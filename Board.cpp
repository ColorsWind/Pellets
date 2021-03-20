//
// Created by colors_wind on 2021/3/16.
//

#include "Board.h"
#include "Grid/AirGrid.h"
#include "Grid/HPGrid.h"
#include <string>
#include <ctime>
#include <iostream>
#include "Constants.h"
Board::Board(int row, int col) : row(row), col(col), grids(new Grid **[row]) {
    for (int y = 0; y < row; y++) {
        this->grids[y] = new Grid *[col];
        for (int x = 0; x < col; x++)
            this->grids[y][x] = new AirGrid(Location(y * Config::grid_size, x * Config::grid_size));
    }
    srand(time(nullptr));
}

Grid *Board::at(int x, int y) const {
    if (x < 0 || x >= col || y < 0 || y >= row)
        std::cerr << "Out of bounds: Index: (" << x << ", " << y << ") Size: (" << row << ", " << col << ")." << std::endl;
    return grids[y][x];
}

Grid* Board::atOrNull(int x, int y) const noexcept {
    if (x < 0 || x >= col || y < 0 || y >= row)
        return nullptr;
    return grids[y][x];
}


Location Board::getLaunchLocation() const {
    return Location((col - 1) * Config::grid_size / 2, (row - 1) * Config::grid_size);
}

Pellet *Board::shoot() {
    auto launch = getLaunchLocation();
    auto pellet = new SolidPellet(launch, target.add(-launch.toVector()).toVector().normalize(Config::relative_velocity));
    existsPellets.push_back(
            pellet);
    return pellet;
}
