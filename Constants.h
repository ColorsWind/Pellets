//
// Created by colors_wind on 2021/3/20.
//

#ifndef PELLETS_CONSTANTS_H
#define PELLETS_CONSTANTS_H

namespace Config {
    static int fps = 90;
    static int grid_size = 50;
    static int pellet_size = 18;
    static int board_row = 16;
    static int board_col = 12;
    static double absolute_velocity = grid_size * 12;
    static double relative_velocity = absolute_velocity / fps;
}

#endif //PELLETS_CONSTANTS_H
