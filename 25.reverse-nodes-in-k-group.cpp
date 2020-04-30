// Copyright 2019 chengenbao. All Rights Reserved.

/*
Given a linked list, reverse the nodes of a linked list k at a time and return
its modified list.

k is a positive integer and is less than or equal to the length of the linked
list. If the number of nodes is not a multiple of k then left-out nodes in the
end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be
changed.
*/

#ifdef DEBUG

#include <iostream>

#include "common.h"

#endif  // DEBUG

class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == nullptr || k == 1) {
      return head;
    }

    ListNode* next = head;
    head = nullptr;
    while (next != nullptr) {
      auto end = next->next;
      int i = k;
      if (head == nullptr) {
        --i;
      }

      for (; i > 0 && end != nullptr; --i) {
        end = end->next;
      }

      if (i > 0) {
        break;
      }

      if (head == nullptr) {
        head = next;
        auto p = next->next;
        for (int j = 0; j < k - 1; ++j) {
          next->next = p->next;
          p->next = head;
          head = p;
          p = next->next;
        }
      } else {
        auto p = next->next;
        auto q = p->next;
        for (int j = 0; j < k - 1; ++j) {
          p->next = q->next;
          q->next = next->next;
          next->next = q;
          q = p->next;
        }
        next = p;
      }
    }

    return head;
  }
};

#ifdef DEBUG

int main(int argc, char** argv) {
  auto l = ConstructList({1, 2, 3, 4, 5});

  Solution s;
  PrintList(s.reverseKGroup(l, 3));

  l = ConstructList({1, 2, 3, 4, 5, 6});
  PrintList(s.reverseKGroup(l, 3));

  return 0;
}

#endif  // DEBUG

// @lc code=end
