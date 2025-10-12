#include <stdio.h>
#include <time.h>
#include "fibo.h"

void main() {
    int n = 30;
    int tab[31];
    for (int i=0; i<=30; i++) tab[i] =-1;
    clock_t start, end;

    start = clock();
    printf("%d\n", fibo(n));
    end = clock();
    double duree_fibo = (double)(end - start)/ CLOCKS_PER_SEC;
    printf("durée fibo: %f s\n", duree_fibo);

    start = clock();
    printf("%d\n", fibo2(n, tab));
    end = clock();
    double duree_fibo2 = (double)(end - start)/ CLOCKS_PER_SEC;
    printf("durée fibo2: %f s\n", duree_fibo2);
}