// Copyright 2019 chengenbao. All Rights Reserved.

/*
  You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

  You may assume the two numbers do not contain any leading zero, except the number 0 itself.

  Example:

  Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
  Output: 7 -> 0 -> 8
  Explanation: 342 + 465 = 807.
*/

#ifdef DEBUG

#include <iostream>
#include <vector>

#include "common.h"

#endif  // DEBUG

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* p = l1;
    ListNode* q = l2;
    ListNode* prev = nullptr;
    int r = 0;
    while (p && q) {
      r += p->val + q->val;
      if (r > 9) {
        p->val = r - 10;
        r = 1;
      } else {
        p->val = r;
        r = 0;
      }
      prev = p;
      p = p->next;
      q = q->next;
    }
    prev->next = p ? p : q;
    p = prev->next;
    while (r && p) {
      r += p->val;
      if (r > 9) {
        p->val = r - 10;
        r = 1;
      } else {
        p->val = r;
        r = 0;
      }
      prev = p;
      p = p->next;
    }

    if (r) {
      prev->next = l2;
      prev->next->val = r;
      prev->next->next = nullptr;
    }

    return l1;
  }
};


#ifdef DEBUG

int main(int argc, char** argv) {
  Solution s;
  PrintList(s.addTwoNumbers(ConstructList({2, 4, 3}),
                            ConstructList({5, 6, 4})));
  return 0;
}

#endif  // DEBUG
