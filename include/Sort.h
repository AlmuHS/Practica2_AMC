#ifndef SORT_H
#define SORT_H

#include <vector>

using namespace std;

class Sort
{
    public:
        Sort();
        int newGap(int gap);
        void combSort(vector<int> &a, int start, int len);
};

#endif // SORT_H
