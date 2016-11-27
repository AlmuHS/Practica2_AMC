/* Copyright 2013 2016 Almudena García Jurado-Centurión, pepstain
    This file is part of Practica2_AMC, based in pepstein work (http://www.cplusplus.com/forum/beginner/119660/)

    Practica2_AMC is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Practica2_AMC is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Practica2_AMC.  If not, see <http://www.gnu.org/licenses/>.
*/


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

