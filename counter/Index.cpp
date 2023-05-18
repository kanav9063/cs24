#include "Index.h"

void Index::addDocument(const std::vector<std::string>& words) {
    for (int i = 0; i < words.size(); i++) {
        const std::string& word = words[i];
        indexMap[word].push_back(i);
    }
}

std::vector<int> Index::search(const std::string& word) const {
    auto it = indexMap.find(word);
    if (it != indexMap.end()) {
        return it->second;
    }
    return std::vector<int>();
}