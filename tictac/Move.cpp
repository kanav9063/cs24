#include "Move.h"
#include "Errors.h"
#include <sstream>
#include <cctype>

Move::Move(const std::string& input) {
  std::istringstream stream(input);

  stream >> number;
  if (!num_checker(number)) {
    throw ParseError("Parse error.");
  }
  
  stream >> player;
  if (!player_checker(toupper(player))) {
    throw ParseError("Parse error.");
  }

  

  char square_letter;
  stream >> square_letter;
  square_letter = toupper(square_letter); 
  if (square_letter < 'A' || square_letter > 'C') {
    throw ParseError("Parse error.");
  }
  row = square_letter - 'A'; 

  int square_digit;
  stream >> square_digit;
  if (!column_checker(square_digit)) {
    throw ParseError("Parse error.");
  }
  column = square_digit - 1; 

  std::string extra;
  stream >> extra;
  if (!extra.empty()) {
    throw ParseError("Parse error.");
  }
}

std::ostream& operator << (std::ostream& stream, const Move& move) {
  stream << move.number << " "
         << static_cast<char>(toupper(move.player)) << " "
         << static_cast<char>(move.row + 'A') << static_cast<char>(move.column + '1');
  return stream;
}

bool Move::num_checker(int num) {
  return num >= 1 && num <= 9;
}

bool Move::player_checker(char player) {
  return player == 'X' || player == 'O';
}

bool Move::row_checker(int row) {
  return row >= 0 && row <= 2;
}

bool Move::column_checker(int column) {
  return column >= 1 && column <= 3;
}