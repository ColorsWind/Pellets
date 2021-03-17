//
// Created by colors_wind on 2021/3/16.
//

#include "Board.h"
#include "Grid/AirGrid.h"
#include "Grid/HPGrid.h"
#include <string>
#include <ctime>
#include <iostream>

Board::Board(int m, int n) : m(m), n(n), grids(new Grid **[m]) {
    for (int k = 0; k < m; k++) {
        this->grids[k] = new Grid *[n];
        for (int l = 0; l < n; l++)
            this->grids[k][l] = new AirGrid(Location(k * 50, l * 50));
    }
    srand(time(nullptr));
}

Grid *Board::at(int x, int y) const {
    if (x < 0 || x >= m || y < 0 || y >= n)
        std::cerr << "Out of bounds: Index: (" << x << ", " << y << ") Size: (" << m << ", " << n << ").";
    return grids[x][y];
}

void Board::nextRound() {
    round++;
    for (int k = 1; k < m; k++) {
        auto to = grids[k - 1];
        auto from = grids[k];
        for (int l = 0; l < n; l++) {
            delete to[l];
            to[l] = from[l]->move(from[l]->location().add(Vector{0, 50}));
        }
    }
    for (int l = 0; l < n; l++) {
        int random = rand() % 50;
        delete grids[m-1][l];
        if (random == 0 || random > 30) {
            grids[m-1][l] = new AirGrid(Location{ double(l * 50), 0.0});
        } else {
            grids[m-1][l] = new HPGrid(Location{double(l * 50), 0.0}, random);
        }
    }
}
