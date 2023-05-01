#include "Set.h"


Set::Set() {
    mRoot=nullptr;
}

Set::Set(const Set& other) {
    if (other.mRoot == nullptr) {
        mRoot = nullptr;
    } else {
        mRoot = new Node(*other.mRoot);
    }
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



size_t Set::insert(const std::string& value) {
    return 1;
}

const std::string& Set::lookup(size_t n) const {
    return " ";
}

void Set::print() const {}

size_t Set::remove(const std::string& value) {
    return 1;
}