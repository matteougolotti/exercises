#include <stack>
#include <string>

int solution(std::string& s) {
  std::stack<char> stack;

  for (const auto& c : s) {
    if (c == '(' || c == '[' || c == '{') {
      stack.push(c);
    } else if (c == ')') {
      if (stack.top() == '(') {
        stack.pop();
      } else {
        return 0;
      }
    } else if (c == ']') {
      if (stack.top() == '[') {
        stack.pop();
      } else {
        return 0;
      }
    } else if (c == '}') {
      if (stack.top() == '{') {
        stack.pop();
      } else {
        return 0;
      }
    }
  }

  return stack.empty() ? 1 : 0;
}

int main() {
  std::string s1 = "{[()()]}";
  assert(solution(s1) == 1);

  std::string s2 = "([)()]";
  assert(solution(s2) == 0);

  return 0;
}