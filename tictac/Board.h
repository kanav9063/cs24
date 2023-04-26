#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>

class Board {
public:
    Board();
    void play(char row, int col, char player);
    bool check_winner();
    char get(char r, int c);

    void print_board();

private:
    int row=0;
    int col=0;
    char player;

    char board_[3][3];
};

#endif