#include "../include/QuickSort.h"

using namespace std;

void QuickSort::quickSort(vector<pair<float, float> > arr, int start, int end)
{
    if (start < end)        //test for base case start == end
    {
        // Partition the array and get the pivot point.
        int p = partition(arr, start, end);

        // Sort the portion before the pivot point.
        quickSort(arr, start, p - 1);

        // Sort the portion after the pivot point.
        quickSort(arr, p + 1, end);
	}
	return;                 //base case
}
int QuickSort::partition(vector<pair<float, float> > arr, int start, int end)
{
    // The pivot element is taken to be the element at
    // the start of the subrange to be partitioned.
    float pivotValue = arr[start].first;
    int pivotPosition = start;

    // Rearrange the rest of the array elements to
    // partition the subrange from start to end.
    for (int pos = start + 1; pos <= end; pos++)
    {
        if (arr[pos].first < pivotValue)
        {
            // arr[pos] is the "current" item.
            // Swap the current item with the item to the
            // right of the pivot element.
            swap(arr[pivotPosition + 1], arr[pos]);
            // Swap the current item with the pivot element.
            swap(arr[pivotPosition], arr[pivotPosition + 1]);
            // Adjust the pivot position so it stays with the
            // pivot element.
            pivotPosition ++;
        }
	}
    return pivotPosition;
}

