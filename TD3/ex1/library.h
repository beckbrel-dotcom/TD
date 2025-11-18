#ifndef LIBRARY_H
#define LIBRARY_H

#include<stdio.h>

typedef struct Node {
    int value;
    Node* left;
    Node* right;
} Node;

void insert(int n, Node* root);

void check(int n, int* tab, Node* root);

#endif