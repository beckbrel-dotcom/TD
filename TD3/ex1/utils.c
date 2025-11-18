#include "utils.h"
#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void avl_inorder_print(Book root) {
    if (!root) return;
    avl_inorder_print(root->left);
    printf("id=%d\n", root->id);
    avl_inorder_print(root->right);
}

void avl_free_tree(Book root) {
    if (!root) return;
    avl_free_tree(root->left);
    avl_free_tree(root->right);
    free(root);
}

int file_cmp(FILE *f1, FILE *f2){
    char tmp1 ;
    char tmp2 ;
    int line = 0 ;
    while((fscanf(f1, "%s", &tmp1)==1)&&
    (fscanf(f2, "%s", &tmp2)==1)){
        line++ ;
        if(tmp1!=tmp2){
            printf("Erreur : différence trouvée ligne %i.\n",line) ;
            return -1 ; //Les fichiers sont différents
        }
    }
    return 1 ;

}