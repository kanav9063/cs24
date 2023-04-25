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
            // Parse move
            Move move(line);

            // Check if the move is in bounds
            if (move.row < 'A' || move.row > 'C' || move.column < 1 || move.column > 3) {
                std::cerr << "Invalid move." << std::endl;
                return 2;
            }

            // Check if the cell is already occupied
            if (board.get(move.row, move.column) != ' ') {
                std::cerr << "Invalid move." << std::endl;
                return 2;
            }

            // Make move
            board.play(current_player, move.row, move.column);

            // Check for winner
            if (board.check_winner()) {
                std::cout << "Game over: " << current_player << " wins." << std::endl;
                return 0;
            }

            // Check for draw
            if (move_number == 9) {
                std::cout << "Game over: Draw." << std::endl;
                return 0;
            }

            // Switch players
            current_player = (current_player == 'X') ? 'O' : 'X';
            move_number++;

            // Print game status
            std::cout << "Game in progress: " << current_player << "'s turn." << std::endl;
        }
        catch (const ParseError& e) {
            std::cerr << "Parse error: " << e.what() << std::endl;
            return 1;
        }
    }

    // Game in progress
    std::cout << "Game in progress: " << current_player << "'s turn." << std::endl;
    return 0;
}