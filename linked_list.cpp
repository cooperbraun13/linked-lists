#include <stdexcept>
#include <iostream>
#include "linked_list.hpp"

Node::Node() {
    value = 0;
    next = nullptr;
}

Node::Node(int v) {
    value = v;
    next = nullptr;
}

Node::Node(Node* n) {
    value = 0;
    next = n;
}

Node::Node(int v, Node* n) {
    value = v;
    next = n;
}

Node::~Node() {
    delete next;
}

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::~LinkedList() {
    delete head;
}

bool LinkedList::push_back(int v) {
    if (is_empty()) {
        return push_front(v);
    }
    Node* iter = head;
    while(iter->next != nullptr) {
        iter = iter->next;
    }
    iter->next = new Node(v);
    return true;
}

bool LinkedList::push_front(int v) {
    Node* temp = new Node(v, head);
    head = temp;
    return true;
}

bool LinkedList::insert(int v, int i) {
    
    if (i > size() || i < 0) {
        return false;
    } 
    else if (i == 0) {
        return push_front(v);
    }
    else if (i == size()) {
        return push_back(v);
    }
    else {
        Node* iter = head;
        for (int count = 1; count < i; count++) {
            iter = iter->next;
        }
        iter->next = new Node(v, iter->next);
        return true;
    }
}

int LinkedList::at(int i) {
    if (i < 0 || i >= size()) {
        throw std::out_of_range("Invalid Index for List");
    }
    else {
        Node* iter = head;
        for (int count = 0; count < i; count++) {
            iter = iter->next;
        }
        return iter->value;
    }
}

int LinkedList::search(int v) {
    Node* iter = head;
    int count = 0;
    while (iter->next != nullptr && iter->value != v) {
        iter = iter->next;
        count++;
    }
    if (iter->value == v) {
        return count;
    }
    return -1;
}

bool LinkedList::is_empty(){
    return head == nullptr;
}

int LinkedList::size() {
    if (is_empty()) {
        return 0;
    }
    int count = 1;
    for(Node* iter = head; iter->next != nullptr; iter=iter->next) {
        count++;
    }
    return count;
}

bool LinkedList::remove(int i) {
    if(is_empty()) {
        return false;
    }
    else if (i < 0 || i >= size()) {
        return false;
    }
    else if (i == 0) {
        Node* temp = head->next;
        head->next = nullptr;
        delete head;
        head = temp;
        temp = nullptr;
        return true;
    }
    else {
        Node* iter = head;
        for (int count = 1; count < i; count++) {
            iter = iter->next;
        }
        Node* temp = iter->next;
        if (temp->next == nullptr) {
            delete temp;
            iter->next = nullptr;
            return true;
        }
        iter->next = temp->next;
        temp->next = nullptr;
        delete temp;
        return true;
    }
}

bool LinkedList::remove_value(int v) {
    if (is_empty()) {
        return false;
    }
    Node* iter = head;
    if (iter->value == v) {
        head = head->next;
        iter->next = nullptr;
        delete iter;
        iter = nullptr;
        return true;
    }
    if(iter->next == nullptr) {
        return false;
    }
    while(iter->next->value != v && iter->next->next != nullptr) {
        iter = iter->next;
    }
    if(iter->next->value == v) {
        Node* temp = iter->next;
        iter->next = iter->next->next;
        temp->next = nullptr;
        delete temp;
        temp = nullptr;
        return true;
    }
    else {
        return false;
    } 
}

void LinkedList::print() {
    Node* iter = head;
    while (iter != nullptr) {
        std::cout << iter-> value << " ";
        iter = iter->next;
    } 
    std::cout << std::endl;
}