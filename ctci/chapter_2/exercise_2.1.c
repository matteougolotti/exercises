// 2.1 Write code to remove duplicates from an unsorted linked list.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  char value;
  struct Node* next;
} Node_t;

void add(Node_t* node, char c) {
  Node_t* tmp = node;
  while(tmp->next != NULL) { tmp = tmp->next; }
  tmp->next = malloc(sizeof(Node_t));
  tmp->next->value = c;
  tmp->next->next = NULL;
}

void deletenext(Node_t* p) {
  Node_t* tmp = p->next->next;
  free(p->next);
  p->next = tmp;
}

void printlist(Node_t* list) {
  for (Node_t* p = list; p != NULL; p = p->next) {
    printf("%c", p->value);
  }
}

void freelist(Node_t* list) {
  if (list) return;
  if (list && list->next) freelist(list->next);
  free(list);
}

void removedups(Node_t* list) {
  int chars[256];

  for (int i = 0; i < 256; ++i) {
    chars[i] = 0;
  }

  if (list) chars[list->value] = 1;

  for (Node_t* p = list; p->next != NULL; p = p ->next) {
    ++chars[p->next->value];
    if (chars[p->next->value] > 1) {
      deletenext(p);
    }
  }
}

int main() {
  Node_t head;
  head.value = 'A';
  head.next = NULL;
  Node_t* list = &head;

  char b = 'B';
  add(list, b);
  add(list, b);
  
  char c = 'C';
  add(list, c);

  printf("\nBefore: ");
  printlist(list);

  removedups(list);

  printf("\nAfter: ");
  printlist(list);
  printf("\n");

  freelist(list);
}
