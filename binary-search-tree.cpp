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
  Node* treeMin(Node*);
  Node* treeMax(Node*);
  Node* successor(int);
  Node* predecessor(int);
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


Node* BST::treeMin(Node* subroot) {
  Node* temp = subroot;
  if (temp == nullptr) { // empty subtree input
    return nullptr;
  }
  while (temp->left != nullptr) {
    temp = temp->left;
  }
  return temp;
}


Node* BST::treeMax(Node* subroot) {
  Node* temp = subroot;
  if (temp == nullptr) { // empty subtree input
    return nullptr;
  }
  while (temp->right != nullptr) {
    temp = temp->right;
  }
  return temp;
}


Node* BST::successor(int targetKey) {
  Node* node = recursiveTreeSearch(root, targetKey);
  if (node == nullptr) {
    return nullptr;
  }
  if (node->right != nullptr) { // if node has a right child
    return treeMin(node->right);
  } else { // if node has no right child
    Node* tempCh = node;
    Node* tempPa = node->p;
    while (tempPa != nullptr && tempPa->left != tempCh) {
      tempCh = tempPa;
      tempPa = tempPa->p;
    }
    return tempPa;
  }
}


Node* BST::predecessor(int targetKey) {
  Node* node = recursiveTreeSearch(root, targetKey);
  if (node == nullptr) {
    return nullptr;
  }
  if (node->left != nullptr) {
    return treeMax(node->left);
  } else {
    Node* tempCh = node;
    Node* tempPa = node->p;
    while (tempPa != nullptr && tempPa->right != tempCh) {
      tempCh = tempPa;
      tempPa = tempPa->p;
    }
    return tempPa;
  }
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
  int targetKey1 = 9;
  Node* returnNode = t1.recursiveTreeSearch(t1.root, targetKey1);
  if (returnNode == nullptr) {
    std::cout << "Key " << targetKey1 << " not found.\n";
  } else {
    std::cout << "Search returns: " << returnNode->key << std::endl;
  }

  // Max
  std::cout << "Tree max: " << t1.treeMax(t1.root)->key << std::endl;

  // Min
  std::cout << "Tree min: " << t1.treeMin(t1.root)->key << std::endl;

  // Successor
  int targetKey2 = 2;
  std::cout << "Successor of " << targetKey2 << ": ";
  std::cout << t1.successor(targetKey2)->key << std::endl;

  // Predecessor
  int targetKey3 = 8;
  std::cout << "Predecessor of " << targetKey3 << ": ";
  std::cout << t1.predecessor(targetKey3)->key << std::endl;
  
  
  return 0;
}
