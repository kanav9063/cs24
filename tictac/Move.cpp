#include "Move.h"
#include "Errors.h"
#include <sstream>
#include <cctype>
#include <iostream>

Move::Move(const std::string& input) {
  std::istringstream stream(input);

  stream >> number;
  std::cout<<(number)<<std::endl;
  if (!num_checker(number)) {
    throw ParseError("Parse error.");
  }

  stream >> player;
  std::cout<<(player)<<std::endl;
  if (!player_checker(toupper(player))) {
    throw ParseError("Parse error.");
  }

  stream >> row;
  std::cout<<(row)<<std::endl;
  if (!row_checker(toupper(row))) {   
    throw ParseError("Parse error.");
  }


  stream >> column;
  std::cout<<(column)<<std::endl;
  if (!column_checker(column)) {
    throw ParseError("Parse error.");
  }


  stream >> std::ws;


    if (stream.peek() == '#') {
        std::getline(stream, comment);
    }
}

std::ostream& operator << (std::ostream& stream, const Move& move) {
  stream << move.number << " "
         << static_cast<char>(toupper(move.player)) << " "
         << move.row << move.column;
  return stream;
}

bool Move::num_checker(int num) {
  return num >= 1 && num <= 9;
}

bool Move::player_checker(char player) {
  return player == 'X' || player == 'O';
}

bool Move::row_checker(char row) {
  return row == 'A' || row == 'B' || row == 'C';
}

bool Move::column_checker(int column) {
  return column >= 1 && column <= 3;
} 