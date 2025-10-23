#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "search.h"
#include "utils.h"

int main() {
    int n = 100;
    int target = 90;

    int *tab = malloc(n * sizeof(int));
    int *tab2 = malloc(n * sizeof(int));

    if (tab == NULL || tab2 == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        tab[i] = i + 1; // 1 à 100
    }

    clock_t start, end;
    double duree;

    start = clock();
    printf("linear_search(tab,100,90) = %d\n", linear_search(tab, n, target));
    end = clock();
    duree = (double)(end - start) / CLOCKS_PER_SEC;
    printf("durée: %f s\n", duree);

    if (is_sorted_nondecreasing(tab,n)) {
        start = clock();
        printf("binary_search(tab,100,90) = %d\n", binary_search(tab, n, target));
        end = clock();
        duree = (double)(end - start) / CLOCKS_PER_SEC;
        printf("durée: %f s\n", duree);

        start = clock();
        printf("jump_search(tab,100,90) = %d\n", jump_search(tab, n, target));
        end = clock();
        duree = (double)(end - start) / CLOCKS_PER_SEC;
        printf("durée: %f s\n", duree);
    } else {
        printf("Le tableau n'est pas trié.\n");
    }

    free(tab);
    free(tab2);
    return 0;
}
