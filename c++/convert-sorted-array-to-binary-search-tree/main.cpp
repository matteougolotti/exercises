// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

#include <iostream>
#include <vector>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val{ x }, left{ nullptr }, right{ nullptr } {}
};

TreeNode* insert(std::vector<int>& nums,int start,int end)
{
  if(start <= end) {
    int mid = (start + end)/2;
    TreeNode* node = new TreeNode(nums[mid]);
    node->left = insert(nums, start, mid - 1);
    node->right = insert(nums, mid + 1, end);
    return node;
  }
  
  return nullptr;
}

TreeNode* sortedArrayToBST(std::vector<int>& nums) {
  return insert(nums, 0, nums.size() - 1);
}

void freetree(TreeNode* node) {
  if (node == nullptr) return;
  freetree(node->left);
  freetree(node->right);
  delete(node);
}

std::string tostring(bool b) {
  return b ? "true" : "false";
}

void show(TreeNode* tree) {
  if (tree == nullptr) return;
  show(tree->left);
  show(tree->right);
  std::cout << tree->val << " " << std::endl;
}

int main() {
  std::vector<int> v{ -10, -3, 0, 5, 9 };

  auto bst = sortedArrayToBST(v);

  bool result = true;

  result = result && bst->val == 0;
  result = result && bst->left->val == -3;
  result = result && bst->left->left->val == -10;
  result = result && bst->right->val == 9;
  result = result && bst->right->left->val == 5;

  std::cout << "Result is correct: " << tostring(result) << std::endl;

  std::cout << "\n" << std::endl;

  show(bst);

  freetree(bst);

  return 0;
}
