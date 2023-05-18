#include "Counter.h"

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
  if (existingNode!=nullptr) {
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
  if (existingNode!=nullptr) {
    dataStore.deleteNode(existingNode);
  }
}

void Counter::set(const std::string& key, int count) {
  DataStore::node* existingNode = dataStore.findNode(key);
  if (existingNode!=nullptr) {
    existingNode->value = count;
  } else {
    dataStore.insertNode(key, count);
  }
}

int Counter::get(const std::string& key) const {
  DataStore::node* existingNode = dataStore.findNode(key);
  if (existingNode!=nullptr) {
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