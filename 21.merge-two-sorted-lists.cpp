// Copyright 2019 chengenbao. All Rights Reserved.

/*
  Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

  Example:

  Input: 1->2->4, 1->3->4
  Output: 1->1->2->3->4->4
*/

#ifdef DEBUG

#include "common.h"

#endif  // DEBUG

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) {
      return l2;
    }

    if (l2 == nullptr) {
      return l1;
    }

    ListNode* l3 = nullptr;
    ListNode* node = nullptr;
    while (l1 && l2) {
      if (l1->val <= l2->val) {
        if (!l3) {
          l3 = l1;
        } else {
          node->next = l1;
        }
        node = l1;
        l1 = l1->next;
      } else {
        if (!l3) {
          l3 = l2;
        } else {
          node->next = l2;
        }
        node = l2;
        l2 = l2->next;
      }
    }

    if (l1) {
      node->next = l1;
    } else if (l2) {
      node->next = l2;
    }

    return l3;
  }
};


#ifdef DEBUG

int main(int argc, char** argv) {
  Solution s;
  PrintList(s.mergeTwoLists(ConstructList({1, 2, 4}),
                            ConstructList({1, 3, 4})));
  return 0;
}

#endif  // DEBUG
