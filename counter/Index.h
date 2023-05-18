#ifndef INDEX_H
#define INDEX_H
#include "DataStore.h"

#include <string>

// Index class
class Index {


private:
    static const int numBuckets = 250031;

    DataStore::node* table[numBuckets];

    int hashFunction(const std::string& key) const;

public:
    DataStore dataStore;

public:

    Index();

    void insert(const std::string& key, int value);

    void remove(const std::string& key);

    int get(const std::string& key) const;

    // Update the value associated with a key in the hash table
    void update(const std::string& key, int newValue);
};

#endif
