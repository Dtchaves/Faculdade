#ifndef COMPACTAR_
#define COMPACTAR_

#include<iostream>
#include <fstream>
#include <string>
#include <hash.hpp>
#include <huffman.hpp>
#include <utilidades.hpp>

using namespace std;

/*Função para escrever bit a bit no arquivo de saída*/
void escreve_bit(int bit, ofstream& arquivo);

/*Função para receber um arquivo de entrada e realizar a leitura, retornando as palavras 
que esse arquivo apresenta e sua frequência*/
vocabulario* ocorrencia_com_hash(ifstream& arquivo_de_entrada);

/*Função para escrever do arquivo de saida  as palavras que foram usadas e suas frequências*/
void escrever_chave(ifstream& arquivo_de_entrada,ofstream& arquivo_de_saida,vocabulario* vocab);

/*Função para escrever no arquivo compactado*/
void escrever_compactado(ifstream& arquivo_de_entrada,ofstream& arquivo_de_saida,int tamanho, dicionario* dic );

/*Função para compactar o arquivo de entrada no de saida*/
void compactar(ifstream& arquivo_de_entrada,ofstream& arquivo_de_saida);

#endif