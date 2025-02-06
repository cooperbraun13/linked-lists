#include <stdexcept>
#include <iostream>
#include "doubly_linked_list.hpp"

DLLNode::DLLNode() {
    value = 0;
    next = nullptr;
    prev = nullptr;
}

DLLNode::DLLNode(int v) {
    value = v;
    next = nullptr;
    prev = nullptr;
}

DLLNode::DLLNode(DLLNode* n) {
    value = 0;
    next = n;
    prev = nullptr;
}

DLLNode::DLLNode(int v, DLLNode* n) {
    value = v;
    next = n;
    prev = nullptr;
}

DLLNode::DLLNode(int v, DLLNode* n, DLLNode* p) {
    value = v;
    next = n;
    prev = p;
}

DLLNode::~DLLNode() {
    delete next;
}

DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
}

DoublyLinkedList::~DoublyLinkedList() {
    delete head;
}

bool DoublyLinkedList::push_back(int v) {
    if (is_empty()) {
        return push_front(v);
    }
    DLLNode* new_node = new DLLNode(v);
    // new_node's prev pointer is set to the current tail
    new_node->prev = tail;
    tail->next = new_node;
    tail = new_node;
    return true;
}

bool DoublyLinkedList::push_front(int v) {
    DLLNode* new_node = new DLLNode(v);
    if (is_empty()) {
        head = new_node;
        tail = new_node;
    } else {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    return true;
}

bool DoublyLinkedList::insert(int v, int i) {
    if (i > size() || i < 0) {
        return false;
    } else if (i == 0) {
        return push_front(v);
    } else if (i == size()) {
        return push_back(v);
    }
    DLLNode* iter = head;
    if (i < size() / 2) {
        iter = head;
        for (int count = 0; count < i; count++) {
            iter = iter->next;
        }
    } else {
        iter = tail;
        for (int count = size() - 1; count > i; count--) {
            iter = iter->prev;
        }
    }
    DLLNode* new_node = new DLLNode(v, iter, iter->prev);
    iter->prev->next = new_node;
    iter->prev = new_node;
    return true;
}