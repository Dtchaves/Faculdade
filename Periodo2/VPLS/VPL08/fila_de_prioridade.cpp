#include "fila_de_prioridade.h"

#include <list>
#include <string>
#include <vector>

using std::string;
using std::vector;

void FilaDePrioridade::Adicionar(Pessoa p) {
  lista_.push_back(p);
  list<Pessoa>::iterator it,aux,parada,inicio;
  it = lista_.end();
  it--;
  it--;
  aux = lista_.end();
  aux--;
  parada = lista_.begin();
  parada--;
  Pessoa troca;
  while(it!= parada)
  {
    if(aux->prioridade > it->prioridade)
    {        
      troca = *aux;
      *aux = *it;
      *it = troca;
      aux = it; 
    }
    it--;
  }


}

string FilaDePrioridade::RemoverMaiorPrioridade() {
  string nome;
  list<Pessoa>::iterator it = lista_.begin();
  nome = it->nome;
  lista_.erase(it);

  return nome;
}

void FilaDePrioridade::Remover(string nome) {
  list<Pessoa>::iterator it = lista_.begin( ),parada = lista_.end(),aux;
  while(it!= parada)
  {
    if(nome == it->nome)
    {
      aux = lista_.erase(it);
      it = aux;
    }
    else it++;
  }
}

int FilaDePrioridade::tamanho() {
  return lista_.size();
}

vector<string> FilaDePrioridade::listar() {
  vector<string> v;
  list<Pessoa>::iterator it ;
  for(it = lista_.begin( );it!= lista_.end();it++)
  {
    v.push_back(it->nome);
  }
  return v; 
}