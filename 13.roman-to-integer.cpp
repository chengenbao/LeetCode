// Copyright 2019 chengenbao. All Rights Reserved.

/*
  Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

  Symbol       Value
  I             1
  V             5
  X             10
  L             50
  C             100
  D             500
  M             1000
  For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

  Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

  I can be placed before V (5) and X (10) to make 4 and 9.
  X can be placed before L (50) and C (100) to make 40 and 90.
  C can be placed before D (500) and M (1000) to make 400 and 900.
  Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

  Example 1:

  Input: "III"
  Output: 3
  Example 2:

  Input: "IV"
  Output: 4
  Example 3:

  Input: "IX"
  Output: 9
  Example 4:

  Input: "LVIII"
  Output: 58
  Explanation: L = 50, V= 5, III = 3.
  Example 5:

  Input: "MCMXCIV"
  Output: 1994
  Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

#ifdef DEBUG

#include <string>
#include <iostream>

#endif  // DEBUG

class Solution {
 public:
  int romanToInt(const std::string& s) {
    int value = 0;
    auto p = s.c_str();

    while (*p == 'M') {
      value += 1000;
      ++p;
    }

    if (*p == 'C' && *(p + 1) == 'M') {
      value += 900;
      p += 2;
    } else if (*p == 'C' && *(p + 1) == 'D') {
      value += 400;
      p += 2;
    } else if (*p == 'D') {
      value += 500;
      ++p;
    }

    while (*p == 'C') {
      value += 100;
      ++p;
    }

    if (*p == 'X' && *(p + 1) == 'C') {
      value += 90;
      p += 2;
    } else if (*p == 'X' && *(p + 1) == 'L') {
      value += 40;
      p += 2;
    } else if (*p == 'L') {
      value += 50;
      ++p;
    }

    while (*p == 'X') {
      value += 10;
      ++p;
    }

    if (*p == 'I' && *(p + 1) == 'X') {
      value += 9;
      p += 2;
    } else if (*p == 'I' && *(p + 1) == 'V') {
      value += 4;
      p += 2;
    } else if (*p == 'V') {
      value += 5;
      ++p;
    }

    while (*p == 'I') {
      ++value;
      ++p;
    }

    return value;
  }
};

#ifdef DEBUG

int main(int argc, char** argv) {
  Solution s;
  std::cout << s.romanToInt("III") << std::endl;
  std::cout << s.romanToInt("IV") << std::endl;
  std::cout << s.romanToInt("LVIII") << std::endl;
  std::cout << s.romanToInt("MCMXCIV") << std::endl;
  return 0;
}

#endif  // DEBUG
