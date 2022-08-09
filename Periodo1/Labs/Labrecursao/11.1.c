#include <stdio.h>
#include <stdlib.h>

void levet ( int *vet, int tamanho){
    int i;
    
    for (i = 0; i<tamanho;i++){
        scanf("%i",&vet[i]);
    }
}

int soma(int *vet, int tamanho){

int i;
i = tamanho - 1;
if (i == 0){
    return vet[i];
    
}
        else {
                return vet[i] + soma(vet,i);
        }
}

int main(){
    int *vet,tamanho;
    
    scanf("%i",&tamanho);
    
    vet = (int *) malloc (tamanho*sizeof(int));
    levet(vet,tamanho);
    printf("%i",soma(vet,tamanho));

    
free(vet);
return 0;
}


