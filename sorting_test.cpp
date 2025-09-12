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
    dll.append(5);
    dll.append(1);
    dll.append(2);
    dll.append(14);
    dll.append(8);
    dll.append(70);
    dll.append(60);
    dll.append(100);
    dll.selectionSort();
    cout << "The test is working" << endl;

    string dll_str = dll.to_string();
    if (dll_str == "1 2 5 8 14 60 70 100") {
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