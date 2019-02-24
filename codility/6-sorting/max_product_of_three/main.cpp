#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>

int solution(std::vector<int>& A) {
  std::vector<int> descending{ A };

  std::sort(descending.begin(), descending.end(), [] (int a, int b) {
    return std::abs(a) > std::abs(b);
  });

  auto firstLargestPositiveIt = std::find_if(descending.begin(), descending.end(), [] (const int& v) {
    return v >= 0;
  });

  auto secondLargestPositiveIt = std::find_if(firstLargestPositiveIt + 1, descending.end(), [] (const int& v) {
    return v >= 0;
  });

  auto thirdLargestPositiveIt = std::find_if(secondLargestPositiveIt + 1, descending.end(), [] (const int& v) {
    return v >= 0;
  });

  auto firstLargestNegativeIt = std::find_if(descending.begin(), descending.end(), [] (const int& v) {
    return v < 0;
  });

  auto secondLargestNegativeIt = std::find_if(firstLargestNegativeIt + 1, descending.end(), [] (const int& v) {
    return v < 0;
  });

  // ppp -> (+) * (+) * (+)
  auto ppp = firstLargestPositiveIt != descending.end() && secondLargestPositiveIt != descending.end() && thirdLargestPositiveIt != descending.end()
               ? *firstLargestPositiveIt * *secondLargestPositiveIt * *thirdLargestPositiveIt
               : INT_MIN;

  // pnn -> (+) * (-) * (-)
  auto pnn = firstLargestPositiveIt != descending.end() && firstLargestNegativeIt != descending.end() && secondLargestNegativeIt != descending.end()
               ? *firstLargestPositiveIt * *firstLargestNegativeIt * *secondLargestNegativeIt
               : INT_MIN;

  std::vector<int> ascending{A};

  std::sort(ascending.begin(), ascending.end(), [] (int a, int b) {
    return a < b;
  });

  auto firstSmallestPositiveIt = std::find_if(ascending.begin(), ascending.end(), [] (const int& v) {
    return v >= 0;
  });

  auto secondSmallestPositiveIt = std::find_if(firstSmallestPositiveIt + 1, ascending.end(), [] (const int& v) {
    return v >= 0;
  });

  auto firstSmallestNegativeIt = std::find_if(ascending.begin(), ascending.end(), [] (const int& v) {
    return v < 0;
  });

  auto secondSmallestNegativeIt = std::find_if(firstSmallestNegativeIt + 1, ascending.end(), [] (const int& v) {
    return v < 0;
  });

  auto thirdSmallestNegativeIt = std::find_if(secondSmallestNegativeIt + 1, ascending.end(), [] (const int& v) {
    return v < 0;
  });

  // ppn -> (+) * (+) * (-)
  auto ppn = firstSmallestPositiveIt != ascending.end() && secondSmallestPositiveIt != ascending.end() && firstSmallestNegativeIt != ascending.end()
               ? *firstSmallestPositiveIt * *secondSmallestPositiveIt * *firstSmallestNegativeIt
               : INT_MIN;

  // nnn -> (-) * (-) * (-)
  auto nnn = firstSmallestNegativeIt != ascending.end() && secondSmallestNegativeIt != ascending.end() && thirdSmallestNegativeIt != ascending.end()
               ? *firstSmallestNegativeIt * *secondSmallestNegativeIt * *thirdSmallestNegativeIt
               : INT_MIN;

  std::vector<int> results { ppp, ppn, pnn, nnn };

  return *std::max_element(results.begin(), results.end());
}

int main() {
  std::vector<int> A{ -3, 1, 2, -2, 5, 6};

  int result = solution(A);

  std::cout << result << std::endl;

  assert(solution(A) == 60);
}