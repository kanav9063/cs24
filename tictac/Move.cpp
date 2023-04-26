#include "Move.h"
#include "Errors.h"
#include <sstream>
#include <cctype>
#include <iostream>

Move::Move(const std::string& input) {
  if (input.size() == 0) { throw ParseError("Parse error."); }
  std::istringstream stream;
  stream.str(input);

  if (isspace(stream.peek())) { throw ParseError("Parse error."); }

  char num_c;
  stream >> num_c;
  
  if (!num_checker(num_c)) {
    throw ParseError("Parse error.");
  }
  number = num_c - '0';


  if (!isspace(stream.peek())) { throw ParseError("Parse error."); }

  stream >> player;
  player = toupper(player);
  if (!player_checker(toupper(player))) {
    throw ParseError("Parse error.");
  }


  if (!isspace(stream.peek())) { throw ParseError("Parse error."); }

  stream >> row;
  row = toupper(row);
  if (!row_checker(toupper(row))) {   
    throw ParseError("Parse error.");
  }

  if (isspace(stream.peek())) { throw ParseError("Parse error."); }

  char col_c;
  stream >> col_c;
  col_c = toupper(col_c);
  if (!column_checker(col_c)) {
    throw ParseError("Parse error.");
  }
  column = col_c - '0';
  
  
  std::string rest;
  getline(stream, rest);
  // std::cout << rest << std::endl;

  if (rest.size() > 0 && !isspace(rest[0])) {
      throw ParseError("Parse error.");
  }

  for (size_t i = 0; i < rest.size(); i++) {
    if (rest[i] == '#') break;
    if (!isspace(rest[i])) {
      throw ParseError("Parse error.");
    }
  }
}

std::ostream& operator << (std::ostream& stream, const Move& move) {
  stream << move.number << " "
         << (char)(toupper(move.player)) << " "
         << move.row << move.column;
  return stream;
}

bool Move::num_checker(char num) {
  return num >= '1' && num <= '9';
}

bool Move::player_checker(char player) {
  return player == 'X' || player == 'O';
}

bool Move::row_checker(char row) {
  return row == 'A' || row == 'B' || row == 'C';
}

bool Move::column_checker(char column) {
  return column >= '1' && column <= '3';
} 