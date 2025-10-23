#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "utils.h"
#include "search.h"

int linear_search(int* arr, int n, int target) {
	for (int k=0; k<n; k++) {
		if ( *(arr+k) == target) { return k;}		
		}
	return -1;	
	}
	
int binary_search(int* arr, int n, int target) {
    int inf = 0;
    int sup = n - 1;

    while (inf <= sup) {
        int m = (inf + sup) / 2;

        if (arr[m] == target)
            return m;
        else if (arr[m] < target)
            inf = m + 1;
        else
            sup = m - 1;
    }
    return -1;
}

int jump_search(int* arr, int n, int target) {
    int jump = (int)sqrtf(n);
    int prev = 0;


    while (arr[min_int(jump, n) - 1] < target) {
        prev = jump;
        jump += (int)sqrtf(n);
        if (prev >= n)
            return -1;
    }


    for (int i = prev; i < min_int(jump, n); i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}
