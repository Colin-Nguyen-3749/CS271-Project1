test: sorting_test.o
	g++ -o test sorting_test.o
	
sorting_test.o: sorting_test.cpp DoublyLinkedList.h DoublyLinkedList.cpp
	g++ -g -c sorting_test.cpp


