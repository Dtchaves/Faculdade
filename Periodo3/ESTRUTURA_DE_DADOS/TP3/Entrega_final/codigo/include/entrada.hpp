#ifndef ENTRADA_
#define ENTRADA_

#include<iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

/*Struct para enviar um erro no try catch quando temos um argv com mais argumentos que o necessário
Usado na função le_args*/
typedef struct muitos_argumentos{
    int argumentos;
}muitos_argumentos;

/*Struct para enviar um erro no try catch quando temos um argv sem os argumentos necessários
Usado na função le_args*/
typedef struct poucos_argumentos{
    int argumentos;
}poucos_argumentos;

/*Struct para enviar um erro no try catch quando temos como entrada um arquivo inválido
Usado na função le_args*/
typedef struct arquivo_invalido{
    string invalido;
}arquivo_invalido;

/*Struct para enviar um erro no try catch quando temos como entrada uma opção inválida
Usado na função le_args*/
typedef struct opcao_invalida{
    string invalido;
}opcao_invalida;

/*Função para ler os argumentos da linha de comando enviando exceções quando necessário*/
void le_args(int argc,char ** argv,ifstream& arquivo_de_entrada,ofstream& arquivo_de_saida,string& opcao);

#endif
