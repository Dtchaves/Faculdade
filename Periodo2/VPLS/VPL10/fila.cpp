#include "fila.h"
#include <bits/stdc++.h>

//Construtor
Fila::Fila()
{
    primeiro_ = nullptr;
    ultimo_ = nullptr;

}

string Fila::primeiro()
{
    return primeiro_-> chave;
}

string Fila::ultimo()
{
    return ultimo_ -> chave;
}

bool Fila::vazia()
{
    return (primeiro_ == nullptr && ultimo_ == nullptr);
}

void Fila::Inserir(string k)
{
    No* aux = new No;
    aux->chave = k;
    if(ultimo_ != nullptr) ultimo_-> proximo = aux;
    else primeiro_ = aux;
    aux->proximo = nullptr;
    ultimo_ = aux;
}

void Fila::Remover()
{
    No* aux = primeiro_->proximo;
    if(primeiro_->proximo == nullptr) ultimo_ = nullptr;
    delete primeiro_;
    primeiro_ = aux;
}

int Fila::tamanho()
{
    int contador = 0;
    No* i;
    for (i = primeiro_; i != nullptr; i = i->proximo)
    {
        contador++;
    }
    return contador;
}

//Destrutor
Fila::~Fila()
  {
    while(!vazia())
    {
        Remover();
    }
  }