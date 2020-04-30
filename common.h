// Copyright 2019 chengenbao. All Rights Reserved.

#ifndef COMMON_H_
#define COMMON_H_

#include <iostream>
#include <vector>

struct ListNode {
  int val;
  ListNode* next;
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

template <typename T>
void PrintVector(const std::vector<T>& vec, const int n) {
  for (int i = 0; i < n; ++i) {
    std::cout << vec[i];
  }
  std::cout << std::endl;
}

template <typename T>
void PrintVector(const std::vector<T>& vec) {
  PrintVector(vec, vec.size());
}

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

#endif  // COMMON_H_
