#include <stdio.h>
#include <stdlib.h>
#include "library.h"


void insert(int n, Node* root) {
    
    if (root == NULL) {
        root -> value = n;
        root -> left = NULL;
        root -> right = NULL;
    }
    else {
        //int v = root -> value;
        Node* current = malloc(sizeof(struct Node));
        current = root;

        while (current != NULL ) {

            if (current -> value > n) {
                if (current -> left == NULL ) {
                    current -> left -> value = n;
                }

                if (current -> left -> value > n) {
                    
                    if (current -> right == NULL) {
                        // c'est là où l'acteur meurt
                        int copy = current ->value;
                        current ->value = current ->left ->value;
                        current ->left ->value = n;
                        current ->right ->value = copy; 
                    }
                }
                if (current ->left->value < n) {    
                    if (current -> right == NULL) {
                        // c'est là où l'acteur meurt
                        int copy = current ->value;
                        current ->value = n;
                        current ->right ->value = copy;
                    } 
                    }
                }
                    
            
            else {
                if (current -> right == NULL ) {
                    current -> right -> value = n;
                }
                if (current -> right -> value > n) {
                    
                    if (current -> left == NULL) {
                        // c'est là où l'acteur meurt
                        int copy = current ->value;
                        current ->value = n;
                        current ->left ->value = copy;
                    }
                }
                if (current -> right -> value < n) {
                    
                    if (current -> left == NULL) {
                        // c'est là où l'acteur meurt
                        int copy = current ->value;
                        current ->value = current ->right ->value;
                        current ->left ->value = copy;
                        current ->right ->value = n; 
                    }
                }
            }
        }

    }

}

void check(int n, int* tab, Node* root) {

}