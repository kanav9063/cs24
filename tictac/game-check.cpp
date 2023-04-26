#include "Board.h"
#include "Errors.h"
#include "Move.h"
#include <iostream>
#include <string>

int main() {

    Board board;

    char current_player = 'N';
    int move_number = 1;


    while (true) {
        std::string line;
        if (!std::getline(std::cin, line)) {
            break;
        }

        try {

            Move move(line);

            if (board.get(move.row - 'A', move.column - 1) != ' ') {
                throw InvalidMove("Invalid move: space already occupied.");
            } 
                
            if (move.player == current_player) {
                 throw InvalidMove("Invalid move: same player entered twice in a row.");
                 }
            current_player = move.player;
            if (move_number != move.number) {
                throw InvalidMove("Invalid move: same move number entered twice.");
                }

            if (board.check_winner()) {
                throw InvalidMove("Invalid move: game already over.");
            }


            board.play(move.row - 'A', move.column - 1, current_player);
            move_number++;

        } catch (const InvalidMove& e) {
            std::cout << "Invalid move.\n" << std::endl;
            return 2;
        } catch (const ParseError& e) {
            std::cout << "Parse error.\n" << std::endl;
            return 1;
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
            if (move_number == 1) {
                std::cout << "Game in progress: New game." << std::endl;
                return 0;
            }

            if (current_player == 'X') {
                std::cout << "Game in progress: O's turn." << std::endl;
            } else {
                std::cout << "Game in progress: X's turn." << std::endl;
            }


    return 0;
}