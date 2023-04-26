#include "Board.h"
#include "Errors.h"
#include "Move.h"
#include <iostream>
#include <string>

int main() {
    Board board;
    std::string line;
    int move_number = 1;
    char current_player = 'X';


    while (std::getline(std::cin, line)) {
        try {
            Move move(line);

            if (move.row < 'A' || move.row > 'C' || move.column < 1 || move.column > 3) {
                throw std::invalid_argument("Invalid move.");
            }

            if (board.get(move.row - 'A', move.column - 1) != ' ') {
                throw std::invalid_argument("Invalid move.");
            } 

            board.play(move.row - 'A', move.column - 1, current_player);


            current_player = (current_player == 'X') ? 'O' : 'X';
            move_number++;
        
        } catch (const std::invalid_argument& e) {
            std::cerr << e.what() << std::endl;
            return 2;
        }
        
    }
            if (board.check_winner()) {
                std::cout << "Game over: " << current_player << " wins." << std::endl;
                return 0;
            }

            if (move_number == 9) {
                std::cout << "Game over: Draw." << std::endl;
                return 0;
            }

            if (current_player == 'X') {
                std::cout << "Game in progress: O's turn." << std::endl;
            } else {
                std::cout << "Game in progress: X's turn." << std::endl;
            }

    return 0;
}