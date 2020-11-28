// Copyright 2019 chengenbao. All Rights Reserved.

/*

You are given an integer array nums sorted in ascending order, and an integer
target.

Suppose that nums is rotated at some pivot unknown to you beforehand (i.e.,
[0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

If target is found in the array return its index, otherwise, return -1.



Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1


Constraints:

1 <= nums.length <= 5000
-10^4 <= nums[i] <= 10^4
All values of nums are unique.
nums is guranteed to be rotated at some pivot.
-10^4 <= target <= 10^4

*/

// @lc code=start

#ifdef DEBUG

#include <iostream>
#include <vector>

#include "common.h"

#endif  // DEBUG

class Solution {
 public:
  int search(const std::vector<int>& nums, int target) {
    return search(nums, 0, static_cast<int>(nums.size()) - 1, target);
  }

 private:
  int search(const std::vector<int>& nums, int low, int high, int target) {
    if (low > high) {
      return -1;
    }

    if (low == high) {
      return (target == nums[low]) ? low : -1;
    }

    int mid = (low + high) / 2;
    if (nums[low] <= nums[mid]) {  // [low, mid] in order
      if (target >= nums[low] && target <= nums[mid]) {
        return bsearch(nums, low, mid, target);
      }

      return search(nums, mid + 1, high, target);
    } else {  // [mid + 1, high] in order
      if (target >= nums[mid + 1] && target <= nums[high]) {
        return bsearch(nums, mid + 1, high, target);
      }

      return search(nums, low, mid, target);
    }
  }

  int bsearch(const std::vector<int>& nums, int low, int high, int target) {
    while (low <= high) {
      int mid = (low + high) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] > target) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    return -1;
  }
};

#ifdef DEBUG

int main(int argc, char** argv) {
  Solution s;
  std::cout << s.search({4, 5, 6, 7, 0, 1, 2}, 0) << std::endl;
  std::cout << s.search({4, 5, 6, 7, 0, 1, 2}, 3) << std::endl;
  std::cout << s.search({1}, 0) << std::endl;
  return 0;
}

#endif  // DEBUG

// @lc code=end

