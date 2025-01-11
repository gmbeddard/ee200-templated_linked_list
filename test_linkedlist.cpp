#include "linkedlist.h"
#include <cstdio>
#include <stdexcept>
#include <string>

void testInsert() {
  LinkedList<int> list;

  // Insert elements at different positions
  list.insert(1, 0); // list = [1]
  list.insert(2, 0); // list = [2, 1]
  list.insert(3, 1); // list = [2, 3, 1]

  printf("testInsert:\n");
  for (int i = 0; i < list.size(); i++) {
    printf(" list[%d] = %d\n", i, list.getItem(i));
  }
}

void testRemove() {
  LinkedList<int> list;

  // Insert elements
  list.insert(1, 0); // list = [1]
  list.insert(2, 0); // list = [2, 1]
  list.insert(3, 0); // list = [3, 2, 1]

  // Remove elements
  list.remove(1); // list = [3, 1]
  list.remove(0); // list = [1]

  printf("testRemove:\n");
  for (int i = 0; i < list.size(); i++) {
    printf(" list[%d] = %d\n", i, list.getItem(i));
  }
}

void testGetItem() {
  LinkedList<int> list;

  // Insert elements
  list.insert(1, 0); // list = [1]
  list.insert(2, 0); // list = [2, 1]
  list.insert(3, 0); // list = [3, 2, 1]

  printf("testGetItem:\n");
  printf(" list[0] = %d\n", list.getItem(0)); // Should print 3
  printf(" list[1] = %d\n", list.getItem(1)); // Should print 2
  printf(" list[2] = %d\n", list.getItem(2)); // Should print 1
}

void testCopyConstructor() {
  LinkedList<int> list;

  // Insert elements
  list.insert(1, 0); // list = [1]
  list.insert(2, 0); // list = [2, 1]
  list.insert(3, 0); // list = [3, 2, 1]

  // Copy the list
  LinkedList<int> copy = list;

  printf("testCopyConstructor:\n");
  for (int i = 0; i < copy.size(); i++) {
    printf(" copy[%d] = %d\n", i, copy.getItem(i));
  }
}

void testAssignmentOperator() {
  LinkedList<int> list;

  // Insert elements
  list.insert(1, 0); // list = [1]
  list.insert(2, 0); // list = [2, 1]
  list.insert(3, 0); // list = [3, 2, 1]

  LinkedList<int> another;
  another = list;

  printf("testAssignmentOperator:\n");
  for (int i = 0; i < another.size(); i++) {
    printf(" another[%d] = %d\n", i, another.getItem(i));
  }
}

void testComprehensive() {
  LinkedList<int> list;

  // Insert elements
  list.insert(1, 0); // list = [1]
  list.insert(2, 0); // list = [2, 1]
  list.insert(3, 0); // list = [3, 2, 1]

  // Make a copy
  LinkedList<int> copy = list;

  // Modify the original list
  list.insert(4, 0); // list = [4, 3, 2, 1]
  list.insert(5, 0); // list = [5, 4, 3, 2, 1]

  // Remove an element from the copy
  copy.remove(1); // copy = [3, 1]

  printf("testComprehensive:\n");
  for (int i = 0; i < list.size(); i++) {
    printf(" list[%d] = %d\n", i, list.getItem(i));
  }

  for (int i = 0; i < copy.size(); i++) {
    printf(" copy[%d] = %d\n", i, copy.getItem(i));
  }
}

void testTemplateWithInt() {
  LinkedList<int> intList;

  intList.insert(10, 0); // intList = [10]
  intList.insert(20, 1); // intList = [10, 20]
  intList.insert(15, 1); // intList = [10, 15, 20]

  printf("testTemplateWithInt:\n");
  for (int i = 0; i < intList.size(); i++) {
    printf(" intList[%d] = %d\n", i, intList.getItem(i));
  }
}

void testTemplateWithDouble() {
  LinkedList<double> doubleList;

  doubleList.insert(3.14, 0);  // doubleList = [3.14]
  doubleList.insert(2.71, 0);  // doubleList = [2.71, 3.14]
  doubleList.insert(1.618, 1); // doubleList = [2.71, 1.618, 3.14]

  printf("testTemplateWithDouble:\n");
  for (int i = 0; i < doubleList.size(); i++) {
    printf(" doubleList[%d] = %.3f\n", i, doubleList.getItem(i));
  }
}

void testTemplateWithString() {
  LinkedList<std::string> stringList;

  stringList.insert("world", 0); // stringList = ["world"]
  stringList.insert("hello", 0); // stringList = ["hello", "world"]

  printf("testTemplateWithString:\n");
  for (int i = 0; i < stringList.size(); i++) {
    printf(" stringList[%d] = %s\n", i, stringList.getItem(i).c_str());
  }
}


void testComprehensiveTemplate() {
  LinkedList<std::string> stringList;
  LinkedList<int> intList;

  stringList.insert("First", 0); // stringList = ["First"]
  stringList.insert("Second", 1); // stringList = ["First", "Second"]

  intList.insert(100, 0); // intList = [100]
  intList.insert(200, 0); // intList = [200, 100]

  printf("testComprehensiveTemplate:\n");
  for (int i = 0; i < stringList.size(); i++) {
    printf(" stringList[%d] = %s\n", i, stringList.getItem(i).c_str());
  }
  for (int i = 0; i < intList.size(); i++) {
    printf(" intList[%d] = %d\n", i, intList.getItem(i));
  }
}

int main(int argc, char* argv[])
{
  testInsert();
  testRemove();
  testGetItem();
  testCopyConstructor();
  testAssignmentOperator();
  testComprehensive();

  // template tests
  testTemplateWithInt();
  testTemplateWithDouble();
  testTemplateWithString();
  testComprehensiveTemplate();
  // // Here's some quick test code to get you started.  You'll need much more
  // // thorough testing, of course.

  // LinkedList<int> list;

  // // Push three elements onto the front
  // list.insert(1, 0);
  // list.insert(2, 0);
  // list.insert(3, 0);

  // // Make a copy
  // LinkedList<int> another = list;

  // // Push some more elements onto the front of the original
  // list.insert(4, 0);
  // list.insert(5, 0);

  // for(int i = 0; i < list.size(); i++){
  //   printf(" list[%d] = %d\n", i, list.getItem(i));
  // }

  // for(int i = 0; i < another.size(); i++){
  //   printf("another[%d] = %d\n", i, another.getItem(i));
  // }

  return(0);
}

