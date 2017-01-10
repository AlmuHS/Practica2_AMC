#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

class HeapSort
{
    private:

    public:
        template<typename RandomAccessIterator>
        void heap_sort(RandomAccessIterator begin, RandomAccessIterator end);
};

#endif // HEAPSORT_H
