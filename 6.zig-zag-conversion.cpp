// Copyright 2019 chengenbao. All Rights Reserved.

/*
  The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

  P   A   H   N
  A P L S I I G
  Y   I   R
  And then read line by line: "PAHNAPLSIIGYIR"

  Write the code that will take a string and make this conversion given a number of rows:

  string convert(string s, int numRows);
  Example 1:

  Input: s = "PAYPALISHIRING", numRows = 3
  Output: "PAHNAPLSIIGYIR"
  Example 2:

  Input: s = "PAYPALISHIRING", numRows = 4
  Output: "PINALSIGYAHRPI"
  Explanation:

  P     I    N
  A   L S  I G
  Y A   H R
  P     I
*/

#ifdef DEBUG
#include <string>
#include <iostream>
#endif  // DEBUG

#include <vector>

class Solution {
 public:
  std::string convert(const std::string& s, int numRows) {
    if (numRows == 1) {
      return s;
    }

    std::vector<std::vector<char>> rows(numRows);
    int step = 1;
    int row = 0;
    int i = 0;
    while (i < s.size()) {
      rows[row].push_back(s[i]);
      row += step;
      if (row == numRows) {
        step = -1;
        row = numRows - 2;
      } else if (row == -1) {
        step = 1;
        row = 1;
      }
      ++i;
    }

    std::string result;
    result.reserve(s.size());
    for (auto& r : rows) {
      for (auto c : r) {
        result.push_back(c);
      }
    }

    return result;
  }
};

#ifdef DEBUG

int main(int argc, char** argv) {
  Solution s;
  std::cout << s.convert("PAYPALISHIRING", 3) << std::endl;
  std::cout << s.convert("PAYPALISHIRING", 4) << std::endl;
  std::cout << s.convert("AB", 1) << std::endl;
  return 0;
}

#endif  // DEBUG
