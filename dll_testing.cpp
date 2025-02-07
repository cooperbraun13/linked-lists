#include <cassert>
#include <iostream>
#include <stdexcept>
#include <string>
#include "doubly_linked_list.hpp"

// add elements to an empty list and then to a non-empty list
bool DLL_test_push_front() {
    // setup
    DoublyLinkedList list;

    // execution
    bool result1 = list.push_front(5);
    bool result2 = list.push_front(15);

    // validation
    assert(result1);
    assert(result2);
    DLLNode* head = list.get_head();
    // expect most recent push_front value, 15, at head
    assert(head->value == 15);
    assert(head->next->value == 5);
    assert(head->next->next == nullptr);

    // clean up
    return true;
}

// add elements to an empty list and then add to a non-empty list
bool DLL_test_push_back() {
    // setup
    DoublyLinkedList list;

    // execution
    bool result1 = list.push_back(100);
    bool result2 = list.push_back(80);
    bool result3 = list.push_back(60);

    // validation
    assert(result1);
    assert(result2);
    assert(result3);
    DLLNode* head = list.get_head();
    assert(head->value == 100);
    assert(head->next->value == 80);
    assert(head->next->next->value == 60);
    assert(head->next->next->next == nullptr);

    // clean up
    return true;
}

// check behavior on an empty list and a non-empty list
bool DLL_test_is_empty() {
    // setup
    DoublyLinkedList list1, list2;
    list2.push_front(7);

    // execution
    bool empty1 = list1.is_empty();
    bool empty2 = list2.is_empty();

    // validation
    assert(empty1);
    assert(!empty2);

    // clean up
    return true;
}

// ensure that the reported size matches the number of elements
bool DLL_test_size() {
    // setup
    DoublyLinkedList list1, list2, list3;
    list2.push_front(9);
    list3.push_front(3);
    list3.push_front(6);

    // execution
    int size1 = list1.size();
    int size2 = list2.size();
    int size3 = list3.size();

    // validation
    assert(size1 == 0);
    assert(size2 == 1);
    assert(size3 == 2);

    // clean up
    return true;
}

// insert values at various positions and test invalid indices
bool DLL_test_insert() {
    // setup
    DoublyLinkedList list1, list2;
    list2.push_back(50);

    // execution
    bool r1 = list1.insert(40, 0);
    bool r2 = list1.insert(20, 0);
    bool r3 = list2.insert(10, 1);
    bool r4 = list2.insert(90, 1);
    bool r5 = list2.insert(5, -1);
    bool r6 = list2.insert(70, 100);

    // validation
    assert(r1);
    assert(r2);
    assert(r3);
    assert(r4);
    assert(!r5);
    assert(!r6);
    DLLNode* head1 = list1.get_head();
    DLLNode* head2 = list2.get_head();
    assert(head1->value == 20);
    assert(head1->next->value == 40);
    assert(head1->next->next == nullptr);
    assert(head2->value == 50);
    assert(head2->next->value == 90);
    assert(head2->next->next->value == 10);
    assert(head2->next->next->next == nullptr);

    // clean up
    return true;
}

// retrieve values by index and ensure errors are thrown for invalid indices
bool DLL_test_at() {
    // setup
    DoublyLinkedList list;
    list.push_front(11);
    list.push_front(22);
    list.push_front(33);
    
    // execution
    int val0, val1, val2;
    try {
        val0 = list.at(0);
        val1 = list.at(1);
        val2 = list.at(2);
    } catch(...) {
        return false;
    }
    int invalidNeg = 1, invalidLarge = 1;
    try {
        list.at(-5);
    } catch (std::out_of_range&) {
        invalidNeg = 0;
    }
    try {
        list.at(100);
    } catch (std::out_of_range&) {
        invalidLarge = 0;
    }
    
    // validation
    assert(val0 == 33);
    assert(val1 == 22);
    assert(val2 == 11);
    assert(invalidNeg == 0);
    assert(invalidLarge == 0);
    
    // cleanup
    return true;
}

// verify that searching returns the correct index or -1 if not found
bool DLL_test_search() {
    // setup
    DoublyLinkedList list;
    list.push_front(44);
    list.push_front(33);
    list.push_front(22);

    // execution
    int return_test_1 = list.search(22);
    int return_test_2 = list.search(33);
    int return_test_3 = list.search(44);
    int return_test_4 = list.search(55);
    
    // validation
    assert(return_test_1 == 0);
    assert(return_test_2 == 1);
    assert(return_test_3 == 2);
    assert(return_test_4 == -1);
    
    // clean up
    return true;
}

// remove by index, including invalid indices and removal of head, middle, and tail
bool DLL_test_remove() {
    // setup
    DoublyLinkedList list;
    list.push_front(8);
    list.push_front(7);
    list.push_front(6);
    list.push_front(5);

    // execution
    bool r1 = list.remove(-1);
    bool r2 = list.remove(10);
    bool r3 = list.remove(3);
    bool r4 = list.remove(1);
    bool r5 = list.remove(0);
    bool r6 = list.remove(0);
    bool r7 = list.remove(0);

    // validation
    assert(!r1);
    assert(!r2);
    assert(r3);
    assert(r4);
    assert(r5);
    assert(r6);
    assert(!r7);
    
    // clean up
    return true;
}

// remove nodes by value, including non-existent values
bool DLL_test_remove_value() {
    // setup
    DoublyLinkedList list;
    list.push_front(14);
    list.push_front(13);
    list.push_front(12);
    list.push_front(11);

    // execution
    bool r1 = list.remove_value(99);
    bool r2 = list.remove_value(14);
    bool r3 = list.remove_value(12);
    bool r4 = list.remove_value(11);
    bool r5 = list.remove_value(13);
    bool r6 = list.remove_value(100);
    
    // validation
    assert(!r1);
    assert(r2);
    assert(r3);
    assert(r4);
    assert(r5);
    assert(!r6);
    
    // clean up
    return true;
}

int main() {
    std::cout << "Starting Doubly Linked List Tests" << std::endl;
    
    std::cout << "Push Front: " 
              << (DLL_test_push_front() ? "Passed" : "Failed") << std::endl;
    std::cout << "Push Back: " 
              << (DLL_test_push_back() ? "Passed" : "Failed") << std::endl;
    std::cout << "Is Empty: " 
              << (DLL_test_is_empty() ? "Passed" : "Failed") << std::endl;
    std::cout << "Size: " 
              << (DLL_test_size() ? "Passed" : "Failed") << std::endl;
    std::cout << "Insert: " 
              << (DLL_test_insert() ? "Passed" : "Failed") << std::endl;
    std::cout << "At: " 
              << (DLL_test_at() ? "Passed" : "Failed") << std::endl;
    std::cout << "Search: " 
              << (DLL_test_search() ? "Passed" : "Failed") << std::endl;
    std::cout << "Remove: " 
              << (DLL_test_remove() ? "Passed" : "Failed") << std::endl;
    std::cout << "Remove Value: " 
              << (DLL_test_remove_value() ? "Passed" : "Failed") << std::endl;
    
    return 0;
}
