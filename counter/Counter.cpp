#include "Counter.h"

// Counter::Iterator Implementation
Counter::Iterator::Iterator(DataStore::node* node) : current(node) {}

const std::string& Counter::Iterator::key() const {
  return current->key;
}

int Counter::Iterator::value() const {
  return current->value;
}

Counter::Iterator& Counter::Iterator::operator++() {
  current = current->next;
  return *this;
}

bool Counter::Iterator::operator==(const Iterator& other) const {
  return current == other.current;
}

bool Counter::Iterator::operator!=(const Iterator& other) const {
  return !(*this == other);
}

// Counter Implementation
Counter::Counter() {}

Counter::~Counter() {}

size_t Counter::count() const {
  size_t counter = 0;
  DataStore::node* current = dataStore.getHead();
  while (current != nullptr) {
    ++counter;
    current = current->next;
  }
  return counter;
}

int Counter::total() const {
  int sum = 0;
  DataStore::node* current = dataStore.getHead();
  while (current != nullptr) {
    sum += current->value;
    current = current->next;
  }
  return sum;
}

void Counter::inc(const std::string& key, int by) {
  DataStore::node* existingNode = dataStore.findNode(key);
  if (existingNode) {
    existingNode->value += by;
  } else {
    dataStore.insertNode(key, by);
  }
}

void Counter::dec(const std::string& key, int by) {
  DataStore::node* existingNode = dataStore.findNode(key);
  if (existingNode!=nullptr) {
    existingNode->value -= by;
    } else {
      dataStore.insertNode(key, -by);
    }

    }

void Counter::del(const std::string& key) {
  DataStore::node* existingNode = dataStore.findNode(key);
  if (existingNode) {
    dataStore.deleteNode(existingNode);
  }
}

void Counter::set(const std::string& key, int count) {
  DataStore::node* existingNode = dataStore.findNode(key);
  if (existingNode) {
    existingNode->value = count;
  } else {
    dataStore.insertNode(key, count);
  }
}

int Counter::get(const std::string& key) const {
  DataStore::node* existingNode = dataStore.findNode(key);
  if (existingNode) {
    return existingNode->value;
  }
  return 0;
}

Counter::Iterator Counter::begin() const {
  return Iterator(dataStore.getHead());
}

Counter::Iterator Counter::end() const {
  return Iterator(nullptr);
}