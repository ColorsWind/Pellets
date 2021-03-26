//
// Created by colors_wind on 2021/3/16.
//

#include "Board.h"
#include "../Grid/AirGrid.h"
#include <ctime>
#include <iostream>
#include "../Constants.h"

Board::Board(int row, int col) :
        row(row),
        col(col),
        grids(new Grid **[row]),
        launchLocation({(col - 1) * Config::grid_size / 2.0, row * (double) Config::grid_size - Config::grid_size / 4}),
        targetLocation({0.0, 0.0}),
        randomEngine(std::mt19937{std::random_device()()}),
        doubleGenerator(std::uniform_real_distribution<double>{0.0, 1.0})
{
    for (int y = 0; y < row; y++) {
        this->grids[y] = new Grid *[col];
        for (int x = 0; x < col; x++)
            this->grids[y][x] = new AirGrid(Location(y * Config::grid_size, x * Config::grid_size));
    }
}

Grid *Board::at(int x, int y) const {
    if (x < 0 || x >= col || y < 0 || y >= row)
        std::cerr << "Out of bounds: Index: (" << x << ", " << y << ") Size: (" << row << ", " << col << ")."
                  << std::endl;
    return grids[y][x];
}

Grid *Board::atOrNull(int x, int y) const noexcept {
    if (x < 0 || x >= col || y < 0 || y >= row)
        return nullptr;
    return grids[y][x];
}


Pellet *Board::shoot() {
    auto pellet = new SolidPellet(launchLocation, targetLocation.add(-launchLocation.toVector()).toVector().normalize(
            Config::relative_velocity));
    existsPellets.push_back(pellet);
    return pellet;
}
