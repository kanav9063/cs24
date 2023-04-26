#include "Board.h"
#include "Errors.h"

Board::Board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board_[i][j] = ' ';
        }
    }
}

void Board::play(char row, int col, char player) {
    int r = row - 'A';
    int c = col - 1;
    board_[r][c] = player;
}

char Board::get(char r, int c) {
    int r_num = r - 'A';
    // std::cout << r_num << "," << c << std::endl;
    return board_[r_num][c-1];
}

bool Board::check_winner() {;

    for (int i = 0; i < 3; i++) {
        if (board_[i][0] != ' ' && board_[i][0] == board_[i][1] && board_[i][1] == board_[i][2]) {
            return true;
        }
    }

    for (int j = 0; j < 3; j++) {
        if (board_[0][j] != ' ' && board_[0][j] == board_[1][j] && board_[1][j] == board_[2][j]) {
            return true;
        }
    }

    if (board_[0][0] != ' ' && board_[0][0] == board_[1][1] && board_[1][1] == board_[2][2]) {
        return true;
    }

    if (board_[0][2] != ' ' && board_[0][2] == board_[1][1] && board_[1][1] == board_[2][0]) {
        return true;
    }

    return false;
}