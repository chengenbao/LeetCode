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
  Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

  Example 1:

  Input: 3
  Output: "III"
  Example 2:

  Input: 4
  Output: "IV"
  Example 3:

  Input: 9
  Output: "IX"
  Example 4:

  Input: 58
  Output: "LVIII"
  Explanation: L = 50, V = 5, III = 3.
  Example 5:

  Input: 1994
  Output: "MCMXCIV"
  Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

#ifdef DEBUG

#include <string>
#include <iostream>

#endif  // DEBUG

class Solution {
 public:
  std::string intToRoman(int num) {
    std::string result;

    while (num >= 1000) {
      result.append("M");
      num -= 1000;
    }

    if (num >= 900) {
      result.append("CM");
      num -= 900;
    }

    if (num >= 500) {
      result.append("D");
      num -= 500;
    }

    if (num >= 400) {
      result.append("CD");
      num -= 400;
    }

    while (num >= 100) {
      result.append("C");
      num -= 100;
    }

    if (num >= 90) {
      result.append("XC");
      num -= 90;
    }

    if (num >= 50) {
      result.append("L");
      num -= 50;
    }

    if (num >= 40) {
      result.append("XL");
      num -= 40;
    }

    while (num >= 10) {
      result.append("X");
      num -= 10;
    }

    if (num >= 9) {
      result.append("IX");
      num -= 9;
    }

    if (num >= 5) {
      result.append("V");
      num -= 5;
    }

    if (num >= 4) {
      result.append("IV");
      num -= 4;
    }

    while (num > 0) {
      result.append("I");
      --num;
    }

    return result;
  }
};

#ifdef DEBUG

int main(int argc, char** argv) {
  Solution s;
  std::cout << s.intToRoman(3) << std::endl;
  std::cout << s.intToRoman(4) << std::endl;
  std::cout << s.intToRoman(9) << std::endl;
  std::cout << s.intToRoman(58) << std::endl;
  std::cout << s.intToRoman(1994) << std::endl;
  return 0;
}

#endif  // DEBUG
