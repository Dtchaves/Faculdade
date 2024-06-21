#include <bits/stdc++.h>
#include "vetor.h"

using namespace std;

Vetor::Vetor(int inicio, int fim)
{   
    int size = abs(inicio - fim) +1;
    elementos_ = new string[size]; 
    inicio_ = inicio; 
}

void Vetor::atribuir(int i, string valor)
{
    elementos_[i-inicio_] = valor;
}

string Vetor::valor(int i) const
{
    return elementos_[i-inicio_];
}

Vetor::~Vetor()
{
    delete [] elementos_;
}