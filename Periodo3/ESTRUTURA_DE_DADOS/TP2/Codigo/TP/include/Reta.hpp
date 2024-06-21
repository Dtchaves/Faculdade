#ifndef RETA_
#define RETA_


#include <iostream>
#include <string>
#include <cmath>
#include <Ponto.hpp>

using namespace std;

/*Classe que representa uma equação Ax+B, ou seja, uma reta no plano cartesiano*/
class Reta{
    public:
    /*Construtor da classe*/
    Reta();

    /*Quando queremos construir a reta que passa entre dois pontos*/
    void Monta_Reta(Ponto Ponto_1, Ponto Ponto_2);

    /*Função que retorna a reta no formato "Ax+B" em uma string*/
    string Retorna_Reta();

    private:
    /*Pontos que deram origem a reta*/
    Ponto Ponto_1;
    Ponto Ponto_2;
    /*Reta tem o formato Ax + B*/
    float A;
    float B;
    /*Angulo formado pela reta*/
    float Angulo;
    
    friend class Fecho_Convexo;
};

#endif