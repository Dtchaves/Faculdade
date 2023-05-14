#ifndef NO
#define NO

#include <iostream>

using namespace std;

//Classe usada para representar um No da Arvore
class No{
    public:
    //Construtor da Classe No
    No();

    private:
    //Cada no contem uma string que representa um numero ou um operador
    string Elemento;
    /*Sendo uma árvore binária balanceada para cada Nó (menos as folhas) vão se conectar com 
    dois outros, representados por esses ponteiros Direita e Esquerda*/
    No* Direita;
    No* Esquerda;
    //Para permitir o acesso dos atributos privados dessa classe pela classe Arvore
    friend class Arvore;
};

#endif