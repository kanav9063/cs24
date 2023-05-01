#ifndef BOARD_H
#define BOARD_H

<<<<<<< HEAD
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
=======
#include "Move.h"

// I recommended writing a Board class to manage your game state.
// Here's some space for the class definition; member functions go in Board.cpp.

#endif
>>>>>>> fb542487be033608b6e629a0146d8006a0783671
