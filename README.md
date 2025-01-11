### EE200 Homework Assignment: Templated LinkedList Class

#### Project Overview
This project implements a templated `LinkedList` class in C++ as part of an assignment focusing on memory management, deep copying, and linked data structures. The class supports dynamic operations such as insertion, deletion, and retrieval, offering a robust and flexible implementation for managing lists of any data type. Emphasis was placed on clean memory management and adherence to C++ best practices.

#### Features
- **Constructors**:
  - Default constructor to initialize an empty list.
  - Constructor to initialize the list from an array with deep copying.
  - Copy constructor for creating deep copies of `LinkedList` instances.
- **Destructor**: Safely cleans up all dynamically allocated memory to prevent leaks.
- **Dynamic Operations**:
  - `size()`: Returns the number of elements in the list.
  - `getItem(int n)`: Retrieves the element at the specified index.
  - `insert(T x, int pos)`: Inserts a new element at the specified position.
  - `remove(int pos)`: Removes the element at the specified position.
- **Operator Overloading**:
  - Deep copy assignment operator to ensure safe copying between `LinkedList` instances.
- **Memory Management**:
  - Designed to be Valgrind-clean, ensuring no memory leaks or invalid accesses.

#### Implementation Highlights
- **Templating**: Provides flexibility for creating linked lists of any data type.
- **Encapsulation**: Public methods manage the linked list, while implementation details are hidden in private members.
- **Dynamic Memory Safety**: Uses raw pointers with careful allocation and deallocation for node management.

#### Testing
Comprehensive tests were written to validate each functionality:
- Basic operations such as insertion, deletion, and retrieval.
- Edge cases like inserting/removing at the beginning or end of the list.
- Deep copy correctness with the copy constructor and assignment operator.
- Memory management verified with Valgrind to ensure no leaks or errors.

#### Repository Content
- **Source Code**: Implementation of the `LinkedList` class and test cases.
- **Makefile**: Build system to compile the code and run tests.
- **Test Files**: Unit tests verifying the correctness and robustness of the implementation.

#### Authors
Gabby Beddard. Assignment completed as part of a data structures course focusing on linked lists and advanced memory management in C++.
