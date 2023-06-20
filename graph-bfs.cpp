/*
TQBH - 2023-06-15,18
Graph Using Adjacency List, and Breadth-First Search
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
private:
  Vertex* v1, * v2;
public:
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
  //~VertexList();
};



class EdgeList {
public:
  Edge* data;
  EdgeList* next;

  EdgeList() {
    data = nullptr;
    next = nullptr;
  }
  //~EdgeList();
};



class Graph {
public:
  VertexList* V;
  EdgeList* E;
  VertexList** Adj; // adjacency lists for vertices

  Graph();
  ~Graph();

  void addVertices(Vertex*);
  void addEdges(Vertex*, Vertex*);
  void graphPrint();
};


Graph::Graph() {
  V = nullptr;
  E = nullptr;
  Adj = new VertexList*[5]; // adjacency lists for vertices,
			    // predetermined number of vertices,
			    // index = data-1 (example from Figure
			    // 20.1a, page 550, chapter 20, Cormen)
}


Graph::~Graph() {
  VertexList* tempV;
  while (V != nullptr) {
    tempV = V->next;
    delete V->data; // deallocate Vertex* memories
    delete V;
    V = tempV;
  }
  
  EdgeList* tempE;
  while (E != nullptr) {
    tempE = E->next;
    delete E->data; // deallocate Edge* memories
    delete E;
    E = tempE;
  }

  for (int i = 0; i < 5; ++i) {
    VertexList* tempV;
    while (Adj[i] != nullptr) {
      tempV = Adj[i]->next;
      delete Adj[i]; // no need to delete data field because pointing
		     // to the same Vertices deleted in V elements above
      Adj[i] = tempV;
    }
  }
  delete Adj;
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
  // Add to va and vb adj lists (undirected graph)
  VertexList* tempV = new VertexList;
  tempV->data = va;
  tempV->next = Adj[va->key -1];
  Adj[va->key - 1] = tempV;
  // same for vb
}


void Graph::graphPrint() {
  // TO BE ADDED
}



int main() {
  // ADD SOME VERTICES AND EDGES TO BUILD AN EXAMPLE GRAPH FIRST
  // BEFORE DOING BFS
  
  
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
