#ifndef KINGDOM_H
#define KINGDOM_H

#include "utils.h"
#include <stdbool.h>
#include <limits.h>

struct SMatrix{
    int size ;
    int** values ;
} ;

typedef struct SMatrix *Matrix ;


/*-----------Matrix algebra-------------*/

Matrix init_matrix(int N) ;

void display_matrix(Matrix M) ;

bool are_linked(Matrix M, int i, int j) ;

/*-------------------------------------*/

/*-----------Search programms------------*/

int* DFS(Matrix G, int s, int* visited) ;

int* BFS(Matrix G, int s, Queue Q, int* visited) ;

/*---------------------------------------*/

/*-----------Solution programms------------*/

int* DIJKSTRA(Matrix G, int s) ;

int KINGDOMS(Matrix G, int s) ;

/*-----------------------------------------*/











#endif