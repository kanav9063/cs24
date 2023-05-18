#include "Index.h"
#include <list>
#include <vector>
#include <string>

// Index Member Functions

Index::Index() : table(numBuckets) {}

// Insert a key-value pair into the hash table
void Index::insert(const std::string& key, int value) {
    int index = hashFunction(key);
    std::list<KeyValuePair>& bucket = table[index];

    // Check if the key already exists in the bucket
    for (auto& pair : bucket) {
        if (pair.key == key) {
            pair.value = value;
            return;
        }
    }

    // Key doesn't exist, add a new key-value pair
    KeyValuePair newPair;
    newPair.key = key;
    newPair.value = value;
    bucket.push_back(newPair);
}

// Remove a key-value pair from the hash table
void Index::remove(const std::string& key) {
    int index = hashFunction(key);
    std::list<KeyValuePair>& bucket = table[index];

    // Search for the key in the bucket
    for (auto it = bucket.begin(); it != bucket.end(); ++it) {
        if (it->key == key) {
            bucket.erase(it);
            return;
        }
    }
}

// Get the value associated with a key in the hash table
int Index::get(const std::string& key) {
    int index = hashFunction(key);
    std::list<KeyValuePair>& bucket = table[index];

    // Search for the key in the bucket
    for (const auto& pair : bucket) {
        if (pair.key == key) {
            return pair.value;
        }
    }

    // Key not found
    return -1;
}


// Update the value associated with a key in the hash table
void Index::update(const std::string& key, int newValue) {
    int index = hashFunction(key);
    std::list<KeyValuePair>& bucket = table[index];

    // Search for the key in the bucket
    for (auto& pair : bucket) {
        if (pair.key == key) {
            pair.value = newValue;
            return;
        }
    }

    // Key not found, insert a new key-value pair
    KeyValuePair newPair;
    newPair.key = key;
    newPair.value = newValue;
    bucket.push_back(newPair);
}