/*
 Given a string containing just the characters '(' and ')', find the length of
the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
*/

// @lc code=start

#ifdef DEBUG

#include <iostream>
#include <string>
#include <vector>

#include "common.h"

class Solution2 {
 public:
  int longestValidParentheses(const std::string& s) {
    int sz = s.size();
    std::vector<std::vector<int>> d;
    d.resize(sz);

    for (int i = 0; i < sz; ++i) {
      d[i].resize(sz, 0);
      if (i < sz - 1 && s[i] == '(' && s[i + 1] == ')') {
        d[i][i + 1] = 2;
      }
    }

    for (int len = 4; len <= sz; len += 2) {
      for (int i = 0; i < sz; ++i) {
        int j = i + len - 1;
        if (j < sz && s[i] == '(' && s[j] == ')') {
          if (d[i + 1][j - 1] > 0) {
            d[i][j] = j - i + 1;
          } else {
            for (int k = i + 1; k < j; k += 2) {
              if (d[i][k] > 0 && d[k + 1][j] > 0) {
                d[i][j] = j - i + 1;
                break;
              }
            }
          }
        }
      }
    }

    int max = 0;
    for (int i = 0; i < sz; ++i) {
      for (int j = i + 1; j < sz; j += 2) {
        if (d[i][j] > max) {
          max = d[i][j];
        }
      }
    }

    return max;
  }
};

#endif  // DEBUG

class Solution {
 public:
  int longestValidParentheses(const std::string& s) {
    int sz = s.size();
    std::vector<int> d(sz, 0);
    for (int i = 0; i < sz; ++i) {
      if (s[i] == '(') {
        int j = i;
        int top = 0;
        int len = 0;
        while (j < sz) {
          if (s[j] == '(') {
            ++top;
          } else {
            --top;
            if (top == 0) {
              len = j - i + 1;
            } else if (top < 0) {
              break;
            }
          }
          ++j;
        }

        if (len > 0) {
          d[i] = len;
          i += len - 1;
        }
      }
    }

    int max = 0;
    for (int i = 0; i < sz; ++i) {
      int j = i;
      int sum = 0;
      while (j < sz && d[j] > 0) {
        sum += d[j];
        j += d[j];
      }
      if (sum > max) {
        max = sum;
      }
      d[i] = sum;
      i = j;
    }

    return max;
  }
};

#ifdef DEBUG

int main(int argc, char** argv) {
  Solution s;
  std::cout << s.longestValidParentheses("(()") << std::endl;
  std::cout << s.longestValidParentheses(")()())") << std::endl;
  std::cout << s.longestValidParentheses("(())()") << std::endl;
  std::cout << s.longestValidParentheses("()(()") << std::endl;
  std::cout << s.longestValidParentheses("()(())") << std::endl;
  std::cout
      << s.longestValidParentheses(
             "()()()(()))()()())))((()()()(()()))(()()()((()()))())(((())()())("
             "()(()(()(())(((()())()))(()))()))))()())(()))))()()(())()()((())("
             ")()))))((()))))(()()((()(()(()())((())()()()()))()()()(())()()())"
             "((((()(())())))(((()(((()((((())())(()()()()(((((()))()(()(())))("
             "((()()()()(()(((())(()(()()(()(()(())()))))))()))()())((()((((()("
             "())(()()()(((((()())()))))())))((((()()()(()(())(((())(((()()((()"
             "((()(((()(()))(((())(((()((((()(())(((()((()(()())))))(()(()()(()"
             ")))))()(()()((()))()))())())((())))()(())((((()((()))))()())()))("
             "(()(()())()())()()((()))())(()(()(())((((((()()((((())))())(((()("
             ")())))()(((()(()()((((())))))()()((((()(()()())(()(())()()()((()("
             "()((((())))((((((())(()())()))))(()(()))()))))))(()()((()()()())("
             "())))(((()))(()()()(()))((())()()()())()()(((())(()(())()()(()())"
             "((()()(((((())(()((((()(()()()(()))(()((((())()())()())())))())(("
             "(()(()((())()()((((()()()()))))))())())()(((((()())()(()()()()()("
             "((())((((((()))(())()(()())(()(()())(()(())))())))(()()(()((((()("
             ")(())(()))()))(()))(()())())()))))))()()(())))))()))()(()())))((("
             "))(()()))()((()))()(())()()((((())()))((()(()))()(((()())()(()()("
             "(()())((((())()))))()(())())())())(((()(()())))((()))))()())))))("
             "()((())))()())((()))()()))(())())()))()()((()(((())()()()((()()(("
             ")(())(()))())())(((()())(()())(()((()()()())()(()(((((((()()(((()"
             "(((((((())(()))))())()))))))))()(()(()((((())(()()(((()))()(())(("
             "(((((((()(()())())()(((()((()(((()(()()(()))(())))))))(((")
      << std::endl;

  return 0;
}

#endif  // DEBUG

// @lc code=end