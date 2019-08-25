// Copyright 2019 chengenbao. All Rights Reserved.

/*
  Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

  Example 1:

  Input: "babad"
  Output: "bab"
  Note: "aba" is also a valid answer.
  Example 2:

  Input: "cbbd"
  Output: "bb"
*/

#ifdef DEBUG

#include <string>
#include <iostream>

#endif  // DEBUG

#define MAX_LEN 1000

class Solution {
 public:
  std::string longestPalindrome(const std::string& s) {
    if (s.empty()) {
      return s;
    }

    bool palin_len[MAX_LEN][MAX_LEN];
    int len = s.size();
    for (int i = 0; i < len; ++i) {
      for (int j = i; j < len; ++j) {
        palin_len[i][j] = false;
      }
      palin_len[i][i] = true;
    }

    for (int i = len - 2; i >= 0; --i) {
      if (s[i] == s[i + 1]) {
        palin_len[i][i + 1] = true;
      }

      for (int j = i + 2; j < len; ++j) {
        if (palin_len[i + 1][j - 1] && s[i] == s[j]) {
          palin_len[i][j] = true;
        }
      }
    }

    int index = 0;
    int mlen = 0;
    for (int i = 0; i < len; ++i) {
      int j = len - 1;
      while (j >= i && !palin_len[i][j]) {
        --j;
      }
      if (j - i + 1 > mlen) {
        index = i;
        mlen = j - i + 1;
      }
    }

    return s.substr(index, mlen);
  }
};

#ifdef DEBUG

int main(int argc, char** argv) {
  Solution s;
  std::cout << s.longestPalindrome("babad") << std::endl;
  std::cout << s.longestPalindrome("cbbd") << std::endl;
  std::cout << s.longestPalindrome("bb") << std::endl;
  std::cout << s.longestPalindrome("ccc") << std::endl;
  std::cout << s.longestPalindrome("aaaa") << std::endl;
  return 0;
}
#endif  // DEBUG
