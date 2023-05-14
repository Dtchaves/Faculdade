#ifndef PILHA
#define PILHA

#include<iostream>

using namespace std;

/*Foi usado um "template" para que não fosse necessário implementar duas pilhas de elementos 
diferentes que possuem as mesmas fuções.*/

/*Struct para enviar um erro no try catch quando temos uma pilha vazia e queremos desempilhar*/
typedef struct Pilha_vazia{
    string Printar;
}Pilha_vazia;

/* Classe que representa um elemento do tipo T da lista encadeada na memória. */
template<class T>
class Elemento_da_Pilha{
public:
    //Construtor da classe Elemento_da_Pilha
    Elemento_da_Pilha(){
        Proximo = NULL;
    }
    //Os elementos do tipo T que vão ser enfileirados
    T Elemento;

    //Um ponteiro para o próximo elemento da pilha
    Elemento_da_Pilha<T>* Proximo;
};

/* Classe que representa uma pilha de elementos do tipo T que, nesse código podem ser "No*"" e "string" */
template<class T>
class Pilha{
public:
    //Construtor da classe Pilha
    Pilha(){
        Topo = NULL;
    }

    //Função que informa se a Pilha está vazia 
    bool Pilha_Vazia(){
        if(Topo == NULL){
            return true;
        }
        else{
            return false;
        }
    }

    //Função que adiciona elementos do tipo T no topo da pilha
    void Empilha( T Valor){
        Elemento_da_Pilha<T>* Auxiliar = new Elemento_da_Pilha<T>;
        Auxiliar->Elemento = Valor;

        if(Pilha_Vazia()){
            Topo = Auxiliar;
        }
        else{
            Auxiliar->Proximo = Topo;
            Topo = Auxiliar;
        }
    } 

    //Função que retorna o elemento do tipo T que está no topo da pilha e o apaga da pilha
    T Desempilha(){
        T Retorno;
        Elemento_da_Pilha<T>* Auxiliar = NULL;
        if(!Pilha_Vazia()){
            Retorno = Topo->Elemento;
            Auxiliar = Topo;
            Topo = Topo->Proximo;
            delete Auxiliar;
            return Retorno;
        }
        else {
            throw Pilha_vazia{"ERRO, PILHA VAZIA"};
        }
    }

    //Destrutor da classe Pilha
    ~Pilha(){
        while(!Pilha_Vazia())
        {
            Desempilha();
        }
    }
    private:
    //É o topo da pilha, sendo um elemento do tipo Elemento_da_Pilha<T>
    Elemento_da_Pilha<T> * Topo; 
    
};

//Função para montar uma pilha a partir de uma string
void Montar_Pilha_De_String(string Entrada,Pilha<string>* Retorno);

#endif