#ifndef DESCOMPACTAR_
#define DESCOMPACTAR_

#include<iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <huffman.hpp>
#include <hash.hpp>
#include <utilidades.hpp>

using namespace std;

/*Função para ler bit a bit do arquivo de entrada*/
int le_bit(ifstream& arquivo_de_entrada);

/*Função para ler do arquivo de entrada as palavras que vão ser usadas e suas frequências*/
vocabulario* ler_chave(ifstream& arquivo_de_entrada);

/*Função para escrever no arquivo descompactado*/
void escrever_descompactado(ifstream& arquivo_de_entrada,ofstream& arquivo_de_saida,long* base, long* offset,long* comprimentos,vocabulario* vocab,dicionario* dic, long tamanho);

/*Função para descompactar o arquivo de entrada no de saida*/
void descompactar(ifstream& arquivo_de_entrada,ofstream& arquivo_de_saida);

#endif