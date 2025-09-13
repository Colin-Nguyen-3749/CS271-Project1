//=========================================
// Colin Nguyen
// September 12, 2025 
// sorting_test.cpp
// This is the file that contains all of my 
// tests that I'm using to make sure that
// my selection sort, insertion sort,
// merge sort, and quick sort all work
// properly!
//=========================================

#include <iostream>
#include <chrono>
#include <stdexcept>

#include "DoublyLinkedList.h"
using std::cout; 
using std::cerr;
using std::endl;
using std::string;

// SS = selection sort; ss_int = testing selection sort for integers
void ss_int() {
    
    DoublyLinkedList<int> dll;
    dll.append(123);
    dll.append(23);
    dll.append(0);
    dll.append(93);
    dll.append(4);
    dll.append(50);
    dll.append(14);
    dll.append(16);
    dll.selectionSort();
    cout << "The test is working" << endl;

    string dll_str = dll.to_string();
    if (dll_str == "0 4 14 16 23 50 93 123") {
        cout << "Yippee!!! " << dll_str << endl;
    } else {
        cout << "Try again"  << dll_str << endl;
    }
}

// SS = selection sort; ss_float = testing selection sort for float
void ss_float() {
    
    DoublyLinkedList<float> dll;
    dll.append(123.438);
    dll.append(23.943);
    dll.append(0.547);
    dll.append(93.16);
    dll.append(4.714);
    dll.append(50.346);
    dll.append(14.813);
    dll.append(16.46);
    dll.selectionSort();
    cout << "The test is working" << endl;

    string dll_str = dll.to_string();
    if (dll_str == "0.547 4.714 14.813 16.46 23.943 50.346 93.16 123.438") {
        cout << "Yippee!!! " << dll_str << endl;
    } else {
        cout << "Try again"  << dll_str << endl;
    }
}

int main() {
    ss_int();
    cout << "Testing selection sort for integers is working" << endl;

    ss_float();
    cout << "Testing selection sort for float is working" << endl;

    return 0;
}