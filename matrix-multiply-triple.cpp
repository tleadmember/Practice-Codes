/*
TQBH - 2023-04-23
Matrix Multiply, Triply Nested
*/

#include <iostream>

// Define function to print a matrix (2-D array)
void printarray(int array[][column_count], int row_count, int column_count) {
  using std::cout;
  using std::endl;
  for (int i = 0; i < row_count; i++) {
    for (int j = 0; j < column_count; j++) {
      cout << array[i][j] << "\t";
    }
    count << endl;
  }
  cout << endl;
}


// Main function
int main() {
  using std::cout;
  using std::endl;
  // Suppose we are given 2 SQUARE matrices to multiply
  int A[4][4] = {
    {5, -2, 4, 1}
    {7, 6, -5, 0}
    {2, -3, -9, 8}
    {2, 7, 2, 9}
    };
  int B[4][4] = {
    {-6, 3, 7, 3}
    {2, 6, -3, 7}
    {2, -6, 8, 4}
    {-5, 7, -1, 0}
    };

  /* Result of A*B should be
    {
    {-31, -14, 72, 17}
    {-40, 87, -9, 43}
    {-76, 98, -57, -51}
    {-39, 99, 0, 63}
    }
  */

  // Create blank matrix C as the resulting matrix C = A*B
  //int C[4][4];
  
  // Find length of matrix
  int len = *(&A + 1) - A;
  cout << "1-D length of matrix: " << len << endl;
  
  // Print matrix A
  cout << "Matrix A:" << endl;
  printarray(A, len, len);
  // Print matrix B
  cout << "Matrix B:" << endl;
  printarray(B, len, len);

  // Perform 

  // Print resulting matrix C
  
  return 0;
}
