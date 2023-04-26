#include "Board.h"
#include "Errors.h"

Board::Board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board_[i][j] = ' ';
        }
    }
}

void Board::play(const Move& move) {
    int row = move.row - 'A';
    int col = move.col - 1;
    char player = move.player;
    board_[row][col] = player;
}

char Board::get(char r, int c) {
    return board_[r - 'A'][c - 1];
}

bool Board::check_winner() {
    const char board[3][3] = {{board_[0][0], board_[0][1], board_[0][2]},
                              {board_[1][0], board_[1][1], board_[1][2]},
                              {board_[2][0], board_[2][1], board_[2][2]}};

    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
    }

    for (int j = 0; j < 3; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return true;
        }
    }

    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }

    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }

    return false;
}