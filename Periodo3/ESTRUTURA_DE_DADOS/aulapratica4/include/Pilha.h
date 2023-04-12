#ifndef PILHA
#define PILHA

#include <stdlib.h>
#include <stdio.h>
#include <Fila_Circular.h>

typedef struct Pilha{
    Fila_Circular* Valores;
}Pilha;

Pilha* Cria_Pilha(void);

int Pilha_Vazia(Pilha* Entrada);

void Empilha(Pilha** Entrada, int Valor);

int Desempilha(Pilha* Entrada);

void Destroi_Pilha(Pilha* Entrada);

#endif