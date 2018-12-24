// Given a binary tree, find its maximum depth.
// https://leetcode.com/problems/maximum-depth-of-binary-tree/

#include <algorithm>
#include <iostream>

class TreeNode {
public:
  TreeNode(int val_, TreeNode* left_, TreeNode* right_)
    : val{ val_ }, left{ left_ }, right{ right_ }
  {}

  int val;
  TreeNode* left;
  TreeNode* right;
};

int depth(int d, TreeNode* node) {
  if (node == nullptr) return d;
  else return std::max(depth(d + 1, node->left), depth(d + 1, node->right));
}

int maxdepth(TreeNode* tree) {
  return depth(0, tree);
}

void freetree(TreeNode* tree) {
  if (tree == nullptr) return;
  if (tree->left != nullptr) freetree(tree->left);
  if (tree->right != nullptr) freetree(tree->right);
  delete(tree);
}

int main() {
  TreeNode* a = new TreeNode{ 0, new TreeNode{ 1, new TreeNode{ 3, nullptr, nullptr }, nullptr },
                                 new TreeNode{ 2, nullptr, nullptr } };

  TreeNode* b = new TreeNode{ 0, new TreeNode{ 1, nullptr, nullptr },
                                 new TreeNode{ 2, nullptr, nullptr } };

  std::cout << "Depth (should be 3): " << maxdepth(a) << std::endl;
  std::cout << "Depth (should be 2): " << maxdepth(b) << std::endl;

  freetree(a);
  freetree(b);

  return 0;
}

