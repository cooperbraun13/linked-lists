#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

class DLLNode {
    public:
        int value;
        DLLNode* next;
        DLLNode* prev;
        DLLNode();
        DLLNode(int v);
        DLLNode(int v, DLLNode* n, DLLNode* p);
        ~DLLNode();
};

class DoublyLinkedList {
    private:
        DLLNode* head;
        DLLNode* tail;
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();
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
        void print_reverse();
        DLLNode* get_head() { return head; }
        DLLNode* get_tail();
};

#endif