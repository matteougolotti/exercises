// Given two strings, write a method to decide if one is a permutation of the other.

#include <iostream>
#include <map>
#include <string>

std::map<char, int> countchars(const std::string& str) {
  std::map<char, int> chars;
  
  for (const auto& c : str) {
    if (chars.find(c) == chars.end()) {
      chars[c] = 1;
    } else {
      chars[c] = chars[c] + 1;
    }
  }

  return chars;
}

bool equals(const std::map<char, int>& first, const std::map<char, int>& second) {
  for (const auto& keyvalue : first) {
    const auto& key = keyvalue.first;
    if (second.find(key) == second.end()) return false;
    if (first.find(key)->second != second.find(key)->second) return false;
  }

  for (const auto& keyvalue : second) {
    const auto& key = keyvalue.first;
    if (first.find(key) == first.end()) return false;
    if (first.find(key)->second != second.find(key)->second) return false;
  }

  return true;
}

bool ispermutation(const std::string& first, const std::string& second) {
  std::map<char, int> firstchars = countchars(first);
  std::map<char, int> secondchars = countchars(second);

  return equals(firstchars, secondchars);
}

int main() {
  std::cout << "'Hello' and 'lloeH' are permutations: " << ispermutation("Hello", "lloeH") << std::endl;
  std::cout << "'Hello' and 'ciao' are permutations: " << ispermutation("Hello", "ciao") << std::endl;
}