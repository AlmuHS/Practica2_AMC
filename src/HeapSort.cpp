#include "../include/HeapSort.h"

template<typename RandomAccessIterator>
void HeapSort::heap_sort(RandomAccessIterator begin, RandomAccessIterator end) {
  std::make_heap(begin, end);
  std::sort_heap(begin, end);
}
