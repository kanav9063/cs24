#ifndef DATASTORE_H
#define DATASTORE_H

#include <string>

class DataStore {
public:
  struct node {
    std::string key;
    int value;
    node* prev;
    node* next;
  };

private:
  node* head;
  node* tail;

public:
  DataStore();
  ~DataStore();

  node* insertNode(const std::string& key, int value);
  void deleteNode(node* targetNode);
  node* findNode(const std::string& key) const;
  node* getHead() const;
};

#endif