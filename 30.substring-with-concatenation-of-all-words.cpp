/*
You are given a string, s, and a list of words, words, that are all of the same
length. Find all starting indices of substring(s) in s that is a concatenation
of each word in words exactly once and without any intervening characters.



Example 1:

Input:
  s = "barfoothefoobarman",
  words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar"
respectively. The output order does not matter, returning [9,0] is fine too.
Example 2:

Input:
  s = "wordgoodgoodgoodbestword",
  words = ["word","good","best","word"]
Output: []
*/

// @lc code=start

#ifdef DEBUG

#include "common.h"
#include <iostream>
#include <unordered_map>
#include <vector>

#endif  // DEBUG

class Solution {
 public:
  std::vector<int> findSubstring(const std::string& s,
                                 const std::vector<std::string>& words) {
    std::vector<int> ret;

    if (s.empty() || words.empty()) {
      return ret;
    }

    int s_len = s.size();
    int w_len = words[0].size();
    int all_len = w_len * words.size();

    std::unordered_map<std::string, int> counter;
    for (auto& word : words) {
      ++counter[word];
    }

    for (int i = 0; i <= s_len - all_len; ++i) {
      std::unordered_map<std::string, int> tmp;
      int j = 0;
      for (; j < all_len; j += w_len) {
        auto sub = s.substr(i + j, w_len);
        if (counter.find(sub) == counter.end()) {
          break;
        }

        ++tmp[sub];
        if (tmp[sub] > counter[sub]) {
          break;
        }
      }
      if (j == all_len) {
        ret.push_back(i);
      }
    }

    return ret;
  }
};

#ifdef DEBUG

int main(int argc, char** argv) {
  Solution s;
  PrintVector(s.findSubstring("barfoothefoobarman", {"foo", "bar"}));
  PrintVector(s.findSubstring("wordgoodgoodgoodbestword",
                              {"word", "good", "best", "word"}));
  return 0;
}

#endif  // DEBUG

// @lc code=end
