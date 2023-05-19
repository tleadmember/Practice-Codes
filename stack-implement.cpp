/*
TQBH - 2023-05-19
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


// Define the default size of the stack
#define DEFAULT_SIZE = 10;


// Define stack using C++ class
class Stack {
public:
  Stack();  // constructor, same name as class, called when an object
	    // of this class is created
  ~Stack();  // destructor, called when an object goes out of scope

  //Define common methods for a stack
  void push(int);
  int pop();
  int peek();

  bool isFull();
  bool isEmpty();
  
};



// Main function
int main() {
  using std::cout;
  using std::endl;

  int chosen_size = 5;
  Stack myStack(chosen_size); // if size not specified, Stack
			      // constructor will use DEFAULT_SIZE???


  return 0;
}
