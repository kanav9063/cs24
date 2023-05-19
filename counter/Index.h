#ifndef INDEX_H
#define INDEX_H
#include "DataStore.h"

#include <string>

// Index class
class Index {


private:
    static const int numBuckets = 251879;

    DataStore::node* table[numBuckets];

    int hashFunction(const std::string& key) const;

public:
    DataStore dataStore;

public:

    Index();

    void insert(const std::string& key, int value);

    void remove(const std::string& key);

    int get(const std::string& key) const;

    void update(const std::string& key, int newValue);
};

#endif
