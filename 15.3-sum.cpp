// Copyright 2019 chengenbao. All Rights Reserved.

/*
  Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

  Note:

  The solution set must not contain duplicate triplets.

  Example:

  Given array nums = [-1, 0, 1, 2, -1, -4],

  A solution set is:
  [
  [-1, 0, 1],
  [-1, -1, 2]
  ]
*/

#ifdef DEBUG

#include <vector>
#include <iostream>

#endif  // DEBUG

#include <algorithm>

class Solution {
 public:
  std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {  // NOLINT
    std::vector<std::vector<int>> res;

    std::sort(nums.begin(), nums.end());
    for (size_t i = 0; i < nums.size(); ++i) {
      int target = -nums[i];
      int front = i + 1;
      int end = nums.size() - 1;
      while (front < end) {
        int sum = nums[front] + nums[end];
        if (sum < target) {
          ++front;
        } else if (sum > target) {
          --end;
        } else {
          std::vector<int> triplet(3);
          triplet[0] = nums[i];
          triplet[1] = nums[front];
          triplet[2] = nums[end];
          res.push_back(triplet);

          while (front < end && nums[front] == triplet[1]) {
            ++front;
          }

          while (front < end && nums[end] == triplet[2]) {
            --end;
          }
        }
      }

      while (i + 1 < nums.size() && nums[i + 1] == nums[i]) {
        ++i;
      }
    }

    return res;
  }
};


#ifdef DEBUG


void PrintResult(const std::vector<std::vector<int>>& result) {
  for (auto& r : result) {
    for (auto v : r) {
      std::cout << v << " ";
    }
    std::cout << std::endl;
  }
}

int main(int argc, char** argv) {
  Solution s;

  std::vector<int> vec({-1, 0, 1, 2, -1, -4});
  PrintResult(s.threeSum(vec));

  return 0;
}

#endif  // DEBUG
