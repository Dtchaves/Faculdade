#include "../include/Ponto.hpp"

Ponto::Ponto(){
}

void Ponto::Monta_Ponto(int Eixo_X,int Eixo_Y){
    X = Eixo_X;
    Y = Eixo_Y;
}

string Ponto::Retorna_Ponto(){
    /*Retorna o ponto (X,Y)*/
    string Retorno = "(" + to_string(X) + "," + to_string(Y) + ")";
    return Retorno;
}
float Ponto::Distancia(Ponto Ponto_2){
    /*Usando pitágoras para achar a distancia*/
    return sqrt(pow((Ponto_2.Y - Y),2) + pow((Ponto_2.X - X),2));
}

float Ponto::Angulo(Ponto Ponto_2){
    float Delta_Y = (Ponto_2.Y - Y);
    float Delta_X = (Ponto_2.X - X);
    float Angulo;

    /*Para achar o angulo temos Delta_Y/Delta_X.Caso os dois sejam 0 temos o angulo entre o ponto e ele mesmo, logo atribuimos o angulo como 0*/
    if((Delta_X == 0)&&(Delta_Y == 0)){
        Angulo = 0.0;/*0 graus*/
    }
    else{
        Angulo = atan2(Delta_Y,Delta_X);
    }
    return Angulo;
}