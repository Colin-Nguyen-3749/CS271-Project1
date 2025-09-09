//=========================================
// Colin Nguyen
// August 29, 2023
// DoublyLinkedList.cpp
// This is the .cpp file that defines all
// of the methods for the DoublyLinkedList 
// class.
//=========================================

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
	Node *fromPtr;
	Node *toPtr;

	if ( mylist.head == NULL ) {
		head = NULL;
		return;
	}

	fromPtr = mylist.head;
	head = new Node;
	tail = new Node;
	tail = nullptr;
	toPtr = head;

	//previous = head;
	
	toPtr->val = fromPtr->val;
	fromPtr = fromPtr->next;
	while ( fromPtr != NULL ) {
		toPtr->next = new Node;
		toPtr = toPtr->next;
		toPtr->val = fromPtr->val;
		fromPtr = fromPtr->next;
	}
	toPtr->next = tail;
	//toPtr->next = nullptr;
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
	
	Node *ptr = head;
	while ( ptr != NULL ) {
		head = ptr;
		ptr = ptr->next;
		delete head;
	}
	
	Node *fromPtr;
	Node *toPtr;

	fromPtr = mylist.head;
	head = new Node;
	tail = new Node;
	tail = mylist.tail;
	toPtr = head;
	
	toPtr->val = fromPtr->val;
	fromPtr = fromPtr->next;
	while ( fromPtr != NULL ) {
		toPtr->next = new Node;
		toPtr = toPtr->next;
		toPtr->val = fromPtr->val;
		fromPtr = fromPtr->next;
	}
	toPtr->next = tail;
	//toPtr->next = nullptr;

	return *this;
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
	//Step 1) create a new node
	Node *qtr = new Node;
	
	//Step 2) set new node next to nil
	qtr->next = tail; 
	
	//Step 3) set item to new item
	qtr->val = item;
	
	if ( head == nullptr ) {
		//special case of empty list
		head = qtr;
	} else {
		//not empty list	
		/*Node *ptr = head;
		while ( ptr->next != nullptr ) {
			ptr = ptr->next;
		}
		ptr->next = qtr;
		*/
		
		
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
// list are moved up one spot to make room.
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
// generate a run-time error and end the program.
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
// two list of items
// RETURN VALUE:
// a merged list of the two input lists
//===================================================
template <typename T>
DoublyLinkedList<T> DoublyLinkedList<T>::operator+	( const DoublyLinkedList<T> &mylist ) const
{
	DoublyLinkedList<T> merge;	
	
	Node *fromPtr;
	Node *toPtr;

	//Node *tracker = head;

	fromPtr = head;
	if ( fromPtr == nullptr ) {
		fromPtr = mylist.head;
		merge.head = new Node;
		toPtr = merge.head;
	} else {
		merge.head = new Node;
		toPtr = merge.head;
		
		toPtr->val = fromPtr->val;
		fromPtr = fromPtr->next;
		while ( fromPtr != NULL ) {
			toPtr->next = new Node;
			toPtr = toPtr->next;
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
		toPtr->val = fromPtr->val;
		fromPtr = fromPtr->next;
		while ( fromPtr != NULL ) {
			toPtr->next = new Node;
			toPtr = toPtr->next;
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
// PARAMETERS:
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
	Node *qtr;
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
