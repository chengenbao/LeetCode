// Copyright 2019 chengenbao. All Rights Reserved.

/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 * Example 1:
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 *
 * Example 2:
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 *
 */

// @lc code=start

#ifdef DEBUG

#include <iostream>
#include <vector>

#include "common.h"

#endif  // DEBUG

class Solution {
 public:
  std::vector<int> searchRange(const std::vector<int>& nums, int target) {
    std::vector<int> range(2, -1);
    if (!nums.empty()) {
      auto low = FindLess(nums, target);
      auto high = FindGreater(nums, target);
      range[0] = (low + 1 < nums.size() && nums[low + 1] == target) ? (low + 1) : -1;
      range[1] = (high - 1 >= 0 && nums[high - 1] == target) ? (high - 1) : -1;
    }

    return range;
  }

 private:
  int FindLess(const std::vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (nums[mid] >= target) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return high;
  }

  int FindGreater(const std::vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (nums[mid] <= target) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return low;
  }
};

#ifdef DEBUG

int main(int argc, char** argv) {
  Solution s;
  PrintVector(s.searchRange({5, 7, 7, 8, 8, 10}, 8));
  PrintVector(s.searchRange({5, 7, 7, 8, 8, 10}, 6));
  PrintVector(s.searchRange({1}, 0));
  return 0;
}

#endif  // DEBUG

// @lc code=end
