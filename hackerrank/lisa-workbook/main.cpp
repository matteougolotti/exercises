#include <cassert>
#include <iostream>
#include <vector>

int workbook(int n, int k, std::vector<int>& arr) {
  int special = 0;
  int page = 0;
  int problemsInPage = 0;

  for (int i = 0; i < arr.size(); ++i) {
    ++page;
    problemsInPage = 0;
    for (int p = 1; p <= arr[i]; ++p) {
      ++problemsInPage;
      if (problemsInPage > k) {
        ++page;
        problemsInPage = 1;
      }

      if (p == page) {
        ++special;
      }
    }
  }

  return special;
}

int main() {
  std::vector<int> v1{ 4, 2, 6, 1, 10 };
  assert(workbook(5, 3, v1) == 4);

  std::vector<int> v2{ 3, 8, 15, 11, 14, 1, 9, 2, 24, 31 };
  assert(workbook(10, 5, v2) == 8);

  return 0;
}