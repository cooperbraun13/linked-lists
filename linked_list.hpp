#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

class Node {
    public:
        int value;
        Node* next;
        Node();
        Node(int v);
        Node(Node* n);
        Node(int v, Node* n);
        ~Node();
};

class LinkedList {
    private: 
        Node* head;

    public:
        LinkedList();
        ~LinkedList();
        bool push_back(int v);
        bool push_front(int v);
        bool insert(int v, int i);
        int at(int i);
        int search(int v);
        bool is_empty();
        int size();
        bool remove(int i);
        bool remove_value(int v);
        void print();
        Node* get_head() { return head; }
};

#endif