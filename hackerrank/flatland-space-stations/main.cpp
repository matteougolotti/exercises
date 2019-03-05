#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

int flatlandSpaceStations(int n, std::vector<int>& c) {
  std::sort(c.begin(), c.end(), [] (int a, int b) {
    return a < b;
  });

  int tmp = c[0];
  for (int i = 1; i < c.size(); ++i) {
    tmp = std::max(tmp, int(std::ceil((c[i] - c[i - 1]) / 2)));
  }

  return std::max(tmp, int(n - 1 - c[c.size() - 1]));
}

int main() {
  std::vector<int> v1{ 0, 1, 2, 4, 3, 5 };
  assert(0 == flatlandSpaceStations(6, v1));

  std::vector<int> v2{ 0, 4 };
  assert(2 == flatlandSpaceStations(5, v2));

  return 0;
}