#include <../include/Fila_Circular.h>

#include <stdlib.h>
#include <stdio.h>


Fila_Circular* Cria_Fila(void){
    Fila_Circular* Aux = (Fila_Circular*) malloc(sizeof(Fila_Circular));
    Aux->Posterior = NULL;
    Aux->Anterior = NULL;
    return Aux;
}

int Fila_Vazia(Fila_Circular* Entrada){
    if((Entrada->Posterior == NULL) && (Entrada->Anterior == NULL)) {
        return 1;
    }
    else {
        return 0;
    }
}

void Enfileira(Fila_Circular* Entrada, int Valor){

    if(!Fila_Vazia(Entrada)){
        Fila_Circular* Aux = Cria_Fila();
        Aux->Numero = Valor;
        Aux->Posterior = Entrada;
        Aux->Anterior = Entrada->Anterior;
        Entrada->Anterior->Posterior = Aux;
        Entrada->Anterior = Aux;
    }
    else{
        Entrada-> Numero = Valor;
        Entrada->Anterior = Entrada;
        Entrada->Posterior = Entrada;
    }
}

int Desenfileira(Fila_Circular** Entrada){
    if(!Fila_Vazia(*Entrada)){
        int Retorno = (*Entrada)->Numero;
        if(((*Entrada)->Posterior == (*Entrada))&&((*Entrada)->Anterior == (*Entrada))){
            (*Entrada)->Posterior = NULL;
            (*Entrada)->Anterior = NULL;
        }
        else{
            (*Entrada)->Posterior->Anterior = (*Entrada)->Anterior;
            (*Entrada)->Anterior->Posterior = (*Entrada)->Posterior;
            Fila_Circular* Aux = (*Entrada);
            (*Entrada) = (*Entrada)->Posterior;
            free(Aux);
        }
        return(Retorno);
    }
    else{
        printf("Erro Fila Vazia");
        return 0;
    }
}

void Destroi_Fila(Fila_Circular* Entrada){

    while(!Fila_Vazia(Entrada)){
        Desenfileira(&Entrada);
    }
    free(Entrada);
}