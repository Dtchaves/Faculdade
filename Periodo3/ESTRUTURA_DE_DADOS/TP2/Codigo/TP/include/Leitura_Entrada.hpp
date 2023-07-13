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

/*Função para abrir o arquivo lido na linha de comando enviando exceções quando necessário*/
ifstream Abre_Arquivo(int argc,char ** argv);

#endif
