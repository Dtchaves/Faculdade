#ifndef LEITURA_ENTRADA
#define LEITURA_ENTRADA

#include<iostream>
#include <iomanip>
#include<Pilha.hpp>
#include<Arvore.hpp>

using namespace std;

/*Struct para enviar um erro no try cath quando temos um argv com mais argumentos que o necessário
Usado na função Abre_Arquivo*/
typedef struct Muitos_Argumentos{
    int Argumentos;
}Muitos_Argumentos;

/*Struct para enviar um erro no try cath quando temos um argv sem os argumentos necessários
Usado na função Abre_Arquivo*/
typedef struct Poucos_Argumentos{
    int Argumentos;
}Poucos_Argumentos;

/*Struct para enviar um erro no try cath quando temos como entrada um arquivo inválido
Usado na função Abre_Arquivo*/
typedef struct Arquivo_Invalido{
    string Invalido;
}Arquivo_Invalido;

//Função para abrir o arquivo lido na linha de comando enviando exceções quando necessário
FILE* Abre_Arquivo(int argc,char ** argv);

//Funcão que retorna o que deve ser feito("LER" ou "POSFIXA" ou "INFIXA" ou "RESOLVA")
string Retorna_Funcao(string* Entrada, int *i);

//Função que retorna o tamanho da entrada pois se for maior que 1000 é inválido
int Conta_Tamanho_Entrada(string Expressao);

//Funcao que retorna se a expressão é válida ou não
bool Expressao_Valida(string Tipo_da_Expressao,string Expressao);

//Funcao que armazena a expressão em uma arvore chamando a função Arvore::Montar_Arvore
bool Armazenar(Arvore* Armazenamento,string Expressao,string Tipo_da_Expressao);

//Função para a leitura de uma expressão chamando a função "Armazenar" para armazena-la
bool Ler_Expressao(int i,string Entrada,Arvore* Armazenamento);

//Função para retornar a forma "POSFIXA" chamando a função Arvore::Retorna_Posfixa
void Retornar_Posfixa(bool Expressao_Valida,Arvore* Armazenamento);

//Função para retornar a forma "INFIXA" chamando a função Arvore::Retorna_Infixa
void Retornar_Infixa(bool Expressao_Valida,Arvore* Armazenamento);

//Função para retornar o resultado chamando a função Arvore::Retorna_Resultado
void Retornar_Resultado(bool Expressao_Valida,Arvore* Armazenamento);


#endif
