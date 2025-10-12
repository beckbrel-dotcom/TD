#include<stdio.h>
#include "fibo.h"

int fibo(int n) {
    if (n <2) {return n;}
    return fibo(n-1) + fibo(n-2);
}

int fibo2(int n, int tab[]) {
    if (n<2) {return n;}
    if (tab[n] !=-1) {return tab[n];}
    tab[n]= fibo2(n-1,tab) + fibo2(n-2, tab);
    return tab[n];
}
