#ifndef HASH_
#define HASH_

#include<iostream>
#include <fstream>
#include <string>
#include <utilidades.hpp>

#define MAX_HASH 1000

using namespace std;

/*Struct que representa um item da classe "elemento_hash_leitura"*/
typedef struct tipo_item_leitura{
    palavra_ocorrencia item;
    tipo_item_leitura* prox;
}tipo_item_leitura;

/*Classe que é uma espécie de uma pilha, sendo totalmente adaptada para 
ser usada para fazer um hash na hora de leitura, a fim de diminuir a complexidade de tempo
na hora de achar se certa palavra ja foi adicionada ou não e incrementar frequencias*/
class elemento_hash_leitura
{
    public:
    /*Construtor*/
    elemento_hash_leitura();
    /*Função que retorna se está vazio ou não*/
    bool vazio();
    /*Função que procura a palavra nos itens armazenados e incrementa a ocorrência se encontrar*/
    bool procura_incrementa(string p);
    /*Função para inserir uma nova palavra*/
    void insere(string item);
    /*Função para remover o ultimo item adicionado*/
    palavra_ocorrencia remove();
    /*Função para limpar os itens*/
    void limpa();
    /*Destrutor*/
    ~elemento_hash_leitura();

    private:
    tipo_item_leitura* primeiro;
};

/*Struct que representa um item da classe "elemento_hash_escrita"*/
typedef struct tipo_item_escrita{
    dicionario item;
    tipo_item_escrita* prox;
}tipo_item_escrita;

/*Classe que é uma espécie de uma pilha, sendo totalmente adaptada para 
ser usada para fazer um hash na hora de escrita, a fim de diminuir a complexidade de tempo
na hora de achar as palavras correspondentes a certo código ou vice-versa*/
class elemento_hash_escrita
{
    public:
    /*Construtor*/
    elemento_hash_escrita();
    /*Função que retorna se está vazio ou não*/
    bool vazio();
    /*Função que retorna o dicionario que contém o código passado como argumento*/
    dicionario procura_cod(long long int cod);
    /*Função que retorna o dicionario que contém a palavra passada como argumento*/
    dicionario procura_palavra(string palavra);
    void insere(dicionario entrada);
    /*Função para remover o ultimo item adicionado*/
    void remove();
    /*Função para limpar os itens*/
    void limpa();
    /*Destrutor*/
    ~elemento_hash_escrita();

    private:
    tipo_item_escrita* primeiro;
};

#endif
