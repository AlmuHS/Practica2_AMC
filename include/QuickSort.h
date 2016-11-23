#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <algorithm>    // std::swap
#include <vector>
#include <utility>

using namespace std;

class QuickSort
{
    public:
        void quickSort(vector<pair<float, float> >, int, int);

        int partition(vector<pair<float, float> >, int, int);

};

#endif // QUICKSORT_H
