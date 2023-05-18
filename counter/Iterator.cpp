#include "Counter.h"

// Counter::Iterator Member Functions

Counter::Iterator::Iterator(DataStore::node* node) : current(node), endNode(node) {}

const std::string& Counter::Iterator::key() const {
  return current->key;
}

int Counter::Iterator::value() const {
  return current->value;
}

Counter::Iterator& Counter::Iterator::operator++() {
  current = current->next;
  if (current == nullptr)
  {
    current=endNode;
  }  
  return *this;
}

bool Counter::Iterator::operator==(const Iterator& other) const {
  return current == other.current;
}

bool Counter::Iterator::operator!=(const Iterator& other) const {
  return !(*this == other);
}
