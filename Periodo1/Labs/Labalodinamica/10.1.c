#include <stdio.h>
#include <stdlib.h>

int main() {
    int *vet,tamanho,i;
    
    scanf("%i",&tamanho);
    
    vet = (int *) malloc(tamanho*sizeof(int));
    
    for (i = 0; i<tamanho;i++){
        scanf("%i",&vet[i]);
    }
        for (i = 0; i<tamanho;i++){
        printf("%i\n",vet[i]);
    }
    
    free(vet);
    return 0;
}