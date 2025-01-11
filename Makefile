all: test_linkedlist

test_linkedlist: test_linkedlist.o
	g++ -g -o test_linkedlist test_linkedlist.o

test_linkedlist.o: test_linkedlist.cpp
	g++ -g -c test_linkedlist.cpp

run: test_linkedlist
	./test_linkedlist

valgrind: test_linkedlist
	valgrind --leak-check=full --track-origins=yes ./test_linkedlist

clean: 
	rm -f test_linkedlist *.o

.PHONY: all clean valgrind