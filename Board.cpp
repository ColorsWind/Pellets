//
// Created by colors_wind on 2021/3/16.
//

#include "Board.h"
#include "Grid/AirGrid.h"
#include <string>
#include <iostream>
Board::Board(int m, int n) : m(m), n(n), grids(new Grid **[m]) {
    for (int k = 0; k < m; k++) {
        this->grids[k] = new Grid *[n];
        for (int l = 0; l < n; l++)
            this->grids[k][l] = new AirGrid(Point(k*50, l*50));
    }
}

Grid *Board::at(int x, int y) const {
    if (x < 0 || x >= m || y < 0 || y >= n)
        std::cerr << "Out of bounds: Index: (" << x << ", " << y << ") Size: (" << m << ", " << n << ").";
    return grids[x][y];
}
