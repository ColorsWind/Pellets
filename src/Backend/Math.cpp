//
// Created by colors_wind on 2021/6/2.
//

#include <Board.h>

int min(int x, int y) {
    if (x > y) return y;
    else return x;
}

int max(int x, int y) {
    if (x > y) return x;
    else return y;
}

int signOfComponent(double component) {
    return component > 0 ? 1 :
           (component == 0) ? 0 : -1;
}

int randomRound(Board *board, double d) {
    int n = (int)d;
    d -= n;
    if (board->nextDouble() < d)
        n++;
    return n;
}