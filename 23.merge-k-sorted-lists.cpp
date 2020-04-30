// Copyright 2019 chengenbao. All Rights Reserved.

/*
 *
 [23] Merge k Sorted Lists

 Merge k sorted linked lists and return it as one sorted list. Analyze and
 describe its complexity.

 Example:

 Input:
 [
 1->4->5,
 1->3->4,
 2->6
 ]

 Output: 1->1->2->3->4->4->5->6
*/

#ifdef DEBUG

#include <iostream>
#include <string>
#include <vector>

#include "common.h"

#else

template <typename T, typename C>
class Heap {
 public:
  Heap() : size_(0) {}

  explicit Heap(const std::vector<T>& items)
      : items_(items), size_(items.size()) {
    Build();
  }

  void Build() {
    if (size_ > 0) {
      for (int i = size_ / 2 - 1; i >= 0; --i) {
        Adjust(i);
      }
    }
  }

  void Adjust(int i) {
    T flag = items_[i];

    while (2 * i + 1 < size_) {
      int min = 2 * i + 1;
      if (min + 1 < size_ && c_(items_[min + 1], items_[min])) {
        ++min;
      }

      if (c_(items_[min], items_[i])) {
        items_[i] = items_[min];
        i = min;
      } else {
        break;
      }
    }

    items_[i] = flag;
  }

  void Push(const T& item) {
    if (items_.size() > size_) {
      items_[size_] = item;
    } else {
      items_.emplace_back(item);
    }
    ++size_;
  }

  bool Pop(T* item) {
    if (size_ == 0) {
      return false;
    }

    *item = items_[0];
    items_[0] = items_[size_ - 1];
    --size_;
    Adjust(0);

    return true;
  }

  bool IsEmpty() const { return size_ == 0; }

 private:
  C c_;
  std::vector<T> items_;
  size_t size_;
};

#endif  // DEBUG

class Solution {
 public:
  ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    Heap<ListNode*, ListNodeCmp> heap(lists);

    ListNode* head = nullptr;
    ListNode* last = nullptr;
    ListNode* item = nullptr;
    while (heap.Pop(&item)) {
      if (item != nullptr) {
        if (head == nullptr) {
          head = item;
        }
        if (last != nullptr) {
          last->next = item;
        }
        last = item;
        heap.Push(item->next);
      }
      heap.Build();
    }

    return head;
  }

 private:
  struct ListNodeCmp {
    bool operator()(ListNode* p, ListNode* q) {
      if (p == nullptr) {
        return true;
      }

      if (q == nullptr) {
        return false;
      }

      return p->val < q->val;
    }
  };
};

#ifdef DEBUG

int main(int argc, char** argv) {
  std::vector<ListNode*> lists;
  lists.emplace_back(ConstructList({1, 4, 5}));
  lists.emplace_back(ConstructList({1, 3, 4}));
  lists.emplace_back(ConstructList({2, 6}));

  Solution s;
  PrintList(s.mergeKLists(lists));

  lists.clear();

  lists.emplace_back(ConstructList({-6, -4, 0, 0, 4}));
  lists.emplace_back(ConstructList({}));
  lists.emplace_back(ConstructList({4, -2, -1, 1, 2, 3}));
  lists.emplace_back(ConstructList({-9, -6, -5, -2, 4, 4}));
  lists.emplace_back(ConstructList({-9, -6, -5, -2, -1, 3}));
  lists.emplace_back(ConstructList({-2, -1, 0}));
  lists.emplace_back(ConstructList({-6}));
  lists.emplace_back(ConstructList({-8, -1, 0, 2}));

  PrintList(s.mergeKLists(lists));

  return 0;
}

#endif  // DEBUG
