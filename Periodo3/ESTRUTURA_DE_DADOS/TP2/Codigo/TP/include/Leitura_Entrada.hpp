#ifndef LEITURA_ENTRADA_
#define LEITURA_ENTRADA_

#include<iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include<Pilha.hpp>
#include<Ponto.hpp>

using namespace std;

/*Struct para enviar um erro no try catch quando temos um argv com mais argumentos que o necessário
Usado na função Abre_Arquivo*/
typedef struct Muitos_Argumentos{
    int Argumentos;
}Muitos_Argumentos;

/*Struct para enviar um erro no try catch quando temos um argv sem os argumentos necessários
Usado na função Abre_Arquivo*/
typedef struct Poucos_Argumentos{
    int Argumentos;
}Poucos_Argumentos;

/*Struct para enviar um erro no try catch quando temos como entrada um arquivo inválido
Usado na função Abre_Arquivo*/
typedef struct Arquivo_Invalido{
    string Invalido;
}Arquivo_Invalido;

/*Struct para armazenar os dados de entrada em um vetor de pontos e seu tamanho*/
typedef struct Vetor_de_Ponto_e_seu_Tamanho{
    Ponto* Vetor_Pontos;
    int Tamanho;
}Pontos_Quantidade;

/*Função para abrir o arquivo lido na linha de comando enviando exceções quando necessário*/
ifstream Abre_Arquivo(int argc,char ** argv);

/*Função para ler o arquivo e retornar uma Pilha de pontos*/
Pontos_Quantidade* Le_Arquivo(ifstream* Arquivo_de_Entrada);

#endif
