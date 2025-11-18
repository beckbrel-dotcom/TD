#ifndef UTILS_H
#define UTILS_H

#include "library.h"
#include <stdio.h>

// Utilitaires
void avl_inorder_print(Book root);
void avl_free_tree(Book root);
int file_cmp(FILE *f1, FILE *f2) ;

#endif