#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "prime.h"


bool diviseur(int d,int n) {
    if (n%d == 0) {return true;}
    return false;
}

bool prime(int n) {
   if (n <2) {return false;}

   for (int k=2;k <= sqrtf(n); k++) {
    if (diviseur(k,n)) {
    return false; }
   }
   return true;
   
}

int nb_prime(int n) {
   int v=0;
   for (int k=2; k<=n; k++) {
    if (prime(k))
    v++;}
   return v;
}

int nb_prime2(int n,bool tab[]) {
    if (n<2) { 
      return 0;}
    int v=0;
    for (int k=2; k<n+1; k++) { 
      if (tab[k]) {
        v++;
        for (int i=k*k; i<= n; i=i+k) {
           tab[i] = false;}
      } 
    }
    return v;
}
