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

// SS = selection sort; ss_long = testing selection sort for bigger numbers
void ss_long() {
    //-344375293 778467649 -1857762543 632266393 1186462265 -808487409 1160593853 888941915 733190708 778648453
    DoublyLinkedList<int> dll;
    dll.append(-344375293);
    dll.append(778467649);
    dll.append(-1857762543);
    dll.append(632266393);
    dll.append(1186462265);
    dll.append(-808487409);
    dll.append(1160593853);
    dll.append(888941915);
    dll.append(733190708);
    dll.append(778648453);
    //dll = [-344375293, 778467649, , 632266393, 1186462265, -808487409, 1160593853, 888941915, 733190708, 778648453];
    dll.selectionSort();
    cout << "The test is working" << endl;

    string dll_str = dll.to_string();
    if (dll_str == "-1857762543 -808487409 -344375293 632266393 733190708 778467649 778648453 888941915 1160593853 1186462265") {
        cout << "Yippee!!! " << dll_str << endl;
    } else {
        cout << "Try again"  << dll_str << endl;
    }
}

// 
void ss_file1() {
    
}
// SS = selection sort; ss_float = testing selection sort for float again THIS IS NOT WORKING
void ss_float2() {
    
    DoublyLinkedList<float> dll;
    dll.append(1);
    dll.append(1.8);
    dll.append(1.5);
    dll.append(1.2);
    dll.append(1.4);
    dll.append(1.3);
    dll.append(1.3);
    dll.append(1.3);
    dll.selectionSort();
    cout << "The test is workingsgd" << endl;

    string dll_str = dll.to_string();
    if (dll_str == "1.2 1.3 1.31 1.311 1.4 .15 1.8 1.9") {
        cout << "Yippee!!! " << dll_str << endl;
    } else {
        cout << "Try again "  << dll_str << endl;
    }
}

// is_int = insertion sort for integers
void is_int() {

    DoublyLinkedList<float> dll;
    dll.append(0);
    dll.append(4);
    dll.append(2);
    dll.append(6);
    dll.append(7);
    dll.append(1);
    dll.append(5);
    dll.append(3);
    cout << "The test is working" << endl;

    dll.insertionSort();
    cout << "The test is working" << endl;

    string dll_str = dll.to_string();
    if (dll_str == "0 1 2 3 4 5 6 7") {
        cout << "Yippee!!! " << dll_str << endl;
    } else {
        cout << "Try again "  << dll_str << endl;
    }
}

// ms_int = merge sort for integers
void ms_int() {

    DoublyLinkedList<float> dll;
    dll.append(0);
    dll.append(4);
    dll.append(2);
    dll.append(6);
    dll.append(7);
    dll.append(1);
    dll.append(5);
    dll.append(3);

    cout << "The test is working" << endl;

    dll.mergeSort();
    cout << "The test is working" << endl;

    string dll_str = dll.to_string();
    if (dll_str == "0 1 2 3 4 5 6 7") {
        cout << "Yippee!!! " << dll_str << endl;
    } else {
        cout << "Try again "  << dll_str << endl;
    }
}

// qs_int = merge sort for integers
void qs_int() {

    DoublyLinkedList<int> dll;
    dll.append(0);
    dll.append(4);
    dll.append(2);
    dll.append(6);
    dll.append(7);
    dll.append(1);
    dll.append(5);
    dll.append(3); 

    cout << "The test is working" << endl;

    dll.quickSort();
    cout << "The test is working" << endl;

    string dll_str = dll.to_string();
    if (dll_str == "0 1 2 3 4 5 6 7") {
        cout << "Yippee!!! " << dll_str << endl;
    } else {
        cout << "Try again quick sort "  << dll_str << endl;
    }
}

int main() {
    ss_int();
    cout << "Testing selection sort for integers is working" << endl;

    ss_float();
    cout << "Testing selection sort for float is working" << endl;

    ss_float2();
    cout << "Testing selection sort for float is working again" << endl;

    is_int();
    cout << "Testing insertion sort for in is working" << endl;

    ms_int();
    cout << "Testing merge sort for in is working" << endl;

    ss_long();

    qs_int();
    cout << "Testing quick sort is working" << endl;

    return 0;
}