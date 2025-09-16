//=========================================
// Colin Nguyen
// August 29, 2023
// DoublyLinkedList.cpp
// This is the .cpp file that defines all
// of the methods for the DoublyLinkedList 
// class.
//=========================================

#include "DoublyLinkedList.h"
#include <iostream>
#include <cmath>
using namespace std;

//===================================================
// default constructor
// Creates a new empty list object
// PARAMETERS: 
// none
// RETURN VALUE:
// none
//===================================================
template <typename T>
		DoublyLinkedList<T>::DoublyLinkedList		( void )
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}

//===================================================
// copy constructor 
// Creates a list that accepts an list of the same
// class as an argument 
// PARAMETERS:
// a list of items
// RETURN VALUE:
// none
//===================================================
template <typename T>
		DoublyLinkedList<T>::DoublyLinkedList		( const DoublyLinkedList<T> &mylist )
{
	// fromPtr = points to old list; toPtr = points to new list
	Node *fromPtr;
	Node *toPtr;
	Node *thisPtr;

	// If myList is just empty, return an empty doubly linked list constructor
	if ( mylist.head == NULL ) {
		head = nullptr;
		tail = nullptr;
		size = 0;
		return;
	}

	size = 0;
	// Set the fromPtr to the head of myList
	fromPtr = mylist.head;

	// Create a new head and tail pointing towards the list that we created to copy stuff to
	head = new Node;
	//tail = nullptr;
	
	// Set toPtr to the head of the newly created doubly linked list
	toPtr = head;
	// create a new node after the head and move toPtr there
	//toPtr->next = new Node; MISTAKE
	//size++;
	//toPtr = toPtr->next; MISTAKE
	toPtr->prev = nullptr; //set prev pointer for the first node to nullptr

	//fromPtr = fromPtr->next; //move fromPtr to the next node that actually has a value 

	toPtr->val = fromPtr->val; // copy the value from myList to new list

	fromPtr = fromPtr->next;  // move to the next node of myList
	while ( fromPtr != NULL ) {
		toPtr->next = new Node;
		thisPtr = toPtr;
		//toPtr->prev = toPtr; // set prev to current node before moving on
		toPtr = toPtr->next;
		toPtr->prev = thisPtr; // new

		toPtr->val = fromPtr->val;
		fromPtr = fromPtr->next;
		size++;
	}
	

	toPtr->next = nullptr; // set last node next to nullptr
	thisPtr = toPtr;
	tail = thisPtr; // set this node that thisPtr (toPtr) is pointing at as the previous node to tail
}

//===================================================
// destructor
// This deletes the dynamically-allocated memory that it created
// for this function to prevent memory leaks
// PARAMETERS:
// none
// RETURN VALUE:
// none
//===================================================
template <typename T>
		DoublyLinkedList<T>::~DoublyLinkedList		( void )
{
	clear();
}

//===================================================
// assignment operator
// This assigns the values of one list to another list
// PARAMETERS:
// a list of items
// RETURN VALUE:
// another list with the same values
//===================================================
template <typename T>
DoublyLinkedList<T>	DoublyLinkedList<T>::operator=	( const DoublyLinkedList<T> &mylist )
{
	// fromPtr = points to old list; toPtr = points to new list
	Node *fromPtr;
	Node *toPtr;
	Node *thisPtr;

	// If myList is just empty, return an empty doubly linked list constructor
	if ( mylist.head == NULL ) {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	size = 0;
	// Set the fromPtr to the head of myList
	fromPtr = mylist.head;

	// Create a new head and tail pointing towards the list that we created to copy stuff to
	head = new Node;
	//tail = nullptr;
	
	// Set toPtr to the head of the newly created doubly linked list
	toPtr = head;
	// create a new node after the head and move toPtr there
	//toPtr->next = new Node; MISTAKE
	//size++;
	//toPtr = toPtr->next; MISTAKE
	toPtr->prev = nullptr; //set prev pointer for the first node to nullptr

	//fromPtr = fromPtr->next; //move fromPtr to the next node that actually has a value 

	toPtr->val = fromPtr->val; // copy the value from myList to new list

	fromPtr = fromPtr->next;  // move to the next node of myList
	while ( fromPtr != NULL ) {
		toPtr->next = new Node;
		thisPtr = toPtr;
		//toPtr->prev = toPtr; // set prev to current node before moving on
		toPtr = toPtr->next;
		toPtr->prev = thisPtr; // new

		toPtr->val = fromPtr->val;
		fromPtr = fromPtr->next;
		size++;
	}
	

	toPtr->next = nullptr; // set last node next to nullptr
	thisPtr = toPtr;
	tail = thisPtr; // set this node that thisPtr (toPtr) is pointing at as the previous node to tail
}

//===================================================
// append
// This method appends a new time onto the end of the
// linked list.
// PARAMETERS:
// an item of type T
// RETURN VALUE:
// none, but this changes the list by adding a new
// item on the end.
//===================================================
template <typename T>
void 		DoublyLinkedList<T>::append	( const T &item )
{
	// create a new node
	Node *qtr = new Node;
	Node *thisPtr = head;
	qtr->next = nullptr;
	//qtr->prev = nullptr;
	// have qtr point to the end of the list (qtr)
	//tail = qtr;
	//qtr->prev = nullptr; // since qtr is the end of the llist, have it point to nullptr
	
	//Step 3) set item to new item
	qtr->val = item;
	
	if ( head == nullptr ) {
		//special case of empty list
		head = qtr;
		head->prev = nullptr;
		tail = qtr;
		tail->next = nullptr;
	} else {

		while (thisPtr->next != nullptr) {
			thisPtr = thisPtr->next;
		}
		
		thisPtr->next = qtr;
		qtr->prev = thisPtr;
		tail = qtr;
		// Start at the end because doubly linked lists have tails
		//tail->next = qtr; // Set the old tail to be next to the new node

		//qtr->prev = tail; // Have the new node have a prev pointing at the old tail
		//tail = qtr; // Set new tail to new node - but what about the old tail? 
	}
}

//===================================================
// operator[]
// This accesses and returns a value at a specified position.
// Valid indices are 0 to size-1. Invalid indices generate
// a run-time error and end the program. 
// PARAMETERS:
// a specified position
// RETURN VALUE:
// the value at the specified position	
//===================================================
template <typename T>
T &		DoublyLinkedList<T>::operator[]	( int index )
{
	Node *ptr = head;
	if ( index < length() && index >= 0 ) {
		for ( int i = 0; i < index; i++ ) {
			ptr = ptr->next;
		}
		return ptr->val;
	} else {
		throw runtime_error("Invalid index\n");
	}
}

//===================================================
// insert  ( item, position )
// This inserts a new value at a specified position, 
// rather than just the back. Indices that are valid
// are anything from 0 up to the length. If the 
// position is equal to the length then this function 
// acts like an append. All values already in the
// list are moved up one spot to make room.						// re-look over this one
// PARAMETERS:
// an item of type T and a specified position
// RETURN VALUE:
// a list of type T
//===================================================
template <typename T>
void		DoublyLinkedList<T>::insert	( const T &item, int index )
{
	Node *qtr = new Node;
	Node *ptr = head;
	if ( index <= length() && index > 0 ) {
		for ( int i = 0; i < index-1; i++ ) {
			ptr = ptr->next;
		}
		qtr->next = ptr->next;
		ptr->next = qtr;
		qtr->val = item;
		
		while ( ptr->next != nullptr ) {
			ptr = ptr->next;
		}
		
		
	} else if ( index == 0 ) {
		qtr->val = item;
		head = qtr;
		qtr->next = ptr;
	} else if (index == length()-1) {
		append(item);
	} else {
		throw runtime_error("Invalid index\n");
	}
}

//===================================================
// remove
// This removes an item at a specified position. 
// Valid indices are 0 to size-1.   Invalid indices 
// generate a run-time error and end the program.			// re-look over this one 
// PARAMETERS:
// a specified position
// RETURN VALUE:
// none
//===================================================

template <typename T>
void		DoublyLinkedList<T>::remove	( int index )
{
	Node *ptr = head;
	Node *prevPtr = NULL;
	Node *qtr = new Node;
	if ( index <= length() && index > 0 ) {
		for ( int i = 0; i < index; i++ ) {
			prevPtr =  ptr;
			ptr = ptr->next;
		}
		if ( ptr != NULL ) {
			prevPtr->next = ptr->next;
			delete ptr;
		}
	} else if ( index == 0 ) {
		head = ptr->next;
	} else if ( index == length()-1 ) {
		qtr = ptr->prev;
		delete tail;
		qtr = tail;
	} else {
		throw runtime_error("Invalid index\n");
	}
}

//===================================================
// operator+  (concatenate two lists)
// This will combine the two capacities of the lists 
// as well as their values into a new list. 
// PARAMETERS:
// two list of items										// is this fine the way it is? We're creating a new merged list, so we 
// RETURN VALUE:
// a merged list of the two input lists
//===================================================
template <typename T>
DoublyLinkedList<T> DoublyLinkedList<T>::operator+	( const DoublyLinkedList<T> &mylist ) const
{
	DoublyLinkedList<T> merge;	
	
	Node *fromPtr;
	Node *toPtr;
	Node *thisPtr;

	//Node *tracker = head;

	fromPtr = head;
	if ( fromPtr == nullptr ) {
		fromPtr = mylist.head;
		merge.head = new Node;
		toPtr = merge.head;
		toPtr->prev = nullptr; //new
		toPtr->next = merge.tail; // new
	} else {
		merge.head = new Node;
		toPtr = merge.head;
		toPtr->prev = nullptr;
		
		toPtr->val = fromPtr->val;
		fromPtr = fromPtr->next;
		while ( fromPtr != NULL ) {
			toPtr->next = new Node;
			//toPtr->prev = toPtr; // Am I making the prev pointer correctly? I want to set prev to the current pointer before moving on
			thisPtr = toPtr;
			toPtr = toPtr->next;
			toPtr->prev = thisPtr;
			merge.tail = toPtr; // Does this make every node a tail pointer? 
			toPtr->val = fromPtr->val;
			fromPtr = fromPtr->next;
		}
	}
	
	fromPtr = mylist.head;
	
	if ( mylist.head == NULL ) {
		return merge;
	} else {
		toPtr->next = new Node;
		toPtr = toPtr->next;
		toPtr->prev = merge.tail; // new 

		toPtr->val = fromPtr->val;
		fromPtr = fromPtr->next;
		while ( fromPtr != NULL ) {
			toPtr->next = new Node;
			//toPtr->prev = toPtr; //new 
			thisPtr = toPtr;
			toPtr = toPtr->next;
			toPtr->prev = thisPtr;
			merge.tail = toPtr;
			toPtr->val = fromPtr->val;
			fromPtr = fromPtr->next;
		}
	}
	return merge;
}

//===================================================
// length
// This counts and returns the number of items that 
// a list has
// PARAMETERS:												// This makes sense as of right now
// none
// RETURN VALUE:
// the number of items (in nodes) that a list has
//===================================================
template <typename T>
int		DoublyLinkedList<T>::length	( void ) const
{
	int length = 0;
	if ( head == nullptr ) {
		return length;
	} else {	
		Node *ptr = head;
		length++;
		while ( ptr->next != nullptr ) {
			ptr = ptr->next;
			length++;
		}
	}
	return length;
}

//===================================================
// isEmpty
// This returns ture if there are no items in a list; 
// otherwise, it will return false.
// PARAMETERS:
// none
// RETURN VALUE:
// none
//===================================================
template <typename T>
bool		DoublyLinkedList<T>::isEmpty	( void ) const
{
	if ( head == nullptr ) {
		return true;
	} else {
		return false;
	}
}

//===================================================
// clear
// This will remove all items in a list, resulting 
// in the list being empty.
// PARAMETERS:
// none
// RETURN VALUE:
// none
//===================================================
template <typename T>
void		DoublyLinkedList<T>::clear		( void )
{
	Node *ptr = head;
	while ( ptr != NULL ) {
		head = ptr;
		ptr = ptr->next;
		delete head;
	}
	head = ptr;
	delete head;
}


//===================================================
// Selection Sort
// This searches for the min value in the list[i:n]
// and once found, is added to the sorted side to the
// left of i, which is incremented afterwards. 
// PARAMETERS:
// none
// RETURN VALUE:
// none
//===================================================
template <typename T>
void		DoublyLinkedList<T>::selectionSort	( void )
{
	Node *indexPtr; // keeps track of index
	indexPtr = head; // set pointer to head
	int difference = 0; // keeps track of how much indexPtr should go for swapping
	Node *minPtr; // keeps track of the minimum of the shrinking list

	T swap; //This value saves whatever's inside a node that needs to be swapped
	int n = length(); // get the length of the list
	int minIndex = 0; // numerically keeps track of where the minPtr should go
	int minValue = 0;

	for (int i = 0; i < n-1; i++) { //outer loop goes through each list item one by one
		minIndex = i;
		if (i == 0) {
			minPtr = head; // if we're already at the start of the list, do nothing
			minValue = minPtr->val;
		} else {
			minPtr = minPtr->next; // if we don't want to be at the start of the list, go to the next node
			minValue = minPtr->val;
		}
		indexPtr = minPtr; 
		indexPtr = indexPtr->next; // set the indexPtr to be right next to the minPtr

		for (int j = i+1; j < n-1; j++) { // inner loop looks for the minimum value in list[i+1:n]
			if ((indexPtr->val) < (minValue)) {
				minIndex = j; // keeps track of where the smallest value is in list[i+1:n]
				minValue = indexPtr->val;
			}
			indexPtr = indexPtr->next;

		}
		if ((indexPtr->val) < (minValue)) {
			minIndex = n-1;
			minValue = indexPtr->val;
		}
		if (minIndex != i) {
			difference = abs(minIndex-i); // find how many nodes are between the minPtr and the indexPtr
			indexPtr = minPtr;
			for (int k = i; k < i+difference; k++) { // really tedious way to move our indexPtr where we need it to be
				indexPtr = indexPtr->next;
			}
			swap = minPtr->val;
			minPtr->val = indexPtr->val;
			indexPtr->val = swap;
		}
	}
	indexPtr->next = nullptr;
	tail = indexPtr;
	
}

//===================================================
// Insertion Sort
// For every item in the list, they will be swapped
// with the item in front of them if it is less
// until the right spot has been found.
// PARAMETERS:
// none
// RETURN VALUE:
// none
//===================================================
template <typename T>
void		DoublyLinkedList<T>::insertionSort ( void ) 
{
	Node *ptr = head->next;
	Node *indexPtr = ptr;
	Node *qtr = head;
	T item;
	T swap;

	while ( indexPtr->next != NULL ) {
		item = indexPtr->val;

		while (qtr->prev != nullptr && qtr->val > item) {
			swap = ptr->val;
			ptr->val = qtr->val;
			qtr->val = swap;

			qtr = qtr->prev;
			ptr = ptr->prev;
		}

		if ((qtr->prev == nullptr) && (qtr->val > item)) {
			swap = ptr->val;
			ptr->val = qtr->val;
			qtr->val = swap;
		}
		
		indexPtr = indexPtr->next;
		ptr = indexPtr;
		qtr = indexPtr->prev;
	}

	item = indexPtr->val;

	while (qtr->prev != nullptr && qtr->val > item) {
		swap = ptr->val;
		ptr->val = qtr->val;
		qtr->val = swap;

		qtr = qtr->prev;
		ptr = ptr->prev;
	}

	if ((qtr->prev == nullptr) && (qtr->val > item)) {
		swap = ptr->val;
		ptr->val = qtr->val;
		qtr->val = swap;
	}
}

//===================================================
// Merge Sort
// Using merge sort, the input list will be 
// sorted.
// PARAMETERS:
// none
// RETURN VALUE:
// none
//===================================================
template <typename T>
void 		DoublyLinkedList<T>::mergeSort 	( void )
{	
	int n = length();
	int q = n/2;
	int p = 0;
	int r = n-1;
	
	DoublyLinkedList<T> myList;
	myList.head = new Node;
	Node *toPtr = myList.head;
	Node *copyPtr = head;

	Node *prevNode = nullptr;
	while (copyPtr != nullptr) {
		toPtr->val = copyPtr->val;
		toPtr->prev = prevNode;

		if (copyPtr->next != nullptr) {
			toPtr->next = new Node;
		} else {
			toPtr->next = nullptr;
		}

		prevNode = toPtr;
		toPtr = toPtr->next;
		copyPtr = copyPtr->next;
	}

	
	mergeSortCall(myList, p, r);

	// Copy back into the original list
	// src = source
	// dst = destination
    Node *src = myList.head;
    Node *dst = head;
    while (src != nullptr && dst != nullptr) {
        dst->val = src->val;
        src = src->next;
        dst = dst->next;
    }
}

//===================================================
// MergeCall
// this just calls the merge function 
// PARAMETERS:
// a copy of the list, p (starting index), r (ending index)
// RETURN VALUE:
// none
//===================================================
template <typename T>
void 		DoublyLinkedList<T>::mergeSortCall 	( DoublyLinkedList<T>& myList, int p, int r )
{	

	if ( p >= r ) {
		return;
	}
	int q = ((p+r)/2);

	mergeSortCall(myList, p, q);
	mergeSortCall(myList, q+1, r);
	merge(myList, p, q, r);
}

//===================================================
// Merge 
// combines left and right sublists
// PARAMETERS:
// a copy of the list, p (starting index), r (ending index)
// RETURN VALUE:
// none
//===================================================
template <typename T>
void		DoublyLinkedList<T>::merge	( DoublyLinkedList<T>& myList, int p, int q, int r )
{
	DoublyLinkedList<T> leftSublist; // equivalent of left subarray 
	DoublyLinkedList<T> rightSublist; // equivalent of right subarray
	
	Node *leftQtr; // setting the left node to the head of the left sublist
	Node *rightPtr; // setting the right node to the head of the right sublist

	leftSublist.head = new Node; 
	rightSublist.head = new Node;
	leftQtr = leftSublist.head;
	rightPtr = rightSublist.head;
	
	Node *ptr = myList.head; // ptr keeps track of the original list for the RIGHT sublist
	Node *qtr = myList.head; // qtr keeps track of the original list for the LEFT sublist

	//q = length()/2;
	int L = q - p + 1; // left index tracker // removed + 1 after the p
	int R = r - q; // right index tracker


	// move ptr to the halfway point of the list
	for ( int k = 0; k < q+1; k++ ) {
		ptr = ptr->next;

	}

	for ( int g = 0; g < p; g++ ) {
		qtr = qtr->next;
	}

	// copy all values in the first half of the list to the left sublist
	for ( int i = 0; i < L; i++ ) {
		leftQtr->val = qtr->val;
		leftQtr->next = new Node;
		leftQtr = leftQtr->next;
		qtr = qtr->next;
	}

	// copy all values in the second half of the list to the right sublist
	for ( int j = 0; j < R; j++ ) {
		rightPtr->val = ptr->val;
		rightPtr->next = new Node;
		rightPtr = rightPtr->next;
		ptr = ptr->next;
	}

	int i = 0;
	int j = 0;
	int k = p;

	
	// ptr is now being used as an overall pointer, not just for the right sublist
	Node *toPtr;
	toPtr = myList.head;

	for ( int m = 0; m < k; m++ ) {
		if (toPtr->next != nullptr) {
			toPtr= toPtr->next;
		}
	}

	rightPtr = rightSublist.head;
	leftQtr = leftSublist.head; // reset both leftNode and rightNode pointers to the head

	while ( i < L && j < R ) {
		// if the item in the left sublist is less than the right sublist, copy that over to the ptr list
		if (leftQtr->val <= rightPtr->val) {
			toPtr->val = leftQtr->val;
			leftQtr = leftQtr->next;
			i++;
		} else {
			// if the item in the right sublist is less than the left sublist, copy that over to the ptr list
			toPtr->val = rightPtr->val;
			rightPtr = rightPtr->next;
			j++;
		}
		toPtr = toPtr->next;
		k++;
	}

	// handle any leftovers in the left or right sublist
	while ( i < L ) {
		toPtr->val = leftQtr->val;
		i++;
		toPtr = toPtr->next;
		leftQtr = leftQtr->next;
		k++;
	}
	while ( j < R ) {
		toPtr->val = rightPtr->val;
		j++;
		toPtr = toPtr->next;
		rightPtr = rightPtr->next;
		k++;
	}

	leftQtr = leftSublist.head;
	rightPtr = rightSublist.head;
}

//===================================================
// Quick sort
// Items are first partitioned and then combined to 
// be sorted
// PARAMETERS:
// none
// RETURN VALUE:
// none 
//===================================================
template <typename T>
void		DoublyLinkedList<T>::quickSort	( void )
{	
	int n = length();
	int q = n/2;
	int p = 0;
	int r = n-1;
	
	DoublyLinkedList<T> myList;
	myList.head = new Node;
	Node *toPtr = myList.head;
	Node *copyPtr = head;

	Node *prevNode = nullptr;
	while (copyPtr != nullptr) {
		toPtr->val = copyPtr->val;
		toPtr->prev = prevNode;

		if (copyPtr->next != nullptr) {
			toPtr->next = new Node;
		} else {
			toPtr->next = nullptr;
		}

		prevNode = toPtr;
		toPtr = toPtr->next;
		copyPtr = copyPtr->next;
	}

	
	quickSortCall(myList, p, r);

    Node *src = myList.head;
    Node *dst = head;
    while (src != nullptr && dst != nullptr) {
        dst->val = src->val;
        src = src->next;
        dst = dst->next;
    }
}
//===================================================
// Quick sort call
// This is how I'm trying to implement the 
// recursive calls
// PARAMETERS:
// a copy of the list, p (starting index), r (ending index)
// RETURN VALUE:
// none 
//===================================================
template <typename T>
void 		DoublyLinkedList<T>::quickSortCall 	( DoublyLinkedList<T>& myList, int p, int r ) 
{
	if (p < r) {
		q = partition(myList, p, r);
		quickSortCall(myList, p, q-1);
		quickSortCall(myList, q+1, r);
	}
}

//===================================================
// partition
// This function selects a pviot value, then using 
// that pviot value it separates values that are 
// lower on the left and those that are higher on the
// right. 
// PARAMETERS:
// a copy of the list, p (starting index), r (ending index)
// RETURN VALUE:
// none
//===================================================
template <typenameT>
void 		DoublyLinkedList<T>::partition	( DoublyLinkedList<T>& myList, int p, int r )
{
	Node *pivot = myList.head;
	for ( int i = 0; i < r; i++ ) {
		pivot = pivot->next;
	}

	int i = p - 1;
	T swap;

	Node *jPtr = myList.head;
	for ( int counter = 0; counter < j; counter++ ) {
		jPtr = jPtr->next;
	}

	Node *iPtr = myList.head;
	for ( int counter2 = 0; counter2 < i; counter2++ ) {
		iPtr = iPtr->next;
	}

	for ( int j = p; j < r-1; j++ ) {
		if (jPtr->val <= pivot->val) {
			i++;
			swap = iPtr->val;
			iPtr->val = jPtr->val;
			jPtr->val = swap;
			iPtr = iPtr->next;
		}
		jPtr = jPtr->next;
	}
	swap2 = iPtr->val;
	iPtr->val = jPtr->val;
	jPtr->val = swap2;
	i++;
}

