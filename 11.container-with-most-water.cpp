// Copyright 2019 chengenbao. All Rights Reserved.

/*
  Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

  Note: You may not slant the container and n is at least 2.

  The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

  Example:

  Input: [1,8,6,2,5,4,8,3,7]
  Output: 49
*/

#ifdef DEBUG

#include <vector>
#include <iostream>

#endif  // DEBUG

class Solution {
 public:
  int maxArea(const std::vector<int>& height) {
    int water = 0;
    int i = 0, j = height.size() - 1;
    while (i < j) {
        int h = height[i] > height[j] ? height[j] : height[i];
        water = water > (j - i) * h ? water : (j - i) * h;
        while (height[i] <= h && i < j) i++;
        while (height[j] <= h && i < j) j--;
    }
    return water;
  }
};

#ifdef DEBUG

int main(int argc, char** argv) {
  Solution s;
  std::cout << s.maxArea({1, 8, 6, 2, 5, 4, 8, 3, 7}) << std::endl;
  std::cout << s.maxArea({2, 3, 4, 5, 18, 17, 6}) << std::endl;
  return 0;
}

#endif  // DEBUG
