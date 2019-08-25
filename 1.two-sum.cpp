// Copyright 2019 chengenbao. All Rights Reserved.

/*
  Given an array of integers, return indices of the two numbers such that they add up to a specific target.

  You may assume that each input would have exactly one solution, and you may not use the same element twice.

  Example:

  Given nums = [2, 7, 11, 15], target = 9,

  Because nums[0] + nums[1] = 2 + 7 = 9,
  return [0, 1].
*/

#ifdef DEBUG
#include <iostream>
#endif  // DEBUG

#include <vector>

class Solution {
 public:
  std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    std::vector<int> result(2);
    for (int i = 0; i < static_cast<int>(nums.size()) - 1; ++i) {
      for (int j = i + 1; j < static_cast<int>(nums.size()); ++j) {
        if (nums[i] + nums[j] == target) {
          result[0] = i;
          result[1] = j;
        }
      }
    }
    return result;
  }
};


#ifdef DEBUG

inline void PrintResult(const std::vector<int>& result) {
  std::cout << "[" <<  result[0] << ", " << result[1] << "]" << std::endl;
}

int main(int argc, char** argv) {
  Solution s;
  PrintResult(s.twoSum({2, 7, 11, 15}, 9));
  return 0;
}

#endif  // DEBUG
