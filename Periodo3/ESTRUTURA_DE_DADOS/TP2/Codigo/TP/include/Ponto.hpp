#ifndef PONTO_
#define PONTO_

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

/*Classe que representa as coordenadas (X,Y), ou seja, um ponto no plano cartesiano*/
class Ponto{
    public:
    /*Construtor da classe padrão*/
    Ponto();

    /*Monta o ponto quando temos os valores de X e Y*/
    void Monta_Ponto(int Eixo_X,int Eixo_Y);

    /*Função que retorna o ponto no formato "(X,Y)" em uma string*/
    string Retorna_Ponto();

    /*Retorna a Distancia Euclidiana entre dois pontos*/
    float Distancia(Ponto Ponto_2);

    /*Retorna o Angulo entre dois pontos*/
    float Angulo(Ponto Ponto_2);

    private:
    /*Todo ponto tem coordenadas (X,Y)*/
    int X;
    int Y;

    friend class Reta;
    friend class Fecho_Convexo;
};



#endif
