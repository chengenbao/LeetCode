// Copyright 2019 chengenbao. All Rights Reserved.

#ifndef COMMON_H_
#define COMMON_H_

#include <vector>
#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}  // NOLINT
};

ListNode* ConstructList(const std::vector<int>& vals) {
  ListNode* head = nullptr;
  ListNode* prev = nullptr;
  for (auto& val : vals) {
    auto node = new ListNode(val);
    if (prev != nullptr) {
      prev->next = node;
    }
    if (head == nullptr) {
      head = node;
    }

    prev = node;
  }

  return head;
}

void PrintList(ListNode* node) {
  while (node != nullptr) {
    std::cout << node->val;
    node = node->next;
  }
  std::cout << std::endl;
}

#endif  // COMMON_H_
