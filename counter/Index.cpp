#include "Index.h"

#include <cstring>

// Index Member Functions

Index::Index() {
    // Initialize the hash table buckets
    for (int i = 0; i < numBuckets; ++i) {
        table[i].key = "";
    }
}

// Hash function to map a key to an index
int Index::hashFunction(const std::string& key) {
    // Simple hash function
    return (key[0] - 'a') % numBuckets;
}

// Insert a key-value pair into the hash table
void Index::insert(const std::string& key, int value) {
    int index = hashFunction(key);

    // Check if the key already exists in the bucket
    if (table[index].key == key) {
        table[index].value = value;
        return;
    }

    // Key doesn't exist, add a new key-value pair
    table[index].key = key;
    table[index].value = value;
}

// Remove a key-value pair from the hash table
void Index::remove(const std::string& key) {
    int index = hashFunction(key);

    // Check if the key matches and remove the pair
    if (table[index].key == key) {
        table[index].key = "";
        return;
    }
}

// Get the value associated with a key in the hash table
int Index::get(const std::string& key) {
    int index = hashFunction(key);

    // Check if the key matches and return the value
    if (table[index].key == key) {
        return table[index].value;
    }

    // Key not found
    return -1;
}

// Update the value associated with a key in the hash table
void Index::update(const std::string& key, int newValue) {
    int index = hashFunction(key);

    // Check if the key matches and update the value
    if (table[index].key == key) {
        table[index].value = newValue;
        return;
    }

    // Key not found, insert a new key-value pair
    table[index].key = key;
    table[index].value = newValue;
}