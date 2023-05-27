/*
TQBH - 2023-05-27
Stack Implementation Using Doubly Linked List
*/

#include <iostream>


class Node {
public:
  int key;     // fields
  Node* prev;
  Node* next;

  Node(int); // constructor
  //~Node(); // destructor
};


Node::Node(int newKey = 0) { //constructor
  key = newKey;
  prev = nullptr;
  next = nullptr;
}



class Stack {
private:
  int count;
  Node *head;
  Node *tail;
public:
  Stack(); //constructor
  ~Stack(); //destructor

  int pop();      // other utility functions
  void push(int);
  int top();
  int size();
  bool isFull();
  bool isEmpty();
};


Stack::Stack() { // stack using linked list, no need to specify length
  count = 0;
  head = nullptr;
  tail = nullptr;
}


Stack::~Stack() {
  Node* tempNode1 = head, * tempNode2;
  while (tempNode1 != nullptr) {
    tempNode2 = tempNode1->next;
    delete tempNode1;
    tempNode1 = tempNode2;
  }
}


int Stack::pop() {
  Node* tempNode = tail;

  --count;

  if (head == nullptr) {  // empty stack
    std::cout << "Error. Cannot pop an empty stack.\n";
    return -1;
  } else {
    if (head == tail) {  // stack with one node
      head = nullptr;
      tail = nullptr;
    } else { // stack with more than one node
      tempNode->prev->next = nullptr;
      tail = tempNode->prev;
    }
  }

  tempKey = tempNode->key;
  delete tempNode;
  return tempKey;
}


//push() 


int main() {
  Stack stack1();

  

  return 0;
}
