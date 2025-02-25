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
    } 
    else {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    return true;
}

bool DoublyLinkedList::insert(int v, int i) {
    if (i > size() || i < 0) {
        return false;
    } 
    else if (i == 0) {
        return push_front(v);
    } 
    else if (i == size()) {
        return push_back(v);
    }
    DLLNode* iter = head;
    if (i < size() / 2) {
        // traverse from head if index is in the first half of the list
        iter = head;
        for (int count = 0; count < i; count++) {
            iter = iter->next;
        }
    } 
    else {
        // traverse from tail if index is in the second half of the list
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

int DoublyLinkedList::at(int i) {
    if (i < 0 || i >= size()) {
        throw std::out_of_range("invalid Index for List");
    }
    DLLNode* iter;
    if (i < size() / 2) {
        iter = head;
        for (int count = 0; count < i; count++) {
            iter = iter->next;
        }
    } 
    else {
        iter = tail;
        for (int count = size() - 1; count > i; count--) {
            iter = iter->prev;
        }
    }
    return iter->value;
}

int DoublyLinkedList::search(int v) {
    if (is_empty()) {
        return -1;
    }
    DLLNode* front_iter = head;
    DLLNode* back_iter = tail;
    int front_index = 0;
    int back_index = size() - 1;
    while (front_index <= back_index) {
        // check front pointer
        if (front_iter->value == v) {
            return front_index;
        }
        // check back pointer
        if (back_iter->value == v) {
            return back_index;
        }
        // move both iterators
        front_iter = front_iter->next;
        back_iter = back_iter->prev;
        front_index++;
        back_index--;
    }
    return -1;
}

bool DoublyLinkedList::is_empty() {
    // a tad overkill but rather safe than sorry
    return (head == nullptr && tail == nullptr);
}

int DoublyLinkedList::size() {
    if (is_empty()) {
        return 0;
    }
    int count = 1;
    for (DLLNode* iter = head; iter->next != nullptr; iter=iter->next) {
        count++;
    }
    return count;
}

bool DoublyLinkedList::remove(int i) {
    if (is_empty()) {
        return false;
    }
    else if (i < 0 || i >= size()) {
        return false;
    }
    // removing head
    if (i == 0) {
        DLLNode* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        }
        else {
            // list is now empty
            tail = nullptr;
        }
        temp->next = nullptr;
        delete temp;
        return true;
    }
    // traverse to the node being removed
    DLLNode* iter = head;
    for (int count = 0; count < i; count++) {
        iter = iter->next;
    }
    // update pointers
    iter->prev->next = iter->next;
    if (iter->next) {
        iter->next->prev = iter->prev;
    }
    else {
        tail = iter->prev;
    }
    iter->next = nullptr;
    iter->prev = nullptr;
    delete iter;
    return true;
}

bool DoublyLinkedList::remove_value(int v) {
    if (is_empty()) {
        return false;
    }
    DLLNode* iter = head;
    while (iter != nullptr && iter->value != v) {
        iter = iter->next;
    }
    if (iter == nullptr) {
        return false;
    }
    if (iter == head) {
        head = head->next;
        if (head) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
    }
    else if (iter == tail) {
        tail = tail->prev;
        tail->next = nullptr;
    }
    else {
        iter->prev->next = iter->next;
        iter->next->prev = iter->prev;
    }
    iter->next = nullptr;
    iter->prev = nullptr;
    delete iter;
    return true;
}

void DoublyLinkedList::print() {
    DLLNode* iter = head;
    while (iter != nullptr) {
        std::cout << iter->value << " ";
        iter = iter->next;
    }
    std::cout << std::endl;
}

void DoublyLinkedList::print_reverse() {
    DLLNode* iter = tail;
    while (iter != nullptr) {
        std::cout << iter->value << " ";
        iter = iter->prev;
    }
    std::cout << std::endl;
}