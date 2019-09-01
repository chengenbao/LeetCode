// Copyright 2019 chengenbao. All Rights Reserved.

/*
  Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

  Example:

  Given array nums = [-1, 2, 1, -4], and target = 1.

  The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

#ifdef DEBUG

#include <vector>
#include <iostream>

#endif  // DEBUG

#include <algorithm>

class Solution {
 public:
  int threeSumClosest(std::vector<int>& nums, int target) {  // NOLINT
    std::sort(nums.begin(), nums.end());

    int sum = nums[0] + nums[1] + nums[2];
    int gap = sum < target ? (target - sum) : (sum - target);
    for (size_t i = 0; i < nums.size(); ++i) {
      int front = i + 1;
      int end = nums.size() - 1;
      int t = target - nums[i];
      while (front < end) {
        int s = nums[front] + nums[end];
        if (s < t) {
          if (target - s - nums[i] < gap) {
            gap = target - s - nums[i];
            sum = s + nums[i];
          }
          ++front;
        } else if (s > t) {
          if (s + nums[i] - target < gap) {
            gap = s + nums[i] - target;
            sum = s + nums[i];
          }
          --end;
        } else {
          return target;
        }
      }

      while (i + i < nums.size() && nums[i + 1] == nums[i]) {
        ++i;
      }
    }

    return sum;
  }
};

#ifdef DEBUG

int main(int argc, char** argv) {
  Solution s;
  std::vector<int> vec({-1, 2, 1, -4});
  std::cout << s.threeSumClosest(vec, 1) << std::endl;
  vec = {1, 2, 5, 10, 11};
  std::cout << s.threeSumClosest(vec, 12) << std::endl;
  return 0;
}

#endif  // DEBUG
