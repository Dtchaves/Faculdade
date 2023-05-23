#ifndef HEAPSORT_
#define HEAPSORT_

#include <stdlib.h>
#include <stdio.h>

/*Ordena usando o Heapsort e usa duas funções auxiliares*/
void Heapsort(int* Vetor, int Tamanho);

/*A partir de uma Raiz vai arrumando todos seus filhos para que os Nós pais sempre sejam maiores que os filhos*/
void Arruma(int Raiz, int Ultima_vaga,int* Vetor);

/*Monta a Arvore inicial*/
void Monta(int* Vetor, int Ultima_vaga);

#endif
