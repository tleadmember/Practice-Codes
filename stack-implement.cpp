/*
TQBH - 2023-05-19,20
Stack Implementation Using C++ Class
*/

#include <iostream>
#include <cstdlib>
#include <ctime>


// Define function to print an array
void printarray(int array[], int length) {
  using std::cout;
  using std::endl;
  for (int index = 0; index < length; ++index) {
    cout << array[index] << " ";
  }
  cout << endl;
}


// Define the default size of the stack (constant)
#define DEFAULT_SIZE 10


// Define stack using C++ class
class Stack {
  int* arr;  // if no access specifier = private access specifier
  int top;
  int capacity;
  
public:
  Stack(int size = DEFAULT_SIZE);  // constructor, same name as class,
				   // called when an object is created
  ~Stack();  // destructor, called when an object goes out of scope

  // Define common methods for a stack
  int size();
  void push(int);
  //int pop();
  //int peek();
  bool isFull();
  //bool isEmpty();
};


// Define constructor, outside of class body
Stack::Stack(int size) {
  arr = new int[size];
  top = -1;
  capacity = size;
}


// Define destructor
Stack::~Stack() {
  delete[] arr;  // to avoid memory leak after new opeator, memory reserved
}


// Define size() method
int Stack::size() {
  return capacity;
}
 

// Define push() method
void Stack::push(int x) {
  // Check if stack overflows
  if (isFull()) {
    std::cout << "Stack overflows. Program terminated." << std::endl;
    exit(EXIT_FAILURE);
  }
  // Push
  std::cout << "Pushing " << x << std::endl;
  arr[++top] = x;
}


// Define isFull() method
bool Stack::isFull() {
  return (top >= (capacity-1));
}



// Main function
int main() {
  using std::cout;
  using std::endl;

  int chosen_size = 6;
  Stack myStack(chosen_size); // if size not specified, Stack
			      // constructor will use DEFAULT_SIZE???

  cout << "Stack size is " << myStack.size() << endl;


  return 0;
}
