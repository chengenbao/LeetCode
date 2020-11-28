/*

Implement next permutation, which rearranges numbers into the lexicographically
next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible
order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding
outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

*/

// @lc code=start

#ifdef DEBUG

#include <iostream>
#include <vector>

#include "common.h"

#endif  // DEBUG

#include <algorithm>

class Solution {
 public:
  void nextPermutation(std::vector<int>& nums) {
    int sz = nums.size();
    if (sz < 2) {
      return;
    }

    int i = sz - 2;
    int max = nums.back();
    for (; i >= 0; --i) {
      // There is some one bigger than current value
      if (nums[i] < max) {
        break;
      } else {
        max = nums[i];
      }
    }

    // In ascending order, reverse
    if (i < 0) {
      for (int j = 0; j < sz / 2; ++j) {
        std::swap(nums[j], nums[sz - j - 1]);
      }
      return;
    }

    int min = max + 1;
    int min_j = 0;
    for (int j = i + 1; j < sz; ++j) {
      if (nums[j] > nums[i] && nums[j] < min) {
        min = nums[j];
        min_j = j;
      }
    }

    // Swap i and min_j
    std::swap(nums[i], nums[min_j]);

    // Rearrange nums[i + 1 ... end] to min
    std::sort(nums.data() + i + 1, nums.data() + sz);
  }
};

#ifdef DEBUG

int main(int argc, char** argv) {
  Solution s;

  std::vector<int> v = {1, 2, 3};
  s.nextPermutation(v);
  PrintVector(v);

  v = {3, 2, 1};
  s.nextPermutation(v);
  PrintVector(v);

  v = {1, 1, 5};
  s.nextPermutation(v);
  PrintVector(v);

  v = {1, 4, 3, 2};
  s.nextPermutation(v);
  PrintVector(v);

  return 0;
}

#endif  // DEBUG

// @lc code=end