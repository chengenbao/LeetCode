// Copyright 2019 chengenbao. All Rights Reserved.

#include "common.h"

#include <algorithm>
#include <iostream>

int main(int argc, char** argv) {
  Heap<int, std::less<int>> heap;

  heap.Push(3);
  heap.Push(10);
  heap.Push(1);
  heap.Push(5);
  heap.Push(8);
  heap.Push(23);

  heap.Build();

  int item;

  heap.Pop(&item);
  std::cout << item << std::endl;

  heap.Push(2);
  heap.Push(4);
  heap.Build();
  while (heap.Pop(&item)) {
    std::cout << item << std::endl;
  }

  return 0;
}
