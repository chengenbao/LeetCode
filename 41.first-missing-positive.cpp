/*
Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3
Example 2:

Input: [3,4,-1,1]
Output: 2
Example 3:

Input: [7,8,9,11,12]
Output: 1
Note:

Your algorithm should run in O(n) time and uses constant extra space.
*/

// @lc code=start

#ifdef DEBUG

#include <iostream>

#include "common.h"

#endif  // DEBUG

class Solution {
 public:
  int firstMissingPositive(std::vector<int>& nums) {
    int size = nums.size();
    for (int i = 0; i < size; ++i) {
      while (nums[i] > 0 && nums[i] <= size && nums[i] != (i + 1)) {
        // Swap nums[i] and nums[nums[i] - 1]
        if (nums[i] != nums[nums[i] - 1]) {
          int tmp = nums[i];
          nums[i] = nums[tmp - 1];
          nums[tmp - 1] = tmp;
        } else {
          break;
        }
      }
    }

    for (int i = 0; i < size; ++i) {
      if (nums[i] != (i + 1)) {
        return i + 1;
      }
    }

    return size + 1;
  }
};

#ifdef DEBUG

int main(int argc, char** argv) {
  Solution s;

  std::vector<int> v = {1, 2, 0};
  std::cout << s.firstMissingPositive(v) << std::endl;
  v = {3, 4, -1, 1};
  std::cout << s.firstMissingPositive(v) << std::endl;
  v = {7, 8, 9, 11, 12};
  std::cout << s.firstMissingPositive(v) << std::endl;
  v = {1, 1};
  std::cout << s.firstMissingPositive(v) << std::endl;
  v = {2, 1};
  std::cout << s.firstMissingPositive(v) << std::endl;
  v = {4, 1, 2, 3};
  std::cout << s.firstMissingPositive(v) << std::endl;

  return 0;
}
#endif  // DEBUG

// @lc code=end
