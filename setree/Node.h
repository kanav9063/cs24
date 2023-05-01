#ifndef NODE_H
#define NODE_H

#include <string>

struct Node {
    std::string value;
    Node* left;
    Node* right;

    Node(const std::string& val = "") :
        value(val), left(nullptr), right(nullptr) {}
};

#endif