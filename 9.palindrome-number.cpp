// Copyright 2019 chengenbao. All Rights Reserved.

/*
  Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

  Example 1:

  Input: 121
  Output: true
  Example 2:

  Input: -121
  Output: false
  Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
  Example 3:

  Input: 10
  Output: false
  Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
  Follow up:

  Coud you solve it without converting the integer to a string?
*/

#ifdef DEBUG

#include <iostream>

#endif  // DEBUG

class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }

    if (x == 0) {
      return true;
    }

    int a = 0;
    int t = x;
    while (x) {
      if (a > INT_MAX / 10) {
        return false;
      }
      a *= 10;
      a += x % 10;
      x /= 10;
    }

    return a == t;
  }
};

#ifdef DEBUG

int main(int argc, char** argv) {
  Solution s;
  std::cout << s.isPalindrome(121) << std::endl;
  std::cout << s.isPalindrome(-121) << std::endl;
  std::cout << s.isPalindrome(10) << std::endl;
  return 0;
}

#endif  // DEBUG
