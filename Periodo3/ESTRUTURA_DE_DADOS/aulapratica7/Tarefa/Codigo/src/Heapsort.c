#include <../include/Heapsort.h>

void Arruma(int Raiz, int Ultima_vaga,int* Vetor){
    int Filho =((Raiz+1)*2) - 1; /*Começa sendo o filho da esquerda*/
    int Chave_raiz = Vetor[Raiz];

    while(Filho <= Ultima_vaga){
        if((Filho<Ultima_vaga)&&(Vetor[Filho]<Vetor[Filho+1])) Filho++; /*Se torna o filho da direita */
        if(Chave_raiz>Vetor[Filho]) break;
        Vetor[Raiz] = Vetor[Filho];
        Raiz = Filho;
        Filho =((Raiz+1)*2) - 1;
    }
    Vetor[Raiz] = Chave_raiz;
}


void Monta(int* Vetor, int Ultima_vaga){
    int Filho_esquerda = (Ultima_vaga+1)/2;
    while(Filho_esquerda > 0){
        Filho_esquerda--;
        Arruma(Filho_esquerda,Ultima_vaga,Vetor);
    }
    return;
}


void Heapsort(int* Vetor, int Tamanho){
    int Ultima_vaga = Tamanho -1;
    int Troca;
    Monta(Vetor,Ultima_vaga);
    while(Ultima_vaga >= 0){
        Troca = Vetor[Ultima_vaga];
        Vetor[Ultima_vaga] = Vetor[0];
        Vetor[0] =  Troca;
        Ultima_vaga--;
        Arruma(0,Ultima_vaga,Vetor);
    }

}