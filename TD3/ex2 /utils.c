#include "utils.h"



/*--------Queues algebra-------*/

Queue init_queue(int N){
    Queue Q = malloc(sizeof(struct SQueue) + N*sizeof(int)) ;
    int* vs = malloc(N*sizeof(int)) ;

    Q->size = N ;
    Q->back = -1 ;
    Q->front = 0 ;
    Q->values = vs ;

    return Q ;
}

void display_queue(Queue Q){
    printf("[ ") ;
    for(int i = Q->front; i<= Q->back ; i++){
        printf("%i ", Q->values[i]) ;
    }
    printf("]\n") ;
}

void enqueue(Queue Q, int e){
    Q->back++ ;
    Q->values[Q->back] = e ;
}

int dequeue(Queue Q){
    int e = Q->values[Q->front] ;
    Q->front++ ;
    return e ;
}

int gfront(Queue Q){
    return Q->values[Q->front] ;
}

/*-----------------------------*/



/*--------Stacks algebra-------*/

Stack init_stack(int N){
    Stack S = malloc(sizeof(struct SStack) + N*sizeof(int)) ;
    int* vs = malloc(N*sizeof(int)) ;

    S->size = N ;
    S->top = -1 ;
    S->values = vs ;

    return S ;
}

void display_stack(Stack S){
    for(int i = S->top; i>=0 ; i--){
        printf("[ %i ]\n", S->values[i]) ;
    }
}

void push(Stack S, int e){
    S->top++ ;
    S->values[S->top] = e ; 
}

int pop(Stack S){
    int e = S->values[S->top] ;
    S->top-- ;
    return e ;
}

int peek(Stack S){
    return S->values[S->top] ;
}

/*-----------------------------*/


/*-----------Others------------*/

int min_int(int a, int b){
    return (a<b)?a:b ;
}

int max_int(int a, int b){
    return (a<b)?b:a ;
}

int* min_arr(int* v, int size){
    int* res = calloc(2, sizeof(int)) ;
    res[0] = v[0] ;
    for(int i = 1 ; i<size ; i++){
        res[0] = min_int(res[0], v[i]) ;
        res[1] = i ;
    }
    return res ;
}
 
int* max_arr(int* v, int size){
    int* res = calloc(2, sizeof(int)) ;
    res[0] = v[0] ;
    for(int i = 1 ; i<size ; i++){
        res[0] = max_int(res[0], v[i]) ;
        res[1] = i ;
    }
    return res ;
}

int sum_arr(int* v, int size){
    int res = 0 ;
    for(int i = 0 ; i<size ; i++){
        res+=v[i] ;
    }
    return res ;
}


int file_cmp(FILE *f1, FILE *f2){
    int tmp1 ;
    int tmp2 ;
    int line = 0 ;
    while((fscanf(f1, "%d", &tmp1)==1)&&
    (fscanf(f2, "%d", &tmp2)==1)){
        line++ ;
        if(tmp1!=tmp2){
            printf("Erreur : différence trouvée ligne %i.\n",line) ;
            return -1 ; //Les fichiers sont différents
        }
    }
    return 1 ;

}

/*-----------------------------*/