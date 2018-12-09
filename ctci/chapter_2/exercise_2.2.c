// 2.2 Implement an algorithm to find the kth to last element of a singly linked list.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node* next;
} Node_t;

Node_t* add(Node_t* list, int value) {
  Node_t *p = list;

  if (p == NULL) {
    p = malloc(sizeof(Node_t));
    p->next = NULL;
    p->value = value;
    return p;
  } else {
    while (p->next) p = p->next;
    p->next = malloc(sizeof(Node_t));
    p->next->value = value;
    p->next->next = NULL;
    return list;
  }
}

Node_t* findkthtoend(Node_t* list, int k) {
  int size = 0;
  Node_t *p = list;

  while (p != NULL) {
    ++size;
    p = p->next;
  }

  if (size - k - 1 >= 0) {
    p = list;
    for (int i = 0; i < (size - k - 1); ++i) {
      p = p->next;
    }
    return p;
  }

  return list;
}

int main() {
  Node_t *list = NULL;

  list = add(list, 0);
  list = add(list, 1);
  list = add(list, 2);
  list = add(list, 3);

  Node_t *kth = findkthtoend(list, 1);

  printf("\nKth to end: %d\n\n", kth->value);
}