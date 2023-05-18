#ifndef INDEX_H
#define INDEX_H

#include <unordered_map>
#include <string>
#include <vector>

class Index {
public:
    void addDocument(const std::vector<std::string>& words);
    std::vector<int> search(const std::string& word) const;

private:
    std::unordered_map<std::string, std::vector<int>> indexMap;
};

#endif