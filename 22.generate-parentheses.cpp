// Copyright 2019 chengenbao. All Rights Reserved.

/*
  Given n pairs of parentheses, write a function to generate all combinations of
  well-formed parentheses.

  For example, given n = 3, a solution set is:

  [
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
  ]
*/

#ifdef DEBUG

#include <iostream>
#include <string>
#include <vector>

#endif  // DEBUG

class Solution {
 public:
  std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> result;
    std::string path;
    path.reserve(n << 1);
    generate(n, n, &path, &result);
    return result;
  }

 private:
  void generate(int left, int right, std::string* path,
                std::vector<std::string>* result) {
    if (left == 0 && right == 0) {
      result->push_back(*path);
      return;
    }

    if (left > 0) {
      path->push_back('(');
      generate(left - 1, right, path, result);
      path->pop_back();
    }

    if (right > 0 && left < right) {
      path->push_back(')');
      generate(left, right - 1, path, result);
      path->pop_back();
    }
  }
};

#ifdef DEBUG

void PrintResult(const std::vector<std::string>& values) {
  for (auto& value : values) {
    std::cout << value << std::endl;
  }
}

int main(int argc, char** argv) {
  Solution s;
  PrintResult(s.generateParenthesis(3));
  return 0;
}

#endif  // DEBUG
