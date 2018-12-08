// Implement a function void reverse(char* str) in C or C++ which reverses a null- terminated string.

#include <stdio.h>
#include <string.h>

void reverse(char* str) {
  int size = strlen(str);

  for (char *l = str, *r = &str[size - 1]; l < r; ++l, --r) {
    char tmp = *l;
    *l = *r;
    *r = tmp;
  }
}

int main() {
  char str[] = "Hello, World!";
  reverse(str);
  printf("Result is: %s", str);
}