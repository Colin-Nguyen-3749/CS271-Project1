test: test_dll_example.o
	g++ -o test test_dll_example.o
	
test_dll_example.o: test_dll_example.cpp DoublyLinkedList.h DoublyLinkedList.cpp
	g++ -g -c test_dll_example.cpp