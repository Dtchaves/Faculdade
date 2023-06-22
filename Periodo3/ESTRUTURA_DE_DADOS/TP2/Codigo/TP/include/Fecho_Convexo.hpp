#ifndef FECHO_CONVEXO_
#define FECHO_CONVEXO_

#include <iostream>
#include <string>
#include <cmath>

#include <Pilha.hpp>
#include <Reta.hpp>
#include <Ponto.hpp>



using namespace std;

    /*Struct para enviar um erro no try catch quando a função "Montar_Fecho_Convexo" é chamada e o algoritmo escolhido não é 
    "Grahamscan" nem "Jarvismarch"*/
typedef struct Algoritmo_Invalido{
    string Algoritmo;
}Algoritmo_Invalido;

/*Struct para enviar um erro no try catch quando a função "Montar_com_graham_scan" é chamada e a forma de ordenação escolhido não é 
"MergeSort" nem "InsertionSort" nem "BucketSort"*/
typedef struct Ordenacao_Invalida{
    string Ordenacao;
}Ordenacao_Invalida;

/*Classe que representa o fecho convexo*/
class Fecho_Convexo{
    public:
    /*Construtor da Classe*/
    Fecho_Convexo();

    /*Função para montar o fecho convexo dado um vetor de pontos. Nessa função é necessário escolher o algoritmo de achar o fecho e o algoritmo de ordenação desejado.Chama as 
    funções "Montar_com_jarvis_march" e "Montar_com_graham_scan" de acordo com a opção escolhida*/
    void Montar_Fecho_Convexo(string Algoritmo, string Ordenacao,Ponto* Vetor_Entrada,int Tamanho_Entrada);

    /*Função para imprimir o fecho armazenado*/
    void Imprimir_Fecho_Convexo();

    private:
    /*Chamada pela função "Montar_Fecho_Convexo" monta o fecho utilizando o algoritmo de Jarvis March*/
    void Montar_com_jarvis_march(Ponto* Vetor_Entrada,int Tamanho_Entrada);

    /*Função que retorna a orientação entre duas retas formadas pelos pontos fornecidos*/
    int Orientacao(Ponto Ponto_ultimo,Ponto Ponto_atual,Ponto Ponto_analise);

    /*Chamada pela função "Montar_Fecho_Convexo" monta o fecho utilizando o algoritmo de Graham scan. Como entrada é necessário afirmar qual algoritmo de ordenação vai ser 
    utilizado. Essa função chama uma das funções "Merge_sort_Graham_scan", "Insertion_sort_Graham_scan" e "Bucket_sort_Graham_scan" de acordo com o método escolhido*/
    void Montar_com_graham_scan(Ponto* Vetor_Entrada,int Tamanho_Entrada,string Ordenacao);

    /*Chamada pela função "Montar_com_graham_scan" ordena o vetor de retas passado como argumento de acordo com o angulo de cada reta utilizando o "MergeSort"*/
    void Merge_sort_Graham_scan(Reta* Vetor_Entrada, int Inicio,int Fim);
    /*Chamada pela função "Merge_sort_Graham_scan" auxilia na ordenação por "MergeSort"*/
    void Merge(Reta* Vetor_Entrada,int Inicio,int Metade,int Fim);

    /*Chamada pela função "Montar_com_graham_scan" ordena o vetor de retas passado como argumento de acordo com o angulo de cada reta utilizando o "InsertionSort"*/
    void Insertion_sort_Graham_scan(Reta* Vetor_Entrada,int Tamanho_Entrada);

    /*Chamada pela função "Montar_com_graham_scan" ordena o vetor de retas passado como argumento de acordo com o angulo de cada reta utilizando o "BucketSort"*/
    void Bucket_sort_Graham_scan(Reta* Vetor_Entrada,int Tamanho_Entrada);


    /*Uma pilha de pontos que representa o Fecho convexo em si*/
    Pilha<Ponto> Fecho;
};



#endif
