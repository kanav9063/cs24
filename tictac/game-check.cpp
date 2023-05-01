#include "Board.h"
#include "Errors.h"
#include "Move.h"
<<<<<<< HEAD
#include <iostream>
#include <string>

int main() {

    Board board;

    char current_player = 'N';
    int move_number = 1;


    std::string line;
    while (std::getline(std::cin, line)) {
        try {

            Move move(line);

            if (board.check_winner()) {
                // std::cout <<"a" <<std::endl;
                throw InvalidMove("Invalid move: game already over.");
            }

            if (board.get(move.row, move.column) != ' ') {
                // std::cout << board.get(move.row - 'A', move.column - 1) << std::endl;
                throw InvalidMove("Invalid move: space already occupied.");
            } 
                
            if (move.player == current_player) {
                // std::cout <<"c" <<std::endl;
                 throw InvalidMove("Invalid move: same player entered twice in a row.");
                 }
            current_player = move.player;
            if (move_number != move.number) {
                // std::cout <<"d" <<std::endl;
                throw InvalidMove("Invalid move: same move number entered twice.");
                }

            // std::cout << "player: " << current_player << std::endl;
            
            board.play(move.row, move.column, current_player);
            move_number++;
            

        } catch (const InvalidMove& e) {
            std::cout << "Invalid move.\n";
            return 2;
        } catch (const ParseError& e) {
            std::cout << "Parse error.\n";
            return 1;
        }
    }

            if (board.check_winner()) {
                std::cout << "Game over: " << current_player << " wins." << std::endl;
                return 0;
            }
            if (move_number == 10) {
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
=======

int main() {

}
>>>>>>> fb542487be033608b6e629a0146d8006a0783671
