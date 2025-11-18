#include "kingdom.h"
#include <unistd.h>
#include <time.h>





int main(){
    
    int *querries = malloc(11*sizeof(int));
    int querNum = 0 ;
    int curQuer ;
    printf("Quel test voulez-vous effectuer ?\n") ;
    printf("Entrez le numéro du test entre 1 et 10 (entrez 0 pour annuler) : ") ;
    scanf("%d", &curQuer) ;
    if(curQuer==0){
        printf("Ok! See you soon ;-)\n") ;
        return 0 ;
    }
    querries[0] = curQuer ;
    querNum++ ;
    while(querNum<10 && curQuer!=0 ){
        printf("Souhaitez-vous effectuer un autre test ?\n") ;
        printf("Entrez le numéro du test entre 1 et 10 (entrez 0 sinon) : ") ;
        scanf("%d", &curQuer) ;
        printf("\n") ;
        if(curQuer!=0) {
            querries[querNum] = curQuer ;
            querNum++ ;
        }
    }
    printf("Bien! Place au test.\n") ;
    for(int i = 0; i<querNum ; i++){
        Matrix G ;
        int* visited ;
        Queue Q ;
        int curTest = querries[i] ;
        if(curTest<10) printf("---------- test0%i ----------\n",curTest) ;
        else  printf("---------- test10 ----------\n") ;
        FILE *curFile ;
        FILE *curFile_res ;
        FILE *curFile_corr ;
        const char* charNum = (curTest<10)?"0":"";

        char fileName[20] ;
        char fileName_res[20] ;
        char fileName_corr[20] ;

        //Ouverture en lecture du fichier en entrée
        sprintf(fileName, "test%s%d.txt", charNum, curTest) ;
        printf("%s\n",fileName) ;
        
        //Ouverture en écriture du fichier résultat
        sprintf(fileName_res, "test%s%d-res.txt", charNum, curTest) ;
        printf("%s\n",fileName_res) ;
        
        /*Ouverture en lecture du fichier correction pour la 
        fonction file_cmp() */
        sprintf(fileName_corr, "test%s%d-output.txt", charNum, curTest) ;


        clock_t start, end ;
        double cpu_time_used ;
        curFile = fopen(fileName,"r") ;
        curFile_res = fopen(fileName_res,"w") ;
        curFile_corr = fopen(fileName_corr,"r") ;
        if (curFile == NULL) {
            fprintf(stderr, "Erreur: Impossible d'ouvrir le fichier d'entrée %s. Le test est ignoré.\n", fileName);
            continue; // Passer au test suivant
        }
        if (curFile_res == NULL) {
             fprintf(stderr, "Erreur: Impossible d'ouvrir le fichier de sortie %s.\n", fileName_res);
             // Tenter de fermer curFile avant de quitter ce test
             fclose(curFile);
             continue; // Passer au test suivant
        }

        //Traitement des entrées
        int N ;
        int M ;
        int I , J ;
        int Al , Jas ;
        int count = 0 ;
        int tmp ;

        start = clock() ;
        while(fscanf(curFile, "%i", &tmp)==1){
            count++ ;
            if(count == 1){
                N = tmp ;
                G = init_matrix(N) ;
            }
            else if(count == 2){
                M = tmp ;
            }
            else if((2 < count ) && (count<= 2*M+2)){
                if(count%2==1){
                    I = tmp-1 ;
                }
                else if(count%2==0){
                    J = tmp-1 ;
                    G->values[I][J] = 1 ;
                    G->values[J][I] = 1 ;
                }
                
            }
            else if(count == 2*M+3){
                Al = tmp-1 ;
            }
            else if(count==2*M+4){
                printf("On y est\n") ;
                Jas = tmp-1 ;
                int out_1 = KINGDOMS(G, Al) ;
                printf("Nombre de royaumes trouvé !") ;
                int out_2 = DIJKSTRA(G,Al)[Jas] ;
                out_2 = (out_2==INT_MAX)?-1:out_2 ;
                printf("Plus court chemin trouvé !") ;
                
                
                

                fprintf(curFile_res,"%i\n%i",out_1, out_2) ;
            }
            
        }
    
        end = clock() ;
        cpu_time_used = ((double)(end - start)/CLOCKS_PER_SEC) ;
        printf("Le traitement de %s a pris %f sec. Veuillez retrouver sa sortie dans %s.\n", 
            fileName, cpu_time_used, fileName_res) ;
        printf("Vérification du résultat\n") ;
        if (curFile_corr == NULL) {
            fprintf(stderr, "Erreur: Impossible d'ouvrir le fichier de correction %s.\n", fileName_corr);
            // Tenter de fermer curFile_corr avant de quitter ce test
            fclose(curFile_corr);
            continue; // Passer au test suivant
        }

        if(file_cmp(curFile_res, curFile_corr)==1){
            printf("La sortie est identique à la correction. Test réussi.\n") ;
        }
        fclose(curFile) ;
        fclose(curFile_res) ;
        fclose(curFile_corr) ;
        free(G) ;
    }

    free(querries) ;
    return 1 ;
}
