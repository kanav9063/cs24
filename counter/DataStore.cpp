#include "DataStore.h"

// DataStore Member Functions
DataStore::DataStore() : head(nullptr), tail(nullptr) {}

DataStore::~DataStore() {
    node* current = head;
    while (current != nullptr) {
        node* next = current->next;
        delete current;
        current = next;
    }
}

void DataStore::insertNode(const std::string& key, int value) {
    node* newNode = new node;
    newNode->key = key;
    newNode->value = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void DataStore::deleteNode(node* targetNode) {
    if (targetNode == nullptr)
        return;

    if (targetNode == head && targetNode == tail) {
        // Only one node in the list
        head = nullptr;
        tail = nullptr;
    } else if (targetNode == head) {
        // Deleting the first node
        head = targetNode->next;
        head->prev = nullptr;
    } else if (targetNode == tail) {
        // Deleting the last node
        tail = targetNode->prev;
        tail->next = nullptr;
    } else {
        // Deleting a node in the middle
        targetNode->prev->next = targetNode->next;
        targetNode->next->prev = targetNode->prev;
    }

    delete targetNode;
}

DataStore::node* DataStore::findNode(const std::string& key) const {
    node* current = head;
    while (current != nullptr) {
        if (current->key == key)
            return current;
        current = current->next;
    }
    return nullptr;
}

DataStore::node* DataStore::getHead() const {
    return head;
}