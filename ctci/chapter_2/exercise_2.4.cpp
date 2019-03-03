#include <iostream>

class Node {
  public:
    Node(int value, Node* next) : value_{value}, next_{next} {}

    int value_;
    Node* next_;
};

void freelist(Node *node) {
  if (node == nullptr) return;
  if (node != nullptr) freelist(node->next_);
  delete node;
}

void printlist(Node* node) {
  if (node == nullptr) {
    std::cout << std::endl;
    return;
  }
  std::cout << node->value_ << " ";
  printlist(node->next_);
}

Node* cutRec(Node* list, Node* tmp, int x, Node* result) {
  if (list->next_ == nullptr) {
    list->next_ = tmp;
  } else if (list->value_ >= x) {
    Node* next = list->next_;
    list->next_ = tmp;
    return cutRec(next, list, x, result);
  } else {
    return cutRec(list->next_, tmp, x, result == nullptr ? list : result);
  }

  return result;
}

Node* cut(Node* list, int x) {
  return cutRec(list, nullptr, x, nullptr);
}

int main() {
  Node* node = new Node{4, new Node{5, new Node{6, new Node{1, new Node{2, new Node{3, nullptr}}}}}};

  printlist(node);
  
  Node* newList = cut(node, 4);

  printlist(newList);

  freelist(newList);

  return 0;
}