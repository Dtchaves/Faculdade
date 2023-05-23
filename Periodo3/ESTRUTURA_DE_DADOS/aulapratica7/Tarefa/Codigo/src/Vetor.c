#include <../include/Vetor.h>

void Printar_Vetor(int* Vetor,int Tamanho){
    for( int i = 0; i<Tamanho;i++){
        printf("%d \n",Vetor[i]);
    }
}

void Copia_Vetor(int* Vetor_Copiar,int* Vetor_Copia,int Tamanho){
    for (int i = 0; i < Tamanho;  i++) {
            Vetor_Copia[i] = Vetor_Copiar[i];
    }
}