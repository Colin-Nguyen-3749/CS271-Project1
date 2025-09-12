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

void test_selectionSort() {
    
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
        cout << "bum bidi bidi bidi bum bum"  << dll_str << endl;
    }
}

int main() {
    test_selectionSort();
    cout << "Testing selection sort is working" << endl;

    return 0;
}