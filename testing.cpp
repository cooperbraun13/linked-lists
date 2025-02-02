#include<cassert>
#include<iostream>
#include<stdexcept>
#include<string>
#include "linked_list.hpp"


bool LL_test_push_front() {
    // Test 2 cases: empty and not
    // one list

    // set up
    LinkedList l;

    // execution
    bool return_test_1 = l.push_front(0);
    bool return_test_2 = l.push_front(5);

    // validation
    assert(return_test_1);
    assert(return_test_2);
    Node* l_head = l.get_head();
    assert(l_head->value == 5);
    assert(l_head->next->value == 0);
    assert(l_head->next->next == nullptr);

    // clean up
    return true;
}

bool LL_test_push_back() {
    // Test 3 cases: empty, length 1, and length >1
    // -only need one list, push_back three times with three assertions
    
    // set up
    LinkedList l;

    // execution
    bool return_test_1 = l.push_back(10);
    bool return_test_2 = l.push_back(5);
    bool return_test_3 = l.push_back(0);

    // validation
    assert(return_test_1);
    assert(return_test_2);
    assert(return_test_3);
    Node* l_head = l.get_head();
    assert(l_head->value == 10);
    assert(l_head->next->value == 5);
    assert(l_head->next->next->value == 0);
    assert(l_head->next->next->next==nullptr);

    // clean up
    return true;
}


bool LL_test_is_empty() {
    // Test cases: empty and not
    // Two lists

    // set up
    LinkedList l1, l2;
    l2.push_front(0);

    // execution
    bool return_test_1 = l1.is_empty();
    bool return_test_2 = l2.is_empty();

    // validation 
    assert(return_test_1);
    assert(!return_test_2);

    //clean up
    return true;

}

bool LL_test_size() { 
    // Test Cases: 0, 1, and more than 1
    // Three Lists

    // set up
    LinkedList l1, l2, l3;
    l2.push_front(1);
    l3.push_front(2);
    l3.push_front(1);

    // execution
    int return_test_1 = l1.size();
    int return_test_2 = l2.size();
    int return_test_3 = l3.size();

    // validation
    assert(return_test_1 == 0);
    assert(return_test_2 == 1);
    assert(return_test_3 == 2);

    //clean up
    return true;

}

bool LL_test_insert() {
    // Test cases: empty, size 1 front, size 1 back, size 2 middle, negative, too big
    // two lists

    // set up
    LinkedList l1, l2;
    l2.push_back(15);

    // execution 
    bool return_test_1 = l1.insert(5, 0);
    bool return_test_2 = l1.insert(10, 0);
    bool return_test_3 = l2.insert(0, 1);
    bool return_test_4 = l2.insert(100, 1);
    bool return_test_5 = l2.insert(1, -1);
    bool return_test_6 = l2.insert(45, 45);

    // validation
    assert(return_test_1);
    assert(return_test_2);
    assert(return_test_3);
    assert(return_test_4);
    assert(!return_test_5);
    assert(!return_test_6);
    Node* l1_head = l1.get_head();
    Node* l2_head = l2.get_head();
    assert(l1_head->value == 10);
    assert(l1_head->next->value == 5);
    assert(l2_head->value == 15);
    assert(l2_head->next->value == 100);
    assert(l2_head->next->next->value == 0);
    assert(l1_head->next->next == nullptr);
    assert(l2_head->next->next->next == nullptr);

    // clean up
    return true;
}

bool LL_test_at() {
    // Test cases: negative, too big, front, back and middle
    // one list

    // set up
    LinkedList l;
    l.push_front(3);
    l.push_front(2);
    l.push_front(1);
    int return_test_1, return_test_2, return_test_3, return_test_4, return_test_5, return_test_6 = -1;

    // execution
    try {
        return_test_1 = l.at(-1);
    }
    catch (std::out_of_range) {
        return_test_1 = 0;
    }
    catch (...) {
        std::cout << "Wrong error type" << std::endl;
        return_test_1 = 1;
    }
    try {
        return_test_2 = l.at(500);
    }
    catch(std::out_of_range) {
        return_test_2 = 0;
    }
    catch (...) {
        std::cout << "Wrong error type" << std::endl;
        return_test_2 = 0;
    }
    try {
        return_test_3 = l.at(0);
    }
    catch (...) {
        std::cout << "Unexpected Error" << std::endl;
        return_test_3 = 0;
    }
    try {
        return_test_4 = l.at(1);
    }
    catch (...) {
        std::cout << "Unexpected Error" << std::endl;
        return_test_3 = 0;
    }
    try {
        return_test_5 = l.at(2);
    }
    catch (...) {
        std::cout << "Unexpected Error" << std::endl;
        return_test_3 = 0;
    }

    // validation
    assert(!return_test_1);
    assert(!return_test_2);
    assert(return_test_3 == 1);
    assert(return_test_4 == 2);
    assert(return_test_5 == 3);

    // clean up
    return true;
    
}

bool LL_test_search() {
    // Test cases: first value, middle value, last value, not found 
    // one list

    // set up
    LinkedList l;
    l.push_front(3);
    l.push_front(2);
    l.push_front(1);

    // execution
    int return_test_1 = l.search(1);
    int return_test_2 = l.search(2);
    int return_test_3 = l.search(3);
    int return_test_4 = l.search(4);

    // validation
    assert(return_test_1 == 0);
    assert(return_test_2 == 1);
    assert(return_test_3 == 2);
    assert(return_test_4 == -1);

    // clean up
    return true;
}

bool LL_test_remove() {
    // Test cases: negative, too big, last, middle, first, only, empty
    // Single list

    // set up
    LinkedList l;
    l.push_front(4);
    l.push_front(3);
    l.push_front(2);
    l.push_front(1);
    
    // execution
    // std::cout << "Remove index -2: Negative" << std::endl;
    bool return_test_1 = l.remove(-2);
    // std::cout << "Remove index 5 : Too big" << std::endl;
    bool return_test_2 = l.remove(5);
    // std::cout << "Remove index 3 : Last" << std::endl;
    bool return_test_3 = l.remove(3);
    // std::cout << "Remove index 1 : Middle" << std::endl;
    bool return_test_4 = l.remove(1);
    // std::cout << "Remove index 0 : First" << std::endl;
    bool return_test_5 = l.remove(0);
    // std::cout << "Remove index 0 : Only " << std::endl;
    bool return_test_6 = l.remove(0);
    // std::cout << "Remove index 0 : Empty" << std::endl;
    bool return_test_7 = l.remove(0);
    // std::cout << "Remove finished" << std::endl;

    // validation
    assert(!return_test_1);
    assert(!return_test_2);
    assert(return_test_3);
    assert(return_test_4);
    assert(return_test_5);
    assert(return_test_6);
    assert(!return_test_7);
    return true;
}

bool LL_test_remove_value () {
    // Test cases: not found, last, middle, first, only, empty
    // single list

    // set up
    LinkedList l;
    l.push_front(4);
    l.push_front(3);
    l.push_front(2);
    l.push_front(1);

    // execution
    // std::cout << "Beginning Remove Value" << std::endl;
    bool return_test_1 = l.remove_value(5);
    // std::cout << "Removed nothing" << std::endl;
    bool return_test_2 = l.remove_value(4);
    // std::cout << "Removed Last" << std::endl;
    bool return_test_3 = l.remove_value(2);
    // std::cout << "Removed Middle" << std::endl;
    bool return_test_4 = l.remove_value(1);
    // std::cout << "Removed First" << std::endl;
    bool return_test_5 = l.remove_value(3);
    // std::cout << "Removed Only" << std::endl;
    bool return_test_6 = l.remove_value(6);
    // std::cout << "Ending Remove Value" << std::endl;

    // validation 
    assert(!return_test_1);
    assert(return_test_2);
    assert(return_test_3);
    assert(return_test_4);
    assert(return_test_5);
    assert(!return_test_6);

    // clean up
    return true;
}

int main() {
    std::cout << "Starting Tests" << std::endl;

    std::string result_1 = LL_test_push_front() ? "Passed" : "Failed";
    std::cout << "Push Front: " << result_1 << std::endl;

    std::string result_2 = LL_test_push_back() ? "Passed" : "Failed";
    std::cout << "Push Back: " << result_2 << std::endl;

    std::string result_3 = LL_test_is_empty() ? "Passed" : "Failed";
    std::cout << "Is Empty: " << result_3 << std::endl;

    std::string result_4 = LL_test_size() ? "Passed" : "Failed";
    std::cout << "Size: " << result_4 << std::endl;

    std::string result_5 = LL_test_insert() ? "Passed" : "Failed";
    std::cout << "Insert: " << result_5 << std::endl;

    std::string result_6 = LL_test_at() ? "Passed" : "Failed";
    std::cout << "At: " << result_6 << std::endl;

    std::string result_7 = LL_test_search() ? "Passed" : "Failed";
    std::cout << "Search: " << result_7 << std::endl;

    std::string result_8 = LL_test_remove() ? "Passed" : "Failed";
    std::cout << "Remove: " << result_8 << std::endl;

    std::string result_9 = LL_test_remove_value() ? "Passed" : "Failed";
    std::cout << "Remove_value: " << result_9 << std::endl;
    return 0;
}