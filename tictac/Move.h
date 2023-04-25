#ifndef MOVE_H
#define MOVE_H

// This file defines a Move structure and some helper functions.
// You can edit it if you feel like it, but you shouldn't need to.
// You're free to interpret the member variables as you wish,
// but you must print moves in the expected format.

#include <ostream>
#include <string>

struct Move {
  // Member Variables
  int  number;
  char player;
  char  row;
  int  column;
  std::string comment;


  // The constructor parses a string.
  Move(const std::string& input);

  bool num_checker(char num);
  bool player_checker(char player);
  bool row_checker(char row); 
  bool column_checker(char column);


};

// Adding a << operator allows easy printing to std::cout.
// This should print the Move in the format described in the readme.
std::ostream& operator << (std::ostream& stream, const Move& move);

#endif
