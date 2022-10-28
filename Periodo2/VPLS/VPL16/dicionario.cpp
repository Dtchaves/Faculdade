#include <bits/stdc++.h>
#include "dicionario.h"

using namespace std;

Dicionario::Dicionario()
{
    elementos_;
}

int Dicionario::tamanho()
{
    return elementos_.size();
}

bool Dicionario::pertence(string chave) 
{
    for(auto it = elementos_.begin();it != elementos_.end();it++)
    {
        if(it->chave == chave) return true;
    }
    return false;
}

string Dicionario::menor()
{
    list<string> help;

    for(auto it = elementos_.begin();it != elementos_.end();it++)
    {
        help.push_back(it->chave);
    }
    help.sort();
    return *(help.begin());
}

string Dicionario::valor(string chave)
{
    for(auto it = elementos_.begin();it != elementos_.end();it++)
    {
        if(it->chave == chave) return it->valor;
    }

    return "ops";
}

void Dicionario::Inserir(string chave, string valor)
{
    elementos_.push_back(Elemento {chave,valor});
}

void Dicionario::Remover(string chave)
{
    for(auto it = elementos_.begin();it != elementos_.end();it++)
    {
        if(it->chave == chave) 
        {
            elementos_.erase(it);
            break;
        }

    }
}

void Dicionario::Alterar(string chave, string valor)
{
    for(auto it = elementos_.begin();it != elementos_.end();it++)
    {
        if(it->chave == chave)  it->valor = valor;
    }
}

Dicionario::~Dicionario()
{
    elementos_.clear();
}