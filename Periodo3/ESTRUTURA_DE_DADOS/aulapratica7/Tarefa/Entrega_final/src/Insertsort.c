#include <../include/Insertsort.h>


void Insertsort(int* Vetor, int Tamanho){
    int i,j;
    int Aux;
    int h = 1;

    for(i = h; i< Tamanho;i++){
        Aux = Vetor[i];
        j = i;
        while((j>=h)&&(Vetor[j-h]>Aux)){
            Vetor[j] = Vetor[j-h];
            j = j-h;
        }
        Vetor[j] = Aux;
    }
}