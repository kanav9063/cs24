#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>

struct Move {
    int row;
    int col;
    char player;
};

class Board {
public:
    Board();

    void play(const Move& move);
    bool check_winner();
    char get(char r, int c);

private:
    char board_[3][3] = {{' ', ' ', ' '},
                         {' ', ' ', ' '},
                         {' ', ' ', ' '}};
};

#endif 