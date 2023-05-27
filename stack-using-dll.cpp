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
public:
  Stack(); //constructor
  ~Stack(); //destructor

  int pop();      // other utility functions
  void push(int);
  int top();
  bool isFull();
  bool isEmpty();
};


Stack::Stack() {

}



int main() {


  return 0;
}
