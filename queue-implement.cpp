/*
TQBH - 2023-05-21
Queue Implementation with C++
*/

#include <iostream>
#include <cstdlib>

#define DEFAULT_SIZE 20


// Define class of Queue
class Queue {
  int* arr;      // private access if no specifier
  int capacity;
  int headi;
  int taili;

public:             // public access
  Queue(int);       // constructor
  ~Queue();         // destructor
  int size();
  bool isFull();
  bool isEmpty();
  int head();
  bool enqueue(int);
  int dequeue();
};


// Define constructor, called when an object is created
Queue::Queue(int size = DEFAULT_SIZE) {
  arr = new int[size];
  capacity = size;
  headi = 0;
  taili = 0;
}


// Define destructor, call when an object goes out of scope
Queue::~Queue() {
  delete[] arr;  // delete memory allocated for pointer int*
}


// Define method to return the size of the queue
int Queue::size() {
  return capacity;
}


// Define method to tell if queue is full
bool Queue::isFull() {
  if ((headi == 0 && taili == capacity-1) || (taili == headi-1)) {
    return true;
  } else {
    return false;
  }
}


// Define method to tell if queue is empty
bool Queue::isEmpty() {
  if (taili == headi) {
    return true;
  } else {
    return false;
  }
}



// Main function
int main() {
  using std::cout;
  using std::endl;
  
  //int chosenSize = 10;
  //Queue q1(chosenSize);
  Queue q1;

  // Check the size allocated
  cout << "Size of queue: " << q1.size() << endl;
  
  return 0;
}

