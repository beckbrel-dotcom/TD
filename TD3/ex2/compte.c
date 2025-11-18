compter le nombre de graphes conectés 

    //int v = root -> value;
        Node* current = malloc(sizeof(struct Node));
        current = root;

        while (current != NULL) {
            if (current -> value > n) {
                if (current -> left == NULL ) {

                    
                    current -> left -> value = n;
                }
                else {
                    current = current -> left;
                }
            }
            else {
                if (current -> right == NULL ) {
                    current -> right -> value = n;
                }
                else {
                    current = current -> right;
                }
            }
        }


