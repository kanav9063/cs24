#include "Set.h"
#include <iostream>
#include <stdexcept>


Node* copy(Node*&, Node*);
Node* look(Node*, size_t);
void printHelper(Node *);
size_t removeHelper(Node* &, const std::string& );

Set::Set() {
    mRoot = nullptr;
}

Node* copy(Node*& ptr, Node* otherNode) {
    if (otherNode == nullptr) {
        ptr = nullptr;
        return ptr;
    }
    ptr = new Node;
    ptr->value = otherNode->value;
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

bool containsHelper(Node* root, const std::string& value) {
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

size_t countHelper(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + countHelper(root->left) + countHelper(root->right);
}
size_t Set::count() const {
    return countHelper(mRoot);
}

void Set::debug() {}


size_t insertHelper(Node*& root, const std::string& value) {
    if (root == nullptr) {
        root = new Node;
        root->value = value;
        root->left = nullptr;
        root->right = nullptr;
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
    Node* temp = look(mRoot, n);
    if (temp == nullptr) {
        throw std::out_of_range("Invalid index");
    }
    return temp->value;
}

Node* look(Node* ptr, size_t n) {
    if (ptr == nullptr) {
        return nullptr;
    }
    size_t count = countHelper(ptr->left);
    if (count == n) {
        return ptr;
    } else if (count > n) {
        return look(ptr->left, n);
    } else {
        return look(ptr->right, n - count - 1);
    }
}

void Set::print() const {
    printHelper(mRoot);
    std::cout<<std::endl;
}
void printHelper(Node *ptr){
    if(ptr==nullptr){
        std::cout<<"-";
    }
    else if(ptr->left==nullptr && ptr->right==nullptr ){
        std::cout<<ptr->value;
    }
    else{
       std::cout<<"(";
       printHelper(ptr->left);
       std::cout<<" ";
       std::cout<<ptr->value;
       std::cout<<" ";
       printHelper(ptr->right);
       std::cout<<")";
    }
    
}

size_t Set::remove(const std::string& value) {
    return removeHelper(mRoot, value);
}

size_t removeHelper(Node* &ptr, const std::string& value) {
    if (ptr == nullptr) {
        return 0;
    }

    if (value < ptr->value) {
        return removeHelper(ptr->left, value);
    }
    else if (value > ptr->value) {
        return removeHelper(ptr->right, value);
    }
    else {
        if (ptr->left == nullptr) {
            Node* temp = ptr;
            ptr = ptr->right;
            delete temp;
            return 1;
        }
        else if (ptr->right == nullptr) {
            Node* temp = ptr;
            ptr = ptr->left;
            delete temp;
            return 1;
        }
        else {
            Node* temp = ptr->left;
            while (temp->right != nullptr) {
                temp = temp->right;
            }
            ptr->value = temp->value;
            return removeHelper(ptr->left, temp->value);
        }
    }
}