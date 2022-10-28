#include <iostream>

#include "dicionario.h"

using namespace std;

int main() {
  Dicionario m;
  string operacao, chave, valor;
  while (cin >> operacao) {
    try {
      if (operacao == "m") {
        cout << m.menor() << endl;
      } else if (operacao == "t") {
        cout << m.tamanho() << endl;
      } else if (operacao == "p") {
        cin >> chave;
        if (m.pertence(chave)) {
          cout << "sim" << endl;
        } else {
          cout << "não" << endl;
        }
      } else if (operacao == "v") {
        cin >> chave;
        cout << m.valor(chave) << endl;
      } else if (operacao == "i") {
        cin >> chave >> valor;
        m.Inserir(chave, valor);
      } else if (operacao == "r") {
        cin >> chave;
        m.Remover(chave);
      } else if (operacao == "a") {
        cin >> chave >> valor;
        m.Alterar(chave, valor);
      } else {
        return 0;
      }
    } 
    catch(vazio) 
    {
    cout << "Não foi possível realizar a operação: Dicionário vazio" << endl;
    }
    catch(naopertence x) 
    {
    cout << "Não foi possível realizar a operação: A chave "  << x.chave << " não está no dicionário" << endl;
    }
    catch(japertence x) 
    {
    cout << "Não foi possível realizar a operação: A chave " << x.chave << " já está no dicionário" << endl;
    }
  }
}
