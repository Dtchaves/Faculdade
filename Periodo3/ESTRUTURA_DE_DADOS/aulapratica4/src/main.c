#include <../include/Fila_Circular.h>
#include <../include/Pilha.h>

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define LIMITE 10000

int Ja_Foi(int* Valores_Ja_Gerados,int Valor){
    int i;
    for(i = 0; i<LIMITE;i++){
        if(Valores_Ja_Gerados[i] == Valor) return 1;
    }
    i = 0;
    while(Valores_Ja_Gerados[i] != -1) i++;
    Valores_Ja_Gerados[i] = Valor;
    return 0;
}


int main(int argc,char **argv){

    srand(time(NULL));
    int* Valores_Ja_Gerados = (int *) malloc(sizeof(int)*LIMITE);
    for (int i = 0; i < LIMITE; i++) {
        Valores_Ja_Gerados[i] = -1;
    }

    Pilha* teste = Cria_Pilha();
    int i,Aux;

    if(Pilha_Vazia(teste)) printf("Pilha criada e vazia\n");

    for(i = 1; i<LIMITE+1;i++){
        do{
            Aux = rand()%LIMITE;
        } while(Ja_Foi(Valores_Ja_Gerados,Aux));

        Empilha(&teste,Aux);
        printf("O %iº valor empilhado na pilha é %i\n",i,Aux);
    }

    if(!Pilha_Vazia(teste)) printf("Pilha nao vazia\n");

    for(i = 1; i<LIMITE+1;i++){
        printf("O %iº valor desempilhado na pilha é %i\n",i,Desempilha(teste));
    }

    if(Pilha_Vazia(teste)) printf("Pilha vazia\n");


    Destroi_Pilha(teste);
    printf("Pilha destruida\n");
    return 0;
}