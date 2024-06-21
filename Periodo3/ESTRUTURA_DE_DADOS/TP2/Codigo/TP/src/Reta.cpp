#include "../include/Reta.hpp"

Reta::Reta(){
}

void Reta::Monta_Reta(Ponto Ponto_1, Ponto Ponto_2){
    float Delta_Y = (Ponto_2.Y - Ponto_1.Y);
    float Delta_X = (Ponto_2.X - Ponto_1.X);

    A = Delta_Y/Delta_X;
     /*Podemos achar o b usando a seguinte equação: y - Ax = b*/
    B =(Ponto_1.Y) - (A*Ponto_1.X);
        
    /*Atribuindo os valores dos pontos*/
    this->Ponto_1 = Ponto_1;
    this->Ponto_2 = Ponto_2;

    /*Atribuindo o angulo*/
    Angulo = this->Ponto_1.Angulo(this->Ponto_2);
}

string Reta::Retorna_Reta(){
    /*Para imprimir uma reta Ax + B*/
    string Retorno = to_string(A) + " x + " + to_string(B);
    return Retorno;
}

