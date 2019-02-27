#include <cassert>
#include <iostream>

#include <stdio.h>

int get(const int32_t n, int i) {
  return (n & (1 << i)) != 0;
}

int32_t set(int32_t n, int i) {
  return (n | (1 << i));
}

int32_t unset(int32_t n, int i) {
  return (n & (~(1 << i)));
}

int32_t f(int32_t n, int32_t m, int i, int j) {
  int32_t result = n;
  
  for (int k = j; k >= i; --k) {
    int v = get(m, k - i);
    result = v ? set(result, k) : unset(result, k);
  }

  return result;
}

void print(int32_t n) {
  std::cout << std::endl;

  for (int i{0}; i < 32; ++i) {
    std::cout << get(n, i);
  }

  std::cout << std::endl;
}

int main() {
  int n{1024};
  int m{19};

  int result = f(n, m, 2, 6);

  assert(1100 == result);

  return 0;
}