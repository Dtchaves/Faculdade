#include <stdio.h>
#include <stdlib.h>

void lervet(int *vet,int tamanho){
    int i;
    
    for(i = 0; i <tamanho; i++){
        scanf("%i",&vet[i]);
    }
}


int main() {
    int *vet1,*vet2,tamanho,i;
    
    scanf("%i",&tamanho);
    
    vet1 = (int *) malloc(tamanho*sizeof(int));
    vet2 = (int *) malloc(tamanho*sizeof(int));
    
    lervet(vet1,tamanho);
    lervet(vet2,tamanho);
    
        for (i = 0; i<tamanho;i++){
            printf("%i\n",vet1[i]+vet2[i]);
    }
    
    free(vet1);
    free(vet2);
    return 0;
}