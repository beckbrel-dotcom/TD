#include "utils.h"

bool is_sorted_nondecreasing(int *arr, int n)
{
    for (int k=0; k<n-1 ;k++) {
		if (arr[k]>arr[k+1]) return false;
	}
	return true; 
    // return true if array is sorted and false otherwise
}

int min_int(int a, int b)
{
    if (a>b) return b;
    return a;
    // return smallest value between a and b
}
