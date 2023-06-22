#include <../include/Fila_Circular.h>
#include <../include/Pilha.h>

#include <stdlib.h>
#include <stdio.h>

Pilha* Cria_Pilha(void){
    Pilha* Retorno= (Pilha*) malloc(sizeof(Pilha*));
    Retorno->Valores = Cria_Fila();
    return Retorno;
}

int Pilha_Vazia(Pilha* Entrada){
    return Fila_Vazia(Entrada->Valores);
}

void Empilha(Pilha** Entrada, int Valor){
    if(!(Pilha_Vazia(*Entrada))){
        Fila_Circular* Aux = Cria_Fila();
        Enfileira(Aux,Valor);
        while(!(Pilha_Vazia(*Entrada))) Enfileira(Aux,Desenfileira(&((*Entrada)->Valores)));
        (*Entrada)->Valores = Aux;
    }
    else{
        Enfileira((*Entrada)->Valores,Valor);
    }
}

int Desempilha(Pilha* Entrada){
    return Desenfileira(&(Entrada->Valores));
}

void Destroi_Pilha(Pilha* Entrada){
    Destroi_Fila(Entrada->Valores);
    free(Entrada);
}