#include <iostream>
#include <string>

// 1.1 Implement an algorithm to determine if a string has all unique characters, without additional data structures
bool hasUniqueCharacters(const std::string& str) {
  for (const auto& c : str) {
    int count {0};
    for (const auto& x : str) {
      if (x == c) ++count;
    }

    if (count > 1) return false;
  }

  return true;
}

int main() {
  std::cout << "Result is : " << hasUniqueCharacters("Hello") << std::endl;
}