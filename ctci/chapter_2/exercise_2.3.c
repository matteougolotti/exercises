// Implement an algorithm to delete a node in the middle of a singly linked list, given only access to that node.
// EXAMPLE
// Input: the node c from the linked list a->b->c->d->e
// Result: nothing is returned, but the new linked list looks like a- >b- >d->e

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node* next;
} Node_t;

void delete(Node_t* node) {
  if (node->next->next == NULL) {
    node->value = node->next->value;
    free(node->next);
    node->next = NULL;
  } else {
    node->value = node->next->value;
    delete(node->next);
  }
}

void insert(Node_t* node, int value) {
  if (node->next == NULL) {
    node->next = malloc(sizeof(Node_t));
    node->next->value = value;
    node->next->next = NULL;
  } else {
    insert(node->next, value);
  }
}

void show(Node_t* list) {
  Node_t* n = list;
  printf("\n");
  while (n != NULL) {
    printf("%d ", n->value);
    n = n->next;
  }
  printf("\n");
}

void freelist(Node_t* list) {
  if (list == NULL) return;
  freelist(list->next);
  free(list);
}

int  main() {
  Node_t* list = malloc(sizeof(Node_t));
  list->next = NULL;
  list->value = 0;

  insert(list, 1);
  insert(list, 2);
  insert(list, 3);
  insert(list, 4);

  show(list);
  delete(list->next->next);
  show(list);

  freelist(list);

  return 0;
}
