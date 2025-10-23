#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include "sort.h"
#include "utils.h"

void selection_sort(int *arr, int n)
{
    for (int k =0; k< n; k++) {
        int min_index = k;
        for (int j =k+1; j < n; j++) {
            if(arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        swap_int(&arr[k], &arr [min_index]); 
    }
    // selection sort iterative
}

void insertion_sort(int *arr, int n)
{
    for (int i =1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    // insertion sort iterative
}

void bubble_sort(int *arr, int n)
{
    for (int i =0; i < n - 1; i++) {
        for (int j =0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap_int(&arr[j], &arr[j + 1]);
            }
        }
    }
    // bubble sort iterative
}


void merge(int *arr, int *tmp, int l, int m, int r)
{
    int i = l;      
    int j = m + 1;  
    int k = l;    

    while (i <= m && j <= r) {
        if (arr[i] <= arr[j])
            tmp[k++] = arr[i++];
        else
            tmp[k++] = arr[j++];
    }

    while (i <= m)
        tmp[k++] = arr[i++];

    while (j <= r)
        tmp[k++] = arr[j++];

    for (i = l; i <= r; i++)
        arr[i] = tmp[i];
     //merge funtion
    }

void mergesort_rec(int *arr, int *tmp, int l, int r)
{
    if (l >= r)
        return;
    int m = (l + r) / 2;

    mergesort_rec(arr, tmp, l, m);
    mergesort_rec(arr, tmp, m + 1, r);
    merge(arr, tmp, l, m, r);
    // recursive steps of merge sort
}

void merge_sort(int *arr, int n)
{
    if (!arr || n <= 1)
        return;
    int *tmp = (int *)malloc((size_t)n * sizeof(int));
    if (!tmp)
        return;
    mergesort_rec(arr, tmp, 0, n - 1);
    free(tmp);
}

#include <stdio.h>

int partition(int *arr, int l, int r)
{
    int pivot = arr[r];  
    int i = l - 1;      

    for (int j = l; j < r; j++) {
        if (arr[j] <= pivot) {
            i++;
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }

    int tmp = arr[i + 1];
    arr[i + 1] = arr[r];
    arr[r] = tmp;

    return i + 1;
}

void quick_sort_rec(int *arr, int l, int r)
{
    if (l < r) {
        int p = partition(arr, l, r);
        quick_sort_rec(arr, l, p - 1);
        quick_sort_rec(arr, p + 1, r);
    }
}

void quick_sort(int *arr, int n)
{
    if (!arr || n <= 1)
        return;
    quick_sort_rec(arr, 0, n - 1);
}
