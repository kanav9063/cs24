#include "Move.h"
#include "Errors.h"
#include <sstream>
#include <cctype>
#include <iostream>

Move::Move(const std::string& input) {
  std::istringstream stream(input);

  if (isspace(stream.peek())) { throw ParseError("Parse error."); }

  stream >> number;
  if (!num_checker(number)) {
    throw ParseError("Parse error.");
  }

  if (!isspace(stream.peek())) { throw ParseError("Parse error."); }

  stream >> player;
  if (!player_checker(toupper(player))) {
    throw ParseError("Parse error.");
  }

  if (!isspace(stream.peek())) { throw ParseError("Parse error."); }

  stream >> row;
  if (!row_checker(toupper(row))) {   
    throw ParseError("Parse error.");
  }

  stream >> column;
  if (!column_checker(column)) {
    throw ParseError("Parse error.");
  }
  
  std::string rest;
  getline(stream, rest);

  if (rest.size() > 0 && !isspace(rest[0])) {
      throw ParseError("Parse error.");
  }

  for (size_t i = 0; i < rest.size(); i++) {
    if (rest[i] == '#') break;
    if (!isspace(rest[i])) {
      throw ParseError("Parse error.");
    }
  }

  if (stream.peek() == '#') {
        std::getline(stream, comment);
    }

  stream >> std::ws;


    if (stream.peek() == '#') {
        std::getline(stream, comment);
    }
}

std::ostream& operator << (std::ostream& stream, const Move& move) {
  stream << move.number << " "
         << (char)(toupper(move.player)) << " "
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