#ifndef ARVORE
#define ARVORE

#include <iostream>
#include <No.hpp>
#include <Pilha.hpp>

using namespace std;

/*Struct para enviar um erro no try catch quando temos algum problema e não conseguimos criar alguma pilha no meio das funções da árvore*/
typedef struct Erro_de_Montagem{
    string Printar;
}Erro_de_Montagem;

/*Struct para enviar um erro no try catch quando temos divisão por 0*/
typedef struct Divisão_Por_Zero{
    string Printar;
}Divisão_Por_Zero;

/*Uma class que representa uma Árvore no qual cada no é do tipo No e representa ou um número da expressão(se for uma folha) 
ou um operador*/
class Arvore{

    public:
    //Construtor da classe Arvore
    Arvore();

    //Informa se a Árvore está vazia 
    bool Arvore_Vazia();

    /* Função que monta a arvore recenbendo como entrada o tipo de expressão e uma string com a expressao. Retorna se 
    foi um sucesso ou não a montagem. Essa função chama ou a função Arvore::Montar_Arvore_Pela_Entrada_Infixa ou a função Arvore::Montar_Arvore_Pela_Entrada_Posfixa
    bool Infixa -> true = infixa & false = posfixa*/
    bool Montar_Arvore(string Entrada,bool Infixa);

    //Função para retornar a forma infixa
    string Retorna_Infixa();

    //Função para retornar a forma posfixa
    string Retorna_Posfixa();

    //Função para retornar o resultado
    double Retorna_Resultado();

    //Função para limpar a Árvore 
    bool Limpar_Arvore();

    //Destrutor da classe Árvore
    ~Arvore();


    private:
    //Função Recursiva para fazer a limpeza da Árvore
    void Limpa_Recursivo(No** p);

    //Função que caminha na árvore da forma "in ordem" para retorna a forma infixa
    string Caminha_In_Ordem_Adaptada(No* p);

    //Função que caminha na árvore da forma "pos ordem" para retornar a forma posfixa
    string Caminha_Pos_Ordem_Adaptada(No* p);

    //Monta a árvore, recebendo um char** como entrada, a partir de uma manipulação de Pilhas de No* e recursão
    No* Montar_Arvore_Pela_Entrada_Infixa(char** Entrada); 

    /*Monta a árvore, recebendo uma Pilha* de string e um ponteiro para o ponteiro que representa a raiz,
    desempilhando essa Pilha de forma estratégica e recursiva */
    void Montar_Arvore_Pela_Entrada_Posfixa(Pilha<string>* Entrada,No** p);
        
    //Usa uma função recursiva simples para resolver a expressão através das strings armazenadas na árvore
    double Resultado_Recursivo(No* p);

    //É o Nó inicial, a raiz da arvore binária
    No* Raiz; 
    
};



#endif
