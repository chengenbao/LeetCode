// Copyright 2019 chengenbao. All Rights Reserved.

/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle
is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question
to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty
string. This is consistent to C's strstr() and Java's indexOf().
*/

// @lc code=start

#ifdef DEBUG

#include <stdint.h>

#include <iostream>
#include <string>

#include "common.h"

#endif  // DEBUG

class Solution {
 public:
  int strStr(const std::string& haystack, const std::string& needle) {
    if (haystack.empty()) {
      if (needle.empty()) {
        return 0;
      }
      return -1;
    }

    if (needle.empty()) {
      return 0;
    }

    for (size_t i = 0; i + needle.size() <= haystack.size(); ++i) {
      size_t j = 0;
      for (; j < needle.size(); ++j) {
        if (haystack[i + j] != needle[j]) {
          break;
        }
      }
      if (j == needle.size()) {
        return i;
      }
    }

    return -1;
  }
};

#ifdef DEBUG

int main(int argc, char** argv) {
  Solution s;
  std::cout << s.strStr("hello", "ll") << std::endl;
  std::cout << s.strStr("aaaaa", "bba") << std::endl;
  return 0;
}
#endif  // DEBUG
// @lc code=end
