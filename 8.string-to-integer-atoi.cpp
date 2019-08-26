// Copyright 2019 chengenbao. All Rights Reserved.

/*
  Implement atoi which converts a string to an integer.

  The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

  The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

  If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

  If no valid conversion could be performed, a zero value is returned.

  Note:

  Only the space character ' ' is considered as whitespace character.
  Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
  Example 1:

  Input: "42"
  Output: 42
  Example 2:

  Input: "   -42"
  Output: -42
  Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.
  Example 3:

  Input: "4193 with words"
  Output: 4193
  Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
  Example 4:

  Input: "words and 987"
  Output: 0
  Explanation: The first non-whitespace character is 'w', which is not a numerical
             digit or a +/- sign. Therefore no valid conversion could be performed.
  Example 5:

  Input: "-91283472332"
  Output: -2147483648
  Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
  Thefore INT_MIN (−2^31) is returned.
*/

#ifdef DEBUG

#include <string>
#include <iostream>

#endif  // DEBUG

class Solution {
 public:
  int myAtoi(const std::string& str) {
    auto p = str.c_str();

    // skip whitespace
    while (*p == ' ') {
      ++p;
    }

    int s = 1;  // +
    if (*p == '+') {
      ++p;
    } else if (*p == '-') {
      s = 0;
      ++p;
    }

    // skip white space
    if (*p < '0' || *p > '9') {
      return 0;
    }

    int r = 0;
    while (*p >= '0' && *p <= '9') {
      if (r > INT_MAX / 10) {
        return s ? INT_MAX : INT_MIN;
      }

      int n = *p - '0';
      if (r == INT_MAX / 10) {
        int m = INT_MAX % 10;
        if (!s) {
          ++m;
        }
        if (n >= m) {
          return s ? INT_MAX : INT_MIN;
        }
      }

      r *= 10;
      r += n;
      ++p;
    }

    return s ? r : -r;
  }
};

#ifdef DEBUG

int main(int argc, char** argv) {
  Solution s;
  std::cout << s.myAtoi("") << std::endl;
  std::cout << s.myAtoi("42") << std::endl;
  std::cout << s.myAtoi("-42") << std::endl;
  std::cout << s.myAtoi("4193 with words") << std::endl;
  std::cout << s.myAtoi("words and 987") << std::endl;
  std::cout << s.myAtoi("-91283472332") << std::endl;
  return 0;
}

#endif  // DEBUG
