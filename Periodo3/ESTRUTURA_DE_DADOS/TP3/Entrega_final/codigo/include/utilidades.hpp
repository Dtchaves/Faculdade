#ifndef UTILIDADES_
#define UTILIDADES_

#include<iostream>
#include <fstream>
#include <string>

using namespace std;

/*Struct para representar uma palavra e a quantidade de vezes que ela aparece*/
typedef struct palavra_ocorrencia{
    string palavra;
    int ocorrencia;
}palavra_ocorrencia;

/*Struct que representa um vetor do tipo palavra_ocorrencia e seu tamanho*/
typedef struct vetor_palavra_ocorrencia{
    palavra_ocorrencia* vetor;
    long tamanho;
}vocabulario;

/*Struct para armazenar uma palavra, seu código e o tamanho do seu código*/
typedef struct palavra_codigo{
    string palavra;
    long long int codigo;
    long num_bits;
}dicionario;

/*Função para calcular a soma das letras de uma palavra*/
int soma_letras(const string texto);

/*Funções para fazer um quicksort com melhoria na escolha de pivo para ordenar 
as palavras pelas suas frequencias*/
void particao(int esq, int dir,int *i, int *j, palavra_ocorrencia *vetor);
void ordena(int esq, int dir, palavra_ocorrencia* vetor);
void quicksort(palavra_ocorrencia* vetor, long tamanho);

#endif