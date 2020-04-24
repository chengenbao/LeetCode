// Copyright 2019 chengenbao. All Rights Reserved.

/*
  Given a linked list, remove the n-th node from the end of list and return its head.

  Example:

  Given linked list: 1->2->3->4->5, and n = 2.

  After removing the second node from the end, the linked list becomes 1->2->3->5.
  Note:

  Given n will always be valid.

  Follow up:

  Could you do this in one pass?
*/

#ifdef DEBUG

#include <iostream>

#include "common.h"

#endif  // DEBUG

#include <vector>

class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    std::vector<ListNode*> nodes;
    while (head) {
      nodes.push_back(head);
      head = head->next;
    }

    if (n == nodes.size()) {
      if (nodes.size() == 1) {
        return nullptr;
      } else {
        return nodes[1];
      }
    }
    auto prev = nodes[nodes.size() - n - 1];
    prev->next = prev->next->next;
    return nodes[0];
  }
};

#ifdef DEBUG

int main(int argc, char** argv) {
  Solution s;
  PrintList(s.removeNthFromEnd(ConstructList({1, 2, 3, 4, 5}), 2));
  return 0;
}

#endif  // DEBUG
