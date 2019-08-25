// Copyright 2019 chengenbao. All Rights Reserved.

/*
  Given a string, find the length of the longest substring without repeating characters.

  Example 1:

  Input: "abcabcbb"
  Output: 3
  Explanation: The answer is "abc", with the length of 3.
  Example 2:

  Input: "bbbbb"
  Output: 1
  Explanation: The answer is "b", with the length of 1.
  Example 3:

  Input: "pwwkew"
  Output: 3
  Explanation: The answer is "wke", with the length of 3.
  Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#ifdef DEBUG

#include <vector>
#include <string>
#include <iostream>

#endif  // DEBUG

class Solution {
 public:
  int lengthOfLongestSubstring(const std::string& s) {
    std::vector<int> counter(128, 0);
    int i = 0;
    int j = 0;
    int max = 0;
    int sz = s.size();
    while (j < sz) {
      while (j < sz && counter[s[j]] == 0) {
        counter[s[j++]] = 1;
      }
      max = (max > j - i) ? max : j - i;
      if (j < sz) {
        while (s[i] != s[j]) {
          counter[s[i++]] = 0;
        }
        counter[s[i++]] = 0;
      }
    }

    return max;
  }
};

#ifdef DEBUG

int main(int argc, char** argv) {
  Solution s;
  std::cout << s.lengthOfLongestSubstring("abcabcbb") << std::endl;
  std::cout << s.lengthOfLongestSubstring("bbbbb") << std::endl;
  std::cout << s.lengthOfLongestSubstring("pwwkew") << std::endl;
  return 0;
}

#endif  // DEBUG
