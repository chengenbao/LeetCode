/*
Given two integers dividend and divisor, divide two integers without using
multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero, which means losing its
fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = truncate(3.33333..) = 3.
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = truncate(-2.33333..) = -2.
Note:

Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within
the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this
problem, assume that your function returns 231 − 1 when the division result
overflows.
*/

// @lc code=start

#ifdef DEBUG

#include <iostream>

#include "common.h"

#endif  // DEBUG

class Solution {
 public:
  int divide(int dividend, int divisor) {
    if (dividend == 0) {
      return 0;
    }

    bool neg = (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0);
    long dd = dividend;
    long ds = divisor;
    dd = (dd > 0) ? dd : -dd;
    ds = (ds > 0) ? ds : -ds;

    long i = dd;
    if (ds != 1) {
      long rem = 0;
      i = devide_pos(dd, ds, &rem);
    }
    if (!neg && i > INT_MAX) {
      i = INT_MAX;
    }

    if (neg) {
      i = -i;
    }

    return static_cast<int>(i);
  }

 private:
  long devide_pos(long dividend, long divisor, long* rem) {
    if (dividend < divisor) {
      *rem = dividend;
      return 0;
    }

    long rem1 = 0;
    long half = dividend >> 1;
    long ret = (devide_pos(half, divisor, &rem1) << 1);
    *rem = rem1 << 1;
    *rem += dividend - half - half;
    if (*rem >= divisor) {
      *rem -= divisor;
      ++ret;
    }
    return ret;
  }
};

#ifdef DEBUG

int main(int argc, char** argv) {
  Solution s;
  std::cout << s.divide(10, 3) << std::endl;
  std::cout << s.divide(7, -3) << std::endl;
  return 0;
}

#endif  // DEBUG

// @lc code=end
