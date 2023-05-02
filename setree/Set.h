#ifndef SET_H
#define SET_H

#include <cstddef>
#include <string>
#include "Node.h"

// This is the Set class you need to implement.
// Do not edit this file.

class Set {
  Node* mRoot;

public:
  Set();
  Set(const Set& other);
  Set(Set&& other);
  ~Set();

  size_t clear();
  bool contains(const std::string& value) const;
  size_t count() const;
  void debug();
  size_t insert(const std::string& value);
  const std::string& lookup(size_t n) const;
  void print() const;
  size_t remove(const std::string& value);
};

#endif

