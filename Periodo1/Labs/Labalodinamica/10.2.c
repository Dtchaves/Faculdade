#include <stdio.h>
#include <stdlib.h>

int main() {
    int **mat,linhas,colunas,i,j;
    
    scanf("%i",&linhas);
    scanf("%i",&colunas);
    
    mat = (int **) malloc(linhas*sizeof(int*));
    
    for (i = 0; i<linhas;i++){
       mat[i] = (int *) malloc(colunas*sizeof(int));
    }
    
    for (i = 0; i<linhas;i++){
        for (j = 0; j<colunas;j++){
            scanf("%i\n",&mat[i][j]);
        }
    }
    
        for (i = 0; i<linhas;i++){
            for (j = 0; j<colunas;j++){
                printf("%i ",mat[i][j]);
            }
            putchar('\n');
    }
    
    free(mat);
    return 0;
}