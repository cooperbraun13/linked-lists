#include <iostream>
#include "linked_list.hpp"
#include "doubly_linked_list.hpp"

using namespace std;

int main() {
    LinkedList l1;
    l1.push_back(10);
    l1.push_front(5);
    l1.push_back(32);
    cout << l1.size() << endl;
    l1.print();
    l1.remove_value(32);
    l1.print();
    DoublyLinkedList l2;
    l2.push_back(10);
    l2.push_front(5);
    l2.push_back(32);
    cout << l2.size() << endl;
    l2.print();
    l2.remove_value(32);
    l2.print();
}