/*
TQBH - 2023-06-15,18,21,23
Graph and Breadth-First Search
*/

#include <iostream>


// A graph has a set of vertices and a set of edges


class Vertex {
public:
  int key;
  
  Vertex(int newKey) {
    key = newKey;
  }
  //~Vertex();
};



class Edge {
public:
  Vertex* v1, * v2;
  
  Edge(Vertex* va, Vertex* vb) {
    v1 = va;
    v2 = vb;
  }
  //~Edge();
};



class VertexList {
public:
  Vertex* data;
  VertexList* next;

  VertexList() {
    data = nullptr;
    next = nullptr;
  }
  ~VertexList() {
    delete data;
  }  
};



class EdgeList {
public:
  Edge* data;
  EdgeList* next;

  EdgeList() {
    data = nullptr;
    next = nullptr;
  }
  ~EdgeList() {
    delete data;
  }
};



class Queue {
public:
  VertexList* head;
  VertexList* tail;

  Queue() {
    head = nullptr;
    tail = nullptr;
  }
  
  ~Queue() {
    while (head != nullptr) {
      VertexList* tempV = head->next;
      delete head;
      head = tempV;
    }
  }

  void enqueue(Vertex* v) { // add to end of queue
    VertexList* tempV = new VertexList;
    tempV->data = v;
    if (head == nullptr) { // empty queue
      head = tempV;
      tail = tempV;
    } else if (head == tail) { // only one existing element

    } else { // more than one existing element

    }
  }

  Vertex* dequeue() {
    //
  }
};



class Graph {
public:
  VertexList* V;
  EdgeList* E;

  Graph();
  ~Graph();

  void addVertices(Vertex*);
  void addEdges(Vertex*, Vertex*);
  void graphPrint();
  Vertex* BFS(Vertex*, int);
};


Graph::Graph() {
  V = nullptr;
  E = nullptr;
}


Graph::~Graph() {
  while (V != nullptr) {
    VertexList* tempV = V->next;
    //delete V->data; // handled in ~Vertex()
    delete V;
    V = tempV;
  }
  
  while (E != nullptr) {
    EdgeList* tempE = E->next;
    //delete E->data; // handled in ~Edge()
    delete E;
    E = tempE;
  }
}


void Graph::addVertices(Vertex* newVertex) {
  VertexList* tempV = new VertexList;
  tempV->data = newVertex;
  tempV->next = V;
  V = tempV;
}


void Graph::addEdges(Vertex* va, Vertex* vb) {
  Edge* newEdge = new Edge(va, vb);
  EdgeList* tempE = new EdgeList;
  tempE->data = newEdge;
  tempE->next = E;
  E = tempE;
}


void Graph::graphPrint() {
  VertexList* tempV = V; // point to beginning of list
  
  while (tempV != nullptr) { 
    EdgeList* tempE = E; // point to beginning of list for each tempV
			 // iteration
    
    std::cout << "Vertex: " << tempV->data->key << " - ";
    std::cout << "Edges: ";
    
    while (tempE != nullptr) {
      if (tempE->data->v1 == tempV->data || tempE->data->v2 == tempV->data) {
	std::cout << tempE->data->v1->key << "-" << tempE->data->v2->key;
	std::cout << ", ";
      }
      tempE = tempE->next;
    }
    
    std::cout << std::endl;
    tempV = tempV->next;
    
  }

  std::cout << std::endl;
}


Vertex* Graph::BST(Vertex* x, int key) {
  // Create new frontier queue Q

  // Create new set V2 (all nodes ever added to frontier queue Q)

  // Insert x into Q

  // Insert x into V2

  // While loop

  // Otherwise, return that key is not found
  
}



int main() {
  // Create a graph like example in Figure 20.1a, p550, Cormen 4th ed
  Graph g; // for this practice, g is an undirected graph
  
  Vertex* vertex1 = new Vertex(1);
  g.addVertices(vertex1);
  Vertex* vertex2 = new Vertex(2);
  g.addVertices(vertex2);
  Vertex* vertex3 = new Vertex(3);
  g.addVertices(vertex3);
  Vertex* vertex4 = new Vertex(4);
  g.addVertices(vertex4);
  Vertex* vertex5 = new Vertex(5);
  g.addVertices(vertex5);
  
  g.addEdges(vertex1, vertex5); // undirected, order of vertices not matter
  g.addEdges(vertex1, vertex2);
  g.addEdges(vertex2, vertex5);
  g.addEdges(vertex2, vertex4);
  g.addEdges(vertex4, vertex5);
  g.addEdges(vertex3, vertex2);
  g.addEdges(vertex3, vertex4);

  // Print
  g.graphPrint();
  
  return 0;
}








/*
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


class Graph {
public:
  Graph();
  ~Graph();
};


Graph::Graph() {
  
}


void BFS(Queue* G, Node* s) { // Breadth-first search. G is graph. s
			      // is source vertex
  // Initialization of all vertices except the source vertex
  // (already done in Node constructor)

  s.color = 'G';
  
  
  
}

*/


/*
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

  // Call BFS, with source vertex being vertex key 3
  Node* sourceVertex = new Node(3);
  BFS(G1, sourceVertex);

  return 0;
}
*/
