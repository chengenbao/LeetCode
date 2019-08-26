// Copyright 2019 chengenbao. All Rights Reserved.

/*
  Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

  '.' Matches any single character.
  '*' Matches zero or more of the preceding element.
  The matching should cover the entire input string (not partial).

  Note:

  s could be empty and contains only lowercase letters a-z.
  p could be empty and contains only lowercase letters a-z, and characters like . or *.
  Example 1:

  Input:
  s = "aa"
  p = "a"
  Output: false
  Explanation: "a" does not match the entire string "aa".
  Example 2:

  Input:
  s = "aa"
  p = "a*"
  Output: true
  Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
  Example 3:

  Input:
  s = "ab"
  p = ".*"
  Output: true
  Explanation: ".*" means "zero or more (*) of any character (.)".
  Example 4:

  Input:
  s = "aab"
  p = "c*a*b"
  Output: true
  Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
  Example 5:

  Input:
  s = "mississippi"
  p = "mis*is*p*."
  Output: false
*/

#ifdef DEBUG

#include <iostream>
#include <string>

#endif  // DEBUG

class Solution {
 public:
  bool isMatch(const std::string& s, const std::string& p) {
    return IsMatch(s.c_str(), p.c_str());
  }

 private:
  bool IsMatch(const char* p, const char* q) {
    if (!*p && !*q) {
      return true;
    }

    while (*p && *q && *(q + 1) != '*' && (*p == *q || *q == '.')) {
      ++p;
      ++q;
    }

    if (!*p && !*q) {
      return true;
    }

    if (!*p && *q) {
      if (*(q + 1) != '*') {
        return false;
      }
      return isMatch(p, q + 2);
    }

    if (*p && !*q) {
      return false;
    }

    if (*p && *q && *(q + 1) != '*') {
      if (*p != *q) {
        return false;
      } else {
        return isMatch(p + 1, q + 1);
      }
    } else {  // *(q + 1) == '*'
      if (isMatch(p, q + 2)) {
        return true;
      }
      while (*p && (*p == *q || *q == '.')) {
        if (isMatch(p + 1, q + 2)) {
          return true;
        }
        ++p;
      }
    }

    return false;
  }
};


#ifdef DEBUG

int main(int argc, char** argv) {
  Solution s;
  std::cout << s.isMatch("aa", "a") << std::endl;
  std::cout << s.isMatch("abc", "abc") << std::endl;
  std::cout << s.isMatch("aa", "a*") << std::endl;
  std::cout << s.isMatch("ab", ".*") << std::endl;
  std::cout << s.isMatch("aab", "c*a*b") << std::endl;
  std::cout << s.isMatch("mississippi", "mis*is*p*.") << std::endl;
  std::cout << s.isMatch("ab", ".*c") << std::endl;
  return 0;
}

#endif  // DEBUG
