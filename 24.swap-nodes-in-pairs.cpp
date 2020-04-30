// Copyright 2019 chengenbao. All Rights Reserved.

/*
Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be
changed.



Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
*/

#ifdef DEBUG

#include <iostream>

#include "common.h"

#endif  // DEBUG

class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    // Swap head and next
    ListNode* next = head;
    head = next->next;
    next->next = head->next;
    head->next = next;

    while (next->next != nullptr && next->next->next != nullptr) {
      ListNode* tmp = next->next;
      next->next = tmp->next;
      tmp->next = next->next->next;
      next->next->next = tmp;

      next = tmp;
    }

    return head;
  }
};

#ifdef DEBUG

int main(int argc, char** argv) {
  auto list = ConstructList({1, 2, 3, 4});
  Solution s;
  PrintList(s.swapPairs(list));

  return 0;
}
#endif  // DEBUG

// @lc code=end
