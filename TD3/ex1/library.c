#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int max_int(int a, int b) { return (a > b) ? a : b; }

int book_height(const Book node) {
    return node ? node->height : 0;
}

Book book_create(int id) {
    Book b = malloc(sizeof(struct SBook));
    if (!b) return NULL;
    b->id = id;

    b->left = b->right = NULL;
    b->height = 1; // nouveau noeud
    return b;
}

void book_free(Book b) {
    if (!b) return;
    free(b);
}

static Book right_rotate(Book y) {
    Book x = y->left;
    Book T2 = x->right;

    // rotation
    x->right = y;
    y->left = T2;

    // Mettre à jour les hauteurs après la rotation
    y->height = 1 + max_int(book_height(y->left), book_height(y->right));
    x->height = 1 + max_int(book_height(x->left), book_height(x->right)); // x est la nouvelle racine locale

    return x;
}

static Book left_rotate(Book x) {
    Book y = x->right;
    Book T2 = y->left;

    // rotation
    y->left = x;
    x->right = T2;
    
    // Mettre à jour les hauteurs après la rotation
    x->height = 1 + max_int(book_height(x->left), book_height(x->right));
    y->height = 1 + max_int(book_height(y->left), book_height(y->right)); // y est la nouvelle racine locale

    return y;
}

static int get_balance(Book node) {
    if (!node) return 0;
    return book_height(node->left) - book_height(node->right);
}


Book avl_insert(Book root, Book node) {
    if (!node) return root; // nothing to insert

    if (!root) return node;

    if (node->id < root->id) {
        root->left = avl_insert(root->left, node);
    } else if (node->id > root->id) {
        root->right = avl_insert(root->right, node);
    } else {
        // clé déjà présente
        printf("ID already exists\n") ;
        book_free(node);
        return root;
    }
    

    // mise à jour hauteur
    root->height = 1 + max_int(book_height(root->left), book_height(root->right));

    int balance = get_balance(root);

    // Left Left
    if (balance > 1 && node->id < root->left->id)
        return right_rotate(root);

    // Right Right
    if (balance < -1 && node->id > root->right->id)
        return left_rotate(root);

    // Left Right
    if (balance > 1 && node->id > root->left->id) {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    // Right Left
    if (balance < -1 && node->id < root->right->id) {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

static Book min_value_node(Book node) {
    Book current = node;
    while (current && current->left) current = current->left;
    return current;
}

Book avl_delete(Book root, int id) {
    if (!root) return NULL;

    if (id < root->id) {
        root->left = avl_delete(root->left, id);
    } else if (id > root->id) {
        root->right = avl_delete(root->right, id);
    } else {
        // noeud trouvé
        if (!root->left || !root->right) {
            Book temp = root->left ? root->left : root->right;
            if (!temp) {
                // pas d'enfants
                temp = root;
                root = NULL;
            } else {
                // un enfant
                *root = *temp; // copie du contenu
            }
            free(temp);
        } else {
            // deux enfants: get inorder successor
            Book temp = min_value_node(root->right);
            root->id = temp->id;
            root->right = avl_delete(root->right, temp->id);
        }
    }

    if (!root) return root;

    root->height = 1 + max_int(book_height(root->left), book_height(root->right));
    int balance = get_balance(root);

    // Left Left
    if (balance > 1 && get_balance(root->left) >= 0)
        return right_rotate(root);

    // Left Right
    if (balance > 1 && get_balance(root->left) < 0) {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    // Right Right
    if (balance < -1 && get_balance(root->right) <= 0)
        return left_rotate(root);

    // Right Left
    if (balance < -1 && get_balance(root->right) > 0) {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

int avl_find(Book root, int id) {
    while (root) {
        if (id == root->id) return 1;
        if (id < root->id) root = root->left;
        else root = root->right;
    }
    return 0;
}
