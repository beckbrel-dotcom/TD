#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include "prime.h"

void main() {
    int n=201;
    bool tab[n+2];

    tab[0]= false;
    tab[1]= false;
    for (int k=2; k<n+1; k++) {
        tab[k]= true;
    }
    clock_t start, end;
    start = clock();
    int v= nb_prime(n);
    end = clock();
    double duree = (double)(end - start) / CLOCKS_PER_SEC;
    printf("nombre de premiers %d\n", v);
    printf("durée nb_prime %f s\n", duree);

    start = clock();
    int v2= nb_prime2(n, tab);
    end = clock();
    double duree2 = (double)(end - start) / CLOCKS_PER_SEC;
    printf("nombre de premiers %d \n", v);
    printf("durée nb_prime2 %f s\n", duree2);

}