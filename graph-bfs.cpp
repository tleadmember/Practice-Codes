/*
TQBH - 2023-06-15
Graph Using Adjacency List, and Breadth-First Search
*/

#include <iostream>


class Node {
public:
  int key;     // fields
  Node* prev;
  Node* next;
  int d; // distance from source vertex
  Node* pi; // predecessor
  char color;

  Node(int); // constructor
  //~Node(); // destructor
};


Node::Node(int newKey = 0) { //constructor
  key = newKey;
  prev = nullptr;
  next = nullptr;
  d = 0;
  pi = nullptr;
  color = 'W';
}



class Queue {
private:
  int count;
  Node* head;
  Node* tail;
public:
  Queue(); //constructor
  ~Queue(); //destructor

  int dequeue();       // other utility functions
  void enqueue(int);
  int front();
  int size();
  //bool isFull();
  //bool isEmpty();
  void print();
};


Queue::Queue() { // queue using linked list, no need to specify length
  count = 0;
  head = nullptr;
  tail = nullptr;
}


Queue::~Queue() {
  Node* tempNode1 = head, * tempNode2;
  while (tempNode1 != nullptr) {
    tempNode2 = tempNode1->next;
    delete tempNode1;
    tempNode1 = tempNode2;
  }
}


int Queue::dequeue() {
  Node* tempNode = head;

  --count;

  if (head == nullptr) {  // empty queue
    std::cout << "Error. Queue underflows.\n";
    return -1;
  } else {
    if (head == tail) {  // queue with one node
      head = nullptr;
      tail = nullptr;
    } else { // queue with more than one node
      tempNode->next->prev = nullptr;
      head = tempNode->next;
    }
  }

  int tempKey = tempNode->key;
  delete tempNode;
  return tempKey;
}


void Queue::enqueue(int newKey) {
  Node* newNode = new Node(newKey);

  ++count;

  if (head == nullptr) {  // empty queue
    head = newNode;
    tail = newNode;
  } else { // queue with at least one node
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;    
  }
  
  return;
}


int Queue::front() {
  if (head == nullptr) {
    std::cout << "Error. Empty queue. No head.\n";
    return -1;
  } else {
    return head->key;
  }
}


int Queue::size() {
  return count;
}


void Queue::print() {
  Node* tempNode = head;
  while (tempNode != nullptr) {
    std::cout << tempNode->key << " -> ";
    tempNode = tempNode->next;
  }
  std::cout << "NULL\n";
  return;
}


void BFS(Queue* G, Node* s) {
  // Breadth-first search. G is graph. s is source vertex
  
}



int main() {
  // Create a graph from example in Figure 20.1a on page 550, Cormen
  // 4th edition
  int numVertices = 5;
  Queue* G1 = new Queue[numVertices]; // array of 5 queues (5 adjacency lists)
  
  // Adj list for vertex 1
  G1[0].enqueue(2);
  G1[0].enqueue(5);
  // Adj list for vertex 2
  G1[1].enqueue(1);
  G1[1].enqueue(5);
  G1[1].enqueue(3);
  G1[1].enqueue(4);
  // Adj list for vertex 3
  G1[2].enqueue(2);
  G1[2].enqueue(4);
  // Adj list for vertex 4
  G1[3].enqueue(2);
  G1[3].enqueue(5);
  G1[3].enqueue(3);
  // Adj list for vertex 5
  G1[4].enqueue(4);
  G1[4].enqueue(1);
  G1[4].enqueue(2);

  // Print graph (adj list representation)
  for (int i = 0; i < numVertices; ++i) {
    std::cout << "Vertex " << i+1 << " ---> ";
    G1[i].print();
  }

  // Call BFS
  //BFS(G1, G1[2]);
  
  
  

  return 0;
}
