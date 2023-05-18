#ifndef INDEX_H
#define INDEX_H
#include "DataStore.h"

#include <string>

// Index class
class Index {


private:

    

    // Number of buckets in the hash table
    static const int numBuckets = 250031;

    // Array of key-value pairs (buckets)
    DataStore::node* table[numBuckets];

    // Hash function to map a key to an index
    int hashFunction(const std::string& key) const;

public:
    DataStore dataStore;

public:
    // Constructor
    Index();

    // Insert a key-value pair into the hash table
    void insert(const std::string& key, int value);

    // Remove a key-value pair from the hash table
    void remove(const std::string& key);

    // Get the value associated with a key in the hash table
    int get(const std::string& key) const;

    // Update the value associated with a key in the hash table
    void update(const std::string& key, int newValue);
};

#endif
