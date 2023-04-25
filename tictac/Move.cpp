#include "Move.h"
#include "Errors.h"
#include <sstream>
#include <cctype>
#include <iostream>

Move::Move(const std::string& input) {
  std::istringstream stream(input);

  std::string line;
  std::getline(stream >> std::ws, line);

  size_t i = line.find(" ", line.find(" ") + 1); 
  if (i != std::string::npos) {
    line.erase(i + 1);
  }

  stream.str(line); 

  stream >> number;
  if (!num_checker(number)) {
    throw ParseError("Parse error.");
  }

  stream >> player;
  if (!player_checker(toupper(player))) {
    throw ParseError("Parse error.");
  }

  stream >> row;
  if (!row_checker(toupper(row))) {   
    throw ParseError("Parse error.");
  }

  stream >> column;
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