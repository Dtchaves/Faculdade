#ifndef FILA_CIRCULAR
#define FILA_CIRCULAR

#include <stdlib.h>
#include <stdio.h>

typedef struct Fila_Circular{
    int Numero;
    struct Fila_Circular* Posterior;
    struct Fila_Circular* Anterior;
}Fila_Circular;

Fila_Circular* Cria_Fila(void);

int Fila_Vazia(Fila_Circular* Entrada);

void Enfileira(Fila_Circular* Entrada, int Valor);

int Desenfileira(Fila_Circular** Entrada);

void Destroi_Fila(Fila_Circular* Entrada);



#endif