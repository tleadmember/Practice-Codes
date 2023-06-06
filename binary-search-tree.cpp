/*
TQBH - 2023-06-05
Binary Search Tree using C++
*/

#include <iostream>


class Node {
public:
  int key;
  Node* left;
  Node* right;
  Node* p;

  Node(int); //constructor
  ~Node(); //destructor
};


Node::Node(int newKey = 0) {
  key = newKey;
  left = nullptr;
  right = nullptr;
  p = nullptr;
}


Node::~Node() {
  //std::cout << "Node destructor called.\n";
  delete left;
  delete right;
}



class BST {
public:
  Node* root;
  
  BST();
  ~BST();

  void assignRoot(Node*);
  void inorderTreeWalk(Node*);
  //void destroyRecursive(Node*);
  Node* recursiveTreeSearch(Node*, int);
};


BST::BST() {
  root = nullptr;
}


BST::~BST() {
  //std::cout << "BST destructor called.\n";
  delete root;

  //destroyRecursive(root);
}

/*
void BST::destroyRecursive(Node* node) {
  if (node) {
    destroyRecursive(node->left);
    destroyRecursive(node->right);
    delete node;
  }
}
*/


void BST::assignRoot(Node* node) {
  root = node;
}


void BST::inorderTreeWalk(Node* node) {
  if (node) {
    inorderTreeWalk(node->left);
    std::cout << node->key << "  ";
    inorderTreeWalk(node->right);
  }
}


Node* BST::recursiveTreeSearch(Node* subroot, int searchKey) {
  Node* temp = subroot;
  while (temp != nullptr && temp->key != searchKey) {
    if (temp->key > searchKey) {
      temp = temp->left;
    } else {
      temp = temp->right;
    }
  }
  return temp;
}



int main() {
  BST t1;

  Node* n1 = new Node(6);
  Node* n2 = new Node(5);
  Node* n3 = new Node(7);
  Node* n4 = new Node(2);
  Node* n5 = new Node(5);
  Node* n6 = new Node(8);
  
  // Example BST in Cormen, chap 12.1, page 313
  n1->left = n2;
  n1->right = n3;
  t1.assignRoot(n1);

  n2->p = n1;
  n2->left = n4;
  n2->right = n5;

  n3->p = n1;
  n3->right = n6;

  n4->p = n2;

  n5->p = n2;
  
  n6->p = n3;

  // Print BST in order
  t1.inorderTreeWalk(t1.root);
  std::cout << std::endl;

  // Search
  int targetKey = 9;
  Node* returnNode = t1.recursiveTreeSearch(t1.root, targetKey);
  if (returnNode == nullptr) {
    std::cout << "Key " << targetKey << " not found.\n";
  } else {
    std::cout << "Search returns: " << returnNode->key << std::endl;
  }
  
  
  return 0;
}
