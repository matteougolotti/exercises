/*

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

*/

#include <iostream>
#include <string>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

int number(ListNode* n) {
  return (n == nullptr) ? 0 : n->val;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry{0};
    ListNode* l{nullptr};
    ListNode* ln{nullptr};

    do {
      int value = number(l1) + number(l2) + carry;
      carry = value > 9;
      value = value % 10;

      if (l == nullptr) {
          l = new ListNode(value);
          ln = l;
          l->next = nullptr;
      } else {
          ln->next = new ListNode(value);
          ln = ln->next;
          ln->next = nullptr;
      }

      if (l1 != nullptr) {
        l1 = l1->next;
      }

      if (l2 != nullptr) {
        l2 = l2->next;
      }
    } while((l1 != nullptr) &&  (l2 != nullptr));

    return l;
  }


struct ListNode *list(const char *array, int size) {
    struct ListNode* l = new ListNode{0};
    struct ListNode* ln = l;

    for(int i = 0; i < size; i++) {
        if (l == nullptr) {
            l = new ListNode{array[i]};
            ln = l;
        } else {
            ln->next = new ListNode{array[i]};
            ln = ln->next;
        }
        ln->next = nullptr;
    }

    return l->next;
}

void printList(struct ListNode *p) {
    for(; p; p = p->next)
      std::cout << std::to_string(p->val);
    std::cout << std::endl;
}

void free(ListNode* l) {
    if (l == nullptr) return;
    if (l->next != nullptr) free(l->next);
    delete(l);
}

int main() {
  char list1[9] = {2, 4, 3};
  char list2[9] = {5, 6, 4};
  struct ListNode *l1 = list(list1, 3);
  struct ListNode *l2 = list(list2, 3);

  printList(l1);
  printList(l2);

  struct ListNode *answer = addTwoNumbers(l1, l2);
  printList(answer);

  free(l1);
  free(l2);

  return 0;
}