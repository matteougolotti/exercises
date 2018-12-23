// https://leetcode.com/problems/symmetric-tree/

#include <iostream>
#include <string>

class Node {
  public:
  Node(int value, Node* left, Node* right)
    : _value{ value }, _left{ left }, _right{ right }
    {}
   
  int _value;
  Node* _left;
  Node* _right;
};

bool symmetric(Node* left, Node* right) {
  if (left == nullptr && right == nullptr) return true;
  if (left != nullptr && right != nullptr && left->_value == right->_value) {
    return symmetric(left->_left, right->_right) && symmetric(left->_right, right->_left);
  }

  return false;
}

std::string tostring(bool b) {
  return b ? "true" : "false";
}

void freetree(Node* tree) {
  if (tree == nullptr) return;
  freetree(tree->_left);
  freetree(tree->_right);
  delete(tree);
}

int main() {
  Node* tree1 = new Node{ 0, new Node{ 1, new Node{ 2, nullptr, nullptr}, new Node{ 3, nullptr, nullptr } },
                             new Node{ 1, new Node{ 3, nullptr, nullptr}, new Node{ 2, nullptr, nullptr } } };
  
  Node* tree2 = new Node{ 0, nullptr, nullptr };
  Node* tree3 = new Node{ 0, new Node{ 1, nullptr, nullptr }, 
                             new Node{ 2, nullptr, nullptr } };

  std::cout << "First tree is symmetric (should be true): " << tostring(symmetric(tree1->_left, tree1->_right)) << std::endl;
  std::cout << "Second tree is symmetric (should be true): " << tostring(symmetric(tree2->_left, tree2->_right)) << std::endl;
  std::cout << "Third tree is symmetric (should be false): " << tostring(symmetric(tree3->_left, tree3->_right)) << std::endl;

  freetree(tree1);
  freetree(tree2);
  freetree(tree3);

  return 0;
}