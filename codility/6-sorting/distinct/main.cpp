#include <cassert>
#include <iostream>
#include <vector>
#include <set>

int solution(std::vector<int>& A) {
  std::set<int> s;

  for (int a : A) {
    s.insert(a);
  }

  return s.size();
}

int main() {
  std::vector<int> a{1, 2, 3};
  assert(3 == solution(a));
}