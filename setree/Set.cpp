#include "Set.h"

Node* copy(Node *&, Node *);

Set::Set() {
    mRoot = nullptr;
}

Node* copy(Node*& ptr, Node* otherNode) {
    if (otherNode == nullptr) {
        ptr = nullptr;
        return ptr;
    }
    ptr = new Node;
    ptr->value=otherNode->value;
    copy(ptr->left, otherNode->left);
    copy(ptr->right, otherNode->right);
    return ptr;
}

Set::Set(const Set& other) {
    mRoot = copy(mRoot, other.mRoot);
}

Set::Set(Set&& other) {
    mRoot = other.mRoot;
    other.mRoot = nullptr; 
}

Set::~Set() {
    clear();
}

size_t clearHelper(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    size_t count = clearHelper(node->left) + clearHelper(node->right) + 1;
    delete node;
    return count;
}

size_t Set::clear() {
    size_t count = clearHelper(mRoot);
    mRoot = nullptr;
    return count;
}

bool containsHelper(const Node* root, const std::string& value) {
    if (root == nullptr) {
        return false;
    } else if (root->value == value) {
        return true;
    } else if (value < root->value) {
        return containsHelper(root->left, value);
    } else {
        return containsHelper(root->right, value);
    }
}

bool Set::contains(const std::string& value) const {
    return containsHelper(mRoot, value);
}

size_t countHelper(const Node* root, const std::string& value) {
    if (root == nullptr) {
        return 0;
    } else if (root->value == value) {
        return 1 + countHelper(root->left, value) + countHelper(root->right, value);
    } else if (value < root->value) {
        return countHelper(root->left, value);
    } else {
        return countHelper(root->right, value);
    }
}

size_t Set::count() const {
    return countHelper(mRoot);
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
    static std::string s("");
    return s;
}

void Set::print() const {}

size_t Set::remove(const std::string& value) {
    return 1;
}