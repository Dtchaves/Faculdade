#include <../include/Shellsort.h>

void Shellsort_H1(int* Vetor, int Tamanho){
    int i,j;
    int Aux;
    int h = Tamanho/2;

    while(h>0){
        for(i = h; i< Tamanho;i++){
            Aux = Vetor[i];
            j = i;
            while((j>=h)&&(Vetor[j-h]>Aux)){
                Vetor[j] = Vetor[j-h];
                j = j-h;
            }
            Vetor[j]= Aux;
        }

        h = h/2;
    }
}

void Shellsort_H2(int* Vetor, int Tamanho){
    int i,j;
    int Aux;
    int h = 1;
    while(h<Tamanho){
        h = 3*h +1;
    }

    while(h>0){
        for(i = h; i< Tamanho;i++){
            Aux = Vetor[i];
            j = i;
            while((j>=h)&&(Vetor[j-h]>Aux)){
                Vetor[j] = Vetor[j-h];
                j = j-h;
            }
            Vetor[j]= Aux;
        }

        h = (h-1)/3;
    }
}
