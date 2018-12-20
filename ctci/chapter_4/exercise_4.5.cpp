// Implement a function to check if a binary tree is a binary search tree.

#include <iostream>
#include <climits>

class Node {
  public:
    Node(int value, Node* left, Node* right)
      : _value{ value }, _left{ left }, _right{ right }
      {}

    Node* _left;
    Node* _right;
    int _value;
};

bool isValid(Node* node, int min, int max) {
  if (node == nullptr) return true;
  
  if (node->_left != nullptr) {
    if (node->_left->_value > node->_value) return false;
    if (node->_left->_value < min) return false;
  }

  if (node->_right != nullptr) {
    if (node->_right->_value < node->_value) return false;
    if (node->_right->_value > max) return false;
  }

  return isValid(node->_left, min, node->_value) && isValid(node->_right, node->_value, max);
}

bool isBinarySearchTree(const Node* tree) {
  if (tree == nullptr) return true;
  return isValid(tree->_left, INT_MIN, tree->_value) && isValid(tree->_right, tree->_value, INT_MAX);
}

inline std::string toString(bool b) {
  return b ? "true" : "false";
}

void freetree(Node* tree) {
  if (tree == nullptr) return;
  freetree(tree->_left);
  freetree(tree->_right);
  delete(tree);
}

int main() {
  Node* first = new Node { 3, 
    new Node { 2, new Node { 1, nullptr, nullptr }, nullptr },
    new Node { 5, new Node { 4, nullptr, nullptr}, new Node { 6, nullptr, nullptr} } };

  std::cout << "Is binary search tree (true):  " << toString(isBinarySearchTree(first)) << std::endl;

  Node* second = new Node { 2,
    new Node { 1, nullptr, new Node { 3, nullptr, nullptr } },
    new Node { 3, nullptr, new Node { 4, nullptr, nullptr } } };

  std::cout << "IS binary search tree (false): " << toString(isBinarySearchTree(second)) << std::endl;

  freetree(first);
  freetree(second);

  return 0;
}