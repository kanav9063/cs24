#include "Index.h"
#include <cstring>
#include <iostream>

Index::Index() {
    for (int i = 0; i < numBuckets; ++i) {
        table[i] = nullptr; // Initialize the buckets with nullptr
    }
}

// Hash function to map a key to an index
int Index::hashFunction(const std::string& key) const {
    int val = 5147;
    for (size_t i = 0; i < key.size(); ++i) {
        val = val * 31 + key[i];
        val = val % numBuckets;
    }
    return val % numBuckets;
}


// Remove a key-value pair from the hash table
void Index::remove(const std::string& key) {
    int index = hashFunction(key);

    // Check if the key matches and remove the pair
    if (table[index] != nullptr &&  table[index] !=(DataStore::node*)1 && table[index]->key == key) {
            dataStore.deleteNode( table[index]);
            table[index] = (DataStore::node*)1;
            return;
    }

    // Collision occurred, perform linear probing to find the key
    int probeIndex = (index + 1) % numBuckets;
    while (probeIndex != index) {
        if (table[probeIndex] != nullptr && table[probeIndex] !=(DataStore::node*)1 && table[probeIndex]->key == key) {
            // Found the key, remove the pair
            dataStore.deleteNode( table[probeIndex]);
            table[probeIndex] = (DataStore::node*)1;
            return;
        }
        probeIndex = (probeIndex + 1) % numBuckets; // Move to the next slot
    }

    // Key not found
}

// Get the value associated with a key in the hash table
int Index::get(const std::string& key) const {
    int index = hashFunction(key);

    // Check if the key matches and return the value
    if (table[index] != nullptr  &&  table[index] !=(DataStore::node*)1 && table[index]->key == key) {
        return table[index]->value;
    }

    // Collision occurred, perform linear probing to find the key
    int probeIndex = (index + 1) % numBuckets;
    while (table[probeIndex] != nullptr) {
        if (table[probeIndex] != (DataStore::node*)1 && table[probeIndex]->key == key) {
            // Found the key, return the value
            return table[probeIndex]->value;
        }
        probeIndex = (probeIndex + 1) % numBuckets; // Move to the next slot
    }

    // Key not found
    return 0;
}
void Index::update(const std::string& key, int newValue) {
    int index = hashFunction(key);
    int firstDirty = -1;
    bool dirtyFound = false;

    if (table[index] != nullptr && table[index] != (DataStore::node*)1 && table[index]->key == key) {
        table[index]->value = newValue;
        return;
    }
    if (table[index] == nullptr) {
        table[index] = dataStore.insertNode(key, newValue);
        return;
    }

    if (table[index] == (DataStore::node*)1) {
        firstDirty = index;
        dirtyFound = true;
    }

    int probeIndex = (index + 1) % numBuckets;
    while (probeIndex != index) {
        if (!dirtyFound && table[probeIndex] == (DataStore::node*)1) {
            firstDirty = probeIndex;
            dirtyFound = true;
        }
        if (table[probeIndex] == nullptr) {
            if (dirtyFound) {
                probeIndex = firstDirty;
            }
            table[probeIndex] = dataStore.insertNode(key, newValue);
            return;
        } else if (table[probeIndex] != (DataStore::node*)1 && table[probeIndex]->key == key) {
            table[probeIndex]->value = newValue;
            return;
        }
        probeIndex = (probeIndex + 1) % numBuckets; 
    }

}