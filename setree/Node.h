#ifndef NODE_H
#define NODE_H

#include <string>

class Node {
  std::string mValue;
  Node* mLeft;
  Node* mRight;
  size_t mSize;

};

#endif