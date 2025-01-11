#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdexcept>

// template
template <typename LLTemp>
class LinkedList{
  // You'll need to fill in the function declarations here, since writing them
  // correctly is half the challenge of some of these functions.  Be careful to
  // give them the same names as specified in the README, and pay special
  // attention to things which should be const, references, or both.  

  public:
    // default constructor
    LinkedList();
    // deconstuctor
    ~LinkedList();
    LinkedList(int length, LLTemp* values);

    // copy constructor 
    LinkedList(const LinkedList &copy);

    int size() const;

    // for deep copies, operator overloading
    LinkedList& operator=(const LinkedList &copy);

    LLTemp getItem(int n) const;

    void insert(LLTemp x, int pos);
    void remove(int pos);

  private:
    // from stackoverflow example, separate struct to specially access the Nodes of my LLs
    struct Node {
      LLTemp x;
      Node *next;
    };
    
    Node *head;
    int LL_size;
};

// LINKEDLIST.CPP FILE TIME BASICALLY
// follows template: 
    // template <typename T>
    // funct_type class_name<T>::funct_name(arguments) : initializer_list_vals {}
// example from array.h (HW 12)
    // template <typename ArrTemp> Array<ArrTemp>::Array() : size_arr(0), mem_space(1), mem_ptr(new ArrTemp[mem_space]) {}

template <typename LLTemp>
LinkedList<LLTemp>::LinkedList() : head(nullptr), LL_size(0) {}

template <typename LLTemp>
LinkedList<LLTemp>::~LinkedList() {
  // make a new node and assign it to head
  Node* temp = head;

  // while it's not NULL,
  // iterate through all nodes, deleting them one at a time
  while (temp != nullptr) {
    Node* next = temp->next;    // make a new ptr to a node called next that will get temp's next value
    delete temp;                // then delete temp! (doing this after ptr assignment to prevent dangling pointers)
    temp = next;                // then give temp a value (next) so "next" is now the new head! do this until NULL is reached, indicating the end of LL!
  }

  // make the head NULL, size of the list 0!
  head = nullptr;                // now that everything is deleted, assign head to null
  LL_size = 0;                   // LL size is 0 sinze everything is deleted! should be good to go now
}

template <typename LLTemp>
LinkedList<LLTemp>::LinkedList(int length, LLTemp* values) : head(nullptr), LL_size(0) {
  if (values != nullptr && length > 0) {
    for (int i = 0; i < length; i++) {
      insert(values[i], i);
    }
  }
}

template <typename LLTemp>
LinkedList<LLTemp>::LinkedList(const LinkedList &copy) : head(nullptr), LL_size(0) {
  if (copy.head == nullptr) {
    head = nullptr;
    LL_size = 0;
    return;
  }

  // Copy head node, similar to previous function 
  head = new Node;
  head->x = copy.head->x;     // setting current data of copy LL
  head->next = nullptr;       // basically making a 1 length LL 

  // now do this for the rest of the LL, similar to deconstructor 
  Node* current = head;
  Node* copy_current = copy.head->next;

  while (copy_current != nullptr) {
    Node* temp = new Node;
    temp->x = copy_current->x;
    temp->next = nullptr;
    current->next = temp;
    current = temp;
    copy_current = copy_current->next;
  } 
  LL_size = copy.LL_size;
}

template <typename LLTemp>
int LinkedList<LLTemp>::size() const {
  return LL_size;
}

template <typename LLTemp>
LinkedList<LLTemp>& LinkedList<LLTemp>::operator=(const LinkedList &copy) {
  if (this != &copy) {
    // copied from deconstructor basically 
    Node* temp = head;
    // while it's not NULL,
    // iterate through all nodes, deleting them one at a time
    while (temp != nullptr) {
      Node* next = temp->next;    // make a new ptr to a node called next that will get temp's next value
      delete temp;                // then delete temp! (doing this after ptr assignment to prevent dangling pointers)
      temp = next;                // then give temp a value (next) so "next" is now the new head! do this until NULL is reached, indicating the end of LL!
    }

    // make the head NULL, size of the list 0!
    head = nullptr;                // now that everything is deleted, assign head to null
    LL_size = 0;                   // LL size is 0 sinze everything is deleted! should be good to go now

    if (copy.head == nullptr) {
      return *this;
    }

    // Copy head node, similar to previous function 
    head = new Node;
    head->x = copy.head->x;     // setting current data of copy LL
    head->next = nullptr;       // basically making a 1 length LL 
    LL_size = 1;

    // now do this for the rest of the LL, similar to deconstructor 
    Node* current = head;
    Node* copy_current = copy.head->next;

    while (copy_current != nullptr) {
      Node* temp = new Node;
      temp->x = copy_current->x;
      temp->next = nullptr;
      current->next = temp;
      current = temp;
      copy_current = copy_current->next;
      LL_size += 1;
    } 
  }
  return *this;
}

template <typename LLTemp>
LLTemp LinkedList<LLTemp>::getItem(int n) const {
  // if nth item index is out of range, throw an exception
  if (n < 0 || n >= LL_size) {
    throw std::out_of_range("error: index out of range!");
  }  
  // otherwise, create a Node and iterate through LL till you get to the nth item
  Node* temp = head;
  for (int i = 0; i < n; i++) {
    temp = temp->next;
  }
  return temp->x;  
}

template <typename LLTemp>
void LinkedList<LLTemp>::insert(LLTemp x, int pos) {
  if (pos < 0 || pos > LL_size) {
    throw std::out_of_range("error: index out of range!");
  }
  
  Node* new_node = new Node;    // new node to edit in loop
  new_node->x = x;              // make said new node's values the same as the values arg
  new_node->next = nullptr;     // initialize the end of the LL 
  
  if (pos == 0) {
    new_node->next = head;
    head = new_node;
  }
  else {
    Node* temp = head;
    for (int i = 0; i < pos - 1; i++) {
      temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;   
  }
  LL_size += 1;                 // increase LL size and then start it all over, incrementing till LL is complete
}

template <typename LLTemp>
void LinkedList<LLTemp>::remove(int pos) {
  // basically the opposite of insert!
  if (pos < 0 || pos >= LL_size) {
    throw std::out_of_range("error: index out of range!");
  }
  
  Node* temp = head;    // new node to edit in loop
  if (pos == 0) {
    head = head->next;
    delete temp;
  }
  else {
    for (int i = 0; i < pos - 1; i++) {
      temp = temp->next;
    }
    Node* temp_ignore = temp->next;
    temp->next = temp_ignore->next;   
    delete temp_ignore;
  }
  LL_size -= 1;                 // decrease LL size and then start it all over, incrementing till LL is complete
}

#endif
