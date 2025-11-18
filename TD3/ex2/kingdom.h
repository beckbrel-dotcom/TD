#ifndef KINGDOM_H
#define KINGDOM_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int value;
    int* links;
};

typedef struct node* Node;

struct graph{
    int n;
    int* edges[];
};

typedef struct graph* Graph;

int kingdoms(Graph G);

int dijkstra(Node start,Node end);

#endif