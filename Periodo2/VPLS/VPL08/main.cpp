#include "fila_de_prioridade.h"
#include <bits/stdc++.h>

using namespace std;

int main() {
  FilaDePrioridade fila;
  char op;
  while (cin >> op){
    if (op == 'a') {
      Pessoa p;
      cin >> p.nome;
      cin >> p.prioridade;
      fila.Adicionar(p);
    } else if (op == 'p') {
      string nome = fila.RemoverMaiorPrioridade();
      cout << nome << endl;
    } else if (op == 'r') {
      string nome;
      cin >> nome;
      fila.Remover(nome);
    } else if (op == 't') {
      cout << fila.tamanho() << endl;
    } else if (op == 'l') {
      for (auto nome : fila.listar()) {
        cout << nome << endl;
      }
    }
  };
  return 0;
}