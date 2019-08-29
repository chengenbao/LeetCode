// Copyright 2019 chengenbao. All Rights Reserved.

/*
  Write a function to find the longest common prefix string amongst an array of strings.

  If there is no common prefix, return an empty string "".

  Example 1:

  Input: ["flower","flow","flight"]
  Output: "fl"
  Example 2:

  Input: ["dog","racecar","car"]
  Output: ""
  Explanation: There is no common prefix among the input strings.
  Note:

  All given inputs are in lowercase letters a-z.
*/

#ifdef DEBUG

#include <string>
#include <vector>
#include <iostream>

#endif  // DEBUG


class Solution {
 public:
  std::string longestCommonPrefix(const std::vector<std::string>& strs) {
    std::string prefix;
    if (strs.empty()) {
      return prefix;
    }

    size_t i = 0;
    while (true) {
      auto c = strs[0][i];
      for (auto& str : strs) {
        if (i >= str.size() || str[i] != c) {
          return prefix;
        }
      }
      prefix.push_back(c);
      ++i;
    }

    return prefix;
  }
};

#ifdef DEBUG

int main(int argc, char** argv) {
  Solution s;
  std::cout << s.longestCommonPrefix({"flower", "flow", "flight"}) << std::endl;
  std::cout << s.longestCommonPrefix({"dog", "racecar", "car"}) << std::endl;
  return 0;
}

#endif  // DEBUG
