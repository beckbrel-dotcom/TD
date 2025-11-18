#ifndef LIBRARY_H
#define LIBRARY_H

#include <stddef.h>


// Structure représentant un livre stocké dans l'AVL
struct SBook {
    int id; 
    struct SBook *left;
    struct SBook *right;
    int height; // hauteur du noeud pour l'AVL
};

typedef struct SBook* Book ;

// Création / destruction
Book book_create(int id);
void book_free(Book b);

// Opérations AVL
int book_height(Book node);
Book avl_insert(Book root, Book node); // insère (par id) et retourne nouvelle racine
Book avl_delete(Book root, int id);      // supprime un livre par id
int avl_find(Book root, int id);        // recherche par id


#endif // LIBRARY_H