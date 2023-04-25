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

  stream >> row;
  if (!row_checker(toupper(row))) {   
    throw ParseError("Parse error.");
  }


  stream >> column;
  if (!column_checker(column)) {
    throw ParseError("Parse error.");
  }


  if (stream.peek() == '#' || isspace(stream.peek())) {
    if (stream.peek() == '#') {
      std::getline(stream, comment);
    } 
    else {
      stream >> std::ws;
      if (stream.peek() == '#') {
        std::getline(stream, comment);
      } 
      else {
        throw ParseError("Parse error.");
      }
    }
  }
   else {
    throw ParseError("Parse error.");
  }
}


std::ostream& operator << (std::ostream& stream, const Move& move) {
  stream << move.number << " "
         << static_cast<char>(toupper(move.player)) << " "
         << move.row << move.column;

  if (!move.comment.empty()) {
    stream << " # " << move.comment;
  }
  
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