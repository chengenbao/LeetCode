// Copyright 2019 chengenbao. All Rights Reserved.

/*
 There are two sorted arrays nums1 and nums2 of size m and n respectively.

 Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

 You may assume nums1 and nums2 cannot be both empty.

 Example 1:

 nums1 = [1, 3]
 nums2 = [2]

 The median is 2.0
 Example 2:

 nums1 = [1, 2]
 nums2 = [3, 4]

 The median is (2 + 3)/2 = 2.5
*/

#ifdef DEBUG
#include <iostream>
#endif  // DEBUG
#include <vector>

class Solution {
 public:
  double findMedianSortedArrays(const std::vector<int>& nums1,
                                const std::vector<int>& nums2) {
    int len = nums1.size() + nums2.size();
    int mid = len / 2;
    if (len % 2 == 1) {
      ++mid;
    }

    int i_start = 0, i_end = static_cast<int>(nums1.size()) - 1;
    int j_start = 0, j_end = static_cast<int>(nums2.size()) - 1;
    double value = -1;

    while (i_start <= i_end || j_start <= j_end) {
      if (i_start <= i_end) {
        bool ret = Find(nums1, &i_start, &i_end,
                        nums2, &j_start, &j_end,
                        len, mid, &value);
        if (ret) {
          return value;
        }
      }
      if (j_start <= j_end) {
        bool ret = Find(nums2, &j_start, &j_end,
                        nums1, &i_start, &i_end,
                        len, mid, &value);
        if (ret) {
          return value;
       }
      }
    }

    return value;  // No reach
  }

 private:
  size_t FindPos(const std::vector<int>& nums,
                 int start, int end, int value) {
    while (start <= end) {
      int mid = (start + end) / 2;
      if (nums[mid] < value) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }

    return start;
  }

  bool Find(const std::vector<int>& src_nums,
            int* src_start, int* src_end,
            const std::vector<int>& dst_nums,
            int* dst_start, int* dst_end,
            int len, int mid, double* value) {
    int src_mid = (*src_start + *src_end) / 2;
    int pos = FindPos(dst_nums, *dst_start, *dst_end, src_nums[src_mid]);
    if (src_mid + pos + 1 == mid) {
      *value = src_nums[src_mid];
      if (len % 2 == 0) {
        if (src_mid + 1 >= static_cast<int>(src_nums.size())) {
          *value += dst_nums[pos];
        } else if (pos + 1 > static_cast<int>(dst_nums.size())) {
          *value += src_nums[src_mid + 1];
        } else if (src_nums[src_mid + 1] < dst_nums[pos]) {
          *value += src_nums[src_mid + 1];
        } else {
          *value += dst_nums[pos];
        }
        *value /= 2;
      }
      return true;
    } else if (src_mid + pos + 1 < mid) {
      *src_start = src_mid + 1;
      if (pos > *dst_start) {
        *dst_start = pos;
      }
    } else {
      *src_end = src_mid - 1;
      if (pos < *dst_end) {
        *dst_end = pos;
      }
    }

    return false;
  }
};


#ifdef DEBUG

int main(int argc, char** argv) {
  Solution s;
  std::cout << s.findMedianSortedArrays({1, 3}, {2}) << std::endl;
  std::cout << s.findMedianSortedArrays({1, 2}, {3, 4}) << std::endl;
  std::cout << s.findMedianSortedArrays({1, 2, 3, 4}, {3, 4}) << std::endl;
  std::cout << s.findMedianSortedArrays({}, {1}) << std::endl;
  std::cout << s.findMedianSortedArrays({}, {2, 3}) << std::endl;
  std::cout << s.findMedianSortedArrays({1}, {2, 3, 4}) << std::endl;
  std::cout << s.findMedianSortedArrays({1, 2}, {-1, 3}) << std::endl;
  return 0;
}

#endif  // DEBUG
