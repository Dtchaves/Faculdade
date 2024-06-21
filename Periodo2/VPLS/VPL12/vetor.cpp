#include <bits/stdc++.h>
#include "vetor.h"

using namespace std;

Vetor::Vetor(int inicio, int fim): inicio_(inicio),fim_(fim)
{   
    elementos_ = new string[abs(inicio - fim) +1]; 
    inicializados_ = new bool[abs(inicio - fim) +1];
    if(fim < inicio) throw IntervaloVazio {inicio,fim};
}

void Vetor::atribuir(int i, string valor)
{
    if(i < inicio_ || i > fim_) throw IndiceInvalido {inicio_,fim_,i};
    elementos_[i-inicio_] = valor;
    inicializados_[i-inicio_] = true;

}

string Vetor::valor(int i) const
{
    if(i < inicio_ || i > fim_) throw IndiceInvalido {inicio_,fim_,i};
    if(!inicializados_[i-inicio_]) throw IndiceNaoInicializado {i};
    return elementos_[i-inicio_];
}

Vetor::~Vetor()
{
    delete [] elementos_;
}