/*
TQBH - 2023-05-03
Max Heapify
*/

#include <iostream>

// Define function to print an array
void printarray(int array[], int length) {
  using std::cout;
  using std::endl;
  for (int index = 0; index < length; index++) {
    cout << array[index] << " ";
  }
  cout << endl;
}

// Define left() function to return index of left child of a node
int left(i) {
  return 2*i;
}

// Define right() function to return index of right child of a node
int right(i) {
  return 2*i + 1;
}

// Define max_heapify() function
void max_heapify(int array[], int i) {
  l = left(i);
  r = right(i);
  int len = *(&A + 1) - A;

  if ((l < len) && (A[l] > A[i])) {
    largest = l;
  } else {
    largest = i;
  }

  if ((r < len) && (A[r] > A[largest])) {
    largest = r;
  }

  if (largest <> i) {
    // If A[i] is not the largest, exchange A[i] with A[largest]
    temp = A[i];
    A[i] = A[largest];
    A[largest] = temp;
    // Recursively run max_heapify()
    max_heapify(A, largest);
  }
}


// Main function
int main() {
  using std::cout;
  using std::endl;
  // Suppose we are given an unsorted array
  int A[] = { 7, 2, 4, 5, 3, 1, 9, 8, 6 };

  // Find length of array
  int len = *(&A + 1) - A;
  cout << "Length of array: " << len << endl;
  
  // Print unsorted array
  cout << "Unsorted array A:" << endl;
  printarray(A, len);

  // Perform max_heapify()
  max_heapify(A, 0);

  // Print sorted array
  cout << "Sorted array A:" << endl;
  printarray(A, len);
  
  return 0;
}
