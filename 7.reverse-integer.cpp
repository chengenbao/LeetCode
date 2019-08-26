// Copyright 2019 chengenbao. All Rights Reserved.

/*
  Given a 32-bit signed integer, reverse digits of an integer.

  Example 1:

  Input: 123
  Output: 321
  Example 2:

  Input: -123
  Output: -321
  Example 3:

  Input: 120
  Output: 21
  Note:
  Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

#ifdef DEBUG

#include <iostream>

#endif  // DEBUG

class Solution {
 public:
  int reverse(int x) {
    int r = 0;
    int s = 1;

    if (x == 0) {
      return r;
    }

    if (x == INT_MIN) {
      return 0;
    }

    if (x < 0) {
      s = 0;
      x = -x;
    }

    while (x != 0) {
      if (r > INT_MAX / 10) {
        return 0;
      }

      r *= 10;
      r += x % 10;
      x /= 10;
    }

    return (!s) ? -r : r;
  }
};

#ifdef DEBUG

int main(int argc, char** argv) {
  Solution s;
  std::cout << s.reverse(123) << std::endl;
  std::cout << s.reverse(-123) << std::endl;
  std::cout << s.reverse(120) << std::endl;
  std::cout << s.reverse(1534236469) << std::endl;
  std::cout << s.reverse(-2147483648) << std::endl;
  return 0;
}

#endif  // DEBUG
