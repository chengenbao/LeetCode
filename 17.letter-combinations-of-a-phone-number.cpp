// Copyright 2019 chengenbao. All Rights Reserved.

/*
  Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

  A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

  Example:

  Input: "23"
  Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
  Note:

  Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

#ifdef DEBUG

#include <vector>
#include <string>
#include <iostream>

#endif  // DEBUG


class Solution {
 public:
  std::vector<std::string> letterCombinations(const std::string& digits) {
    std::vector<std::string> result;
    if (digits.empty()) {
      return result;
    }

    std::vector<std::vector<char>> table = {
      {'a', 'b', 'c'},       // '2'
      {'d', 'e', 'f'},       // '3'
      {'g', 'h', 'i'},       // '4'
      {'j', 'k', 'l'},       // '5'
      {'m', 'n', 'o'},       // '6'
      {'p', 'q', 'r', 's'},  // '7'
      {'t', 'u', 'v'},       // '8'
      {'w', 'x', 'y', 'z'}   // '9'
    };

    int count = 1;
    for (size_t i = 0; i < digits.size(); ++i) {
      count *= table[digits[i] - '2'].size();
    }

    result.resize(count, digits);
    int round = 1;
    for (int i = digits.size() - 1; i >= 0; --i) {
      char c = table[digits[i] - '2'][0];
      char e = table[digits[i] - '2'].back() + 1;
      char t = c;
      int j = 0;
      for (auto& r : result) {
        r[i] = t;
        ++j;
        if (j % round == 0) {
          ++t;
          if (t == e) {
            t = c;
          }
        }
      }
      round *= table[digits[i] - '2'].size();
    }

    return result;
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
  PrintResult(s.letterCombinations("23"));
  PrintResult(s.letterCombinations("7"));
  return 0;
}

#endif  // DEBUG
