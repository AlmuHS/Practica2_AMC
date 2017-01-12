#include "Sort.h"

using namespace std;

Sort::Sort()
{
    //ctor
}

int Sort::newGap(int gap){
	gap /= 1.3;
	if(gap == 9 || gap == 10)
		gap = 11;
	if(gap < 1)
		return 1;
	return gap;
}

void Sort::combSort(vector<int> &a, int start, int len){
	int gap = len;
	bool swapped;
	do{
		swapped = false;
		gap = newGap(gap);
		for(int i=start; i < len-gap; ++i){
			if(a[i] > a[i+gap]){
				swapped = true;
				swap(a[i], a[i+gap]);
			}
			if(a[i] == a[i+gap]){
				swapped = true;
			}
		}
	}while(gap > 1 || swapped);
}
