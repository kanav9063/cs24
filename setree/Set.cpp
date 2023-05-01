#include "Set.h"


Set::Set() {
    mRoot=nullptr;
}
Node* copy(const Node* otherNode) {
    if (otherNode == nullptr) {
        return nullptr;
    }
    Node* newNode = new Node(otherNode->value);

    newNode->left = copy(otherNode->left);
    newNode->right = copy(otherNode->right);
    return newNode;
}

Set::Set(const Set& other) {
    mRoot = copy(other.mRoot);
}
Set::Set(Set&& other) {

}

Set::~Set() {
    clear();
}

size_t Set::clear() {
    return 1;
}

bool Set::contains(const std::string& value) const {
    return false;
}

size_t Set::count() const {
    return 1;
}

void Set::debug() {}


size_t insertHelper(Node*& root, const std::string& value) {
    if (root == nullptr) {
        root = new Node(value);
        return 1;
    } else if (value < root->value) {
        return insertHelper(root->left, value);
    } else if (value > root->value) {
        return insertHelper(root->right, value);
    }
    return 0; 
}

size_t Set::insert(const std::string& value) {
    return insertHelper(mRoot, value);
}

const std::string& Set::lookup(size_t n) const {
    static std ::string s("");
    return s;
}

void Set::print() const {}

size_t Set::remove(const std::string& value) {
    return 1;
}