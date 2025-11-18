#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct SQueue{
    int size ;
    int front ;
    int back ;
    int* values ;
} ;

struct SStack{
    int size ;
    int top ;
    int* values ;
} ;

typedef  struct SQueue *Queue ;
typedef struct SStack *Stack ;


/*--------Queues algebra-------*/

Queue init_queue(int N) ;

void display_queue(Queue Q) ;

void enqueue(Queue Q, int e) ;

int dequeue(Queue Q) ;

int front(Queue Q) ;

/*-----------------------------*/

/*--------Stacks algebra-------*/

Stack init_stack(int N) ;

void display_stack(Stack S) ;

void push(Stack S, int e) ;

int pop(Stack S) ;

int peek(Stack S) ;

/*-----------------------------*/


/*-----------Others------------*/

int min_int(int a, int b) ;

int max_int(int a, int b) ;

int *min_arr(int* v, int size) ;

int *max_arr(int* v, int size) ;

int sum_arr(int* v, int size) ;

int file_cmp(FILE *f1, FILE *f2) ;

/*-----------------------------*/












#endif