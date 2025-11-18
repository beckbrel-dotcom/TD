#include "kingdom.h"



/*-----------Matrix algebra-------------*/

Matrix init_matrix(int N){
    Matrix M = malloc(sizeof(struct SMatrix)) ;
    int** vs = malloc(N*sizeof(int*)) ;
    M->size = N ;
    M->values = vs ;
    for(int i = 0 ; i<N ; i++){
        M->values[i] = calloc(N,sizeof(int)) ;
    }
    return M ;
}

void display_matrix(Matrix M){
    int N = M->size ;
    printf("matrice de taile %i :\n",M->size) ;
    for(int i = 0 ; i<N ; i++){
        printf("ligne%i [ ",i) ;
        for(int j = 0 ; j<N ; j++){
            printf("%i ", M->values[i][j]) ;
        }
        printf("]\n") ;
    }
}

bool are_linked(Matrix M, int i, int j) {
    return (M->values[i][j]!=0)?true:false ;
}
/*-------------------------------------*/

/*-----------Search programms------------*/

int* DFS(Matrix G, int s, int* visited){
    visited[s] = 1 ;
    printf("sommet %i visité\n", s) ;
    for(int n = 0 ; n<G->size ; n++){
        if(are_linked(G,s,n)&&
        (visited[n]==0)){
            DFS(G, n, visited) ;
        }
    }
    return visited ;
}

int* BFS(Matrix G, int s, Queue Q, int* visited){
    visited[s] = 1 ;
    printf("sommet %i visité\n", s) ;
    enqueue(Q, s) ;

    while(Q->back - Q->front + 1 != 0){
        int u = dequeue(Q) ;
        for(int n = 0 ; n<G->size ; n++){
            if(are_linked(G,u,n)
            &&(visited[n]==0)){
                visited[n] = 1 ;
                enqueue(Q, n) ;
            }
        }
    }
    return visited ;
}

/*---------------------------------------*/

/*-----------Solution programms------------*/
int find_min_distance_vertex(int N, int* dist, int* visited) {
    int min_dist = INT_MAX;
    int min_vertex = -1;

    for (int v = 0; v < N; v++) {
        if (visited[v] == 0 && dist[v] < min_dist) {
            min_dist = dist[v];
            min_vertex = v;
        }
    }
    return min_vertex;
}
int* DIJKSTRA(Matrix G, int s) {
    int N = G->size;
    int* visited = calloc(N, sizeof(int));
    int* dist = calloc(N, sizeof(int));

    
    for (int i = 0; i < N; i++) {
        if (i != s) {
            dist[i] = INT_MAX;
        }
    }

    int u = s; 

    
    while ((u = find_min_distance_vertex(N, dist, visited)) != -1) {
        
        visited[u] = 1; 
        printf("sommet %i visité\n", u);

        
        for (int v = 0; v < N; v++) {
            
            
            if (visited[v] == 0 && are_linked(G, u, v) && dist[u] != INT_MAX) {
                
                int poids_uv = G->values[u][v]; 
                
                
                if (dist[u] + poids_uv < dist[v]) {
                    dist[v] = dist[u] + poids_uv;
                    
                }
            }
        }
        
    }

    free(visited);
    return dist;
}

int KINGDOMS(Matrix G,int s){
    int N = G->size ;
    int res = 0 ;
    int next = s ;
    int* visited = calloc(N,sizeof(int)) ;
    while(sum_arr(visited, N)<N){
        for(int i=0 ; i<N ; i++){
            if(!visited[i]){
                next = i ;
                res++ ;
                DFS(G, s, visited) ;
            }
        }
    }
    return res ;
}

/*-----------------------------------------*/