#ifndef INDEX_H
#define INDEX_H

// Space to implement a separate index class, if you choose to do so.
// This can make things simpler by clearly separating functionality.
// The Index is in charge of getting pairs from the DataStore by key.


class Index {
private:
    // Define the structure for key-value pair
    struct KeyValuePair {
        std::string key;
        int value;
    };

    // Number of buckets in the hash table
    static const int numBuckets = 26;

    // Array of doubly linked lists (buckets)
    std::vector<std::list<KeyValuePair>> table;

    // Hash function to map a key to an index
    int hashFunction(const std::string& key) {}

public:
    Index() : table(numBuckets) {}

    // Insert a key-value pair into the hash table
    void insert(const std::string& key, int value) {}

    // Remove a key-value pair from the hash table
    void remove(const std::string& key) {}

    // Get the value associated with a key in the hash table
    int get(const std::string& key) {}
    
    // Update the value associated with a key in the hash table
    void update(const std::string& key, int newValue) {}
};

#endif
