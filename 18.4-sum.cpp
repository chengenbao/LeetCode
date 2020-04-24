// Copyright 2019 chengenbao. All Rights Reserved.

/*
  Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

  Note:

  The solution set must not contain duplicate quadruplets.

  Example:

  Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

  A solution set is:
  [
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
  ]
*/

#ifdef DEBUG

#include <vector>
#include <iostream>

#endif  // DEBUG

#include <algorithm>

class Solution {
 public:
  std::vector<std::vector<int>> fourSum(
      std::vector<int>& nums, int target) {  // NOLINT
    std::vector<std::vector<int>> result;
    std::sort(nums.begin(), nums.end());

    for (size_t i = 0; i < nums.size(); ++i) {
      for (size_t j = i + 1; j < nums.size(); ++j) {
        int t = target - nums[i] - nums[j];
        int front = j + 1;
        int end = nums.size() - 1;
        while (front < end) {
          int s = nums[front] + nums[end];
          if (s < t) {
            ++front;
          } else if (s > t) {
            --end;
          } else {
            result.push_back({nums[i], nums[j], nums[front], nums[end]});
            ++front;
            --end;
            while (front < end && nums[front] == result.back()[2]) {
              ++front;
            }

            while (front < end && nums[end - 1] == result.back().back()) {
              --end;
            }
          }
        }

        while (j + 1 < nums.size() && nums[j + 1] == nums[j]) {
          ++j;
        }
      }
      while (i + 1 < nums.size() && nums[i + 1] == nums[i]) {
        ++i;
      }
    }
    return result;
  }
};


#ifdef DEBUG

void PrintResult(const std::vector<std::vector<int>>& rows) {
  for (auto& row : rows) {
    for (auto v : row) {
      std::cout << v << " ";
    }
    std::cout << std::endl;
  }
}

int main(int argc, char** argv) {
  Solution s;
  std::vector<int> values = {1, 0, -1, 0, -2, 2};
  PrintResult(s.fourSum(values, 0));
  return 0;
}

#endif  // DEBUG
