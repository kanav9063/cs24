#ifndef COUNTER_H
#define COUNTER_H

#include <cstddef>
#include <string>
#include "DataStore.h"

class Counter {
public:
  class Iterator {
  private:
    DataStore::node* current;
    DataStore::node* endNode;

  public:
    Iterator(DataStore::node* node);
    const std::string& key() const;
    int value() const;
    Iterator& operator++();
    bool operator==(const Iterator& other) const;
    bool operator!=(const Iterator& other) const;
  };

private:
  DataStore dataStore;

public:
  Counter();
  ~Counter();

  size_t count() const;
  int total() const;

  void inc(const std::string& key, int by = 1);
  void dec(const std::string& key, int by = 1);
  void del(const std::string& key);
  int get(const std::string& key) const;
  void set(const std::string& key, int count);

  Iterator begin() const;
  Iterator end() const;
};

#endif