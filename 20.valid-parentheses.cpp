// Copyright 2019 chengenbao. All Rights Reserved.

/*
  Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

  An input string is valid if:

  Open brackets must be closed by the same type of brackets.
  Open brackets must be closed in the correct order.
  Note that an empty string is also considered valid.

  Example 1:

  Input: "()"
  Output: true
  Example 2:

  Input: "()[]{}"
  Output: true
  Example 3:

  Input: "(]"
  Output: false
  Example 4:

  Input: "([)]"
  Output: false
  Example 5:

  Input: "{[]}"
  Output: true
*/

#ifdef DEBUG

#include <string>
#include <iostream>

#endif  // DEBUG

#define MAX_LEN (1 << 20)

class Solution {
 public:
  bool isValid(const std::string& s) {
    char stack[MAX_LEN];
    int top = 0;
    auto p = s.c_str();
    char match[255];

    match[')'] = '(';
    match['}'] = '{';
    match[']'] = '[';
    while (*p) {
      switch (*p) {
        case '(':
        case '{':
        case '[':
          stack[top++] = *p;
          break;
        case ')':
        case '}':
        case ']':
          if (top == 0 || stack[--top] != match[*p]) {
            return false;
          }
        default:
          break;
      }
      ++p;
    }
    return top == 0;
  }
};

#ifdef DEBUG

int main(int argc, char** argv) {
  Solution s;
  std::cout << s.isValid("()") << std::endl;
  std::cout << s.isValid("()[]{}") << std::endl;
  std::cout << s.isValid("(]") << std::endl;
  std::cout << s.isValid("([)]") << std::endl;
  return 0;
}

#endif  // DEBUG
