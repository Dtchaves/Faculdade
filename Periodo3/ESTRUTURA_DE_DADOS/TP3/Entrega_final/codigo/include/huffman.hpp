#ifndef HUFFMAN_
#define HUFFMAN_

#include<iostream>
#include <iomanip>
#include <string>
#include <utilidades.hpp>

using namespace std;

/*Função que, baseado no algoritmo de huffman, utiliza um processo de três fases proposto por Moffat e Katajainen para calcular as alturas 
que cada palavra estaria na árvore de huffman sem de fato montar a árvore, economizando tempo e espaço*/
void calcula_comprimento(long* vetor, long tamanho);

/*Função que transforma o vetor de frequencias das palavras em um que contém em sua segunda posição o peso da árvore e no resto os índices
dos pais dos nós internos da árvore de huffman*/
void primeira_fase(long* vetor, long tamanho);

/*Função que transforma o vetor gerado na primeira fase em um que contém a profundidade dos nós internos*/
void segunda_fase(long* vetor, long tamanho);

/*Função que transforma o vetor gerado na segunda fase em um que contém as alturas que as palavras estariam na árvore que é igual ao comprimento
dos códigos*/
void terceira_fase(long* vetor, long tamanho);

/*Função para mudar os vetores "base" e "offset" que serão vitais na hora de codificar*/
void monta_off_base(long* vetor,long tamanho,long* base, long* offset);

/*Função para codificar uma palavra*/
long long int codifica(long* base, long* offset,int vaga,long maxcode);

/*Função para montar um dicionario contendo as palavras, o tamanho dos seus códigos e seus códigos em número inteiro*/
void monta_dicionario(vocabulario* vocab,long* base, long* offset,long* comprimentos, dicionario* dic);

#endif
