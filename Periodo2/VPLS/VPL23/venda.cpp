#include "venda.hpp"

#include <iomanip>

using namespace std;

Venda::~Venda() {
  // TODO: Implemente este metodo
  /**
   * Aqui voce deve deletar os ponteiros contidos na lista m_pedidos
   */
  while(!m_pedidos.empty())
  {
      auto it = m_pedidos.begin();
      delete *it;
      m_pedidos.erase(it);
  }
}

void Venda::adicionaPedido(Pedido* p) {m_pedidos.push_back(p);}

void Venda::imprimeRelatorio() const {
  // TODO: Implemente este metodo
  /**
   * Aqui voce tem que percorrer a lista de todos os pedidos e imprimir o resumo
   * de cada um. Por ultimo, devera ser exibido o total de venda e a quantidade
   * de pedidos processados.
   */
   int contador = 1;
  float total;
  string aux = "";
  for(auto it = m_pedidos.begin();it != m_pedidos.end();it++) {
    total += ((*it)->calculaTotal());
    aux += "Pedido " + to_string(contador) + '\n';
    contador++;
    aux += ((*it)->resumo());
  }
  cout<<aux;
  cout<<"Relatorio de Vendas"<<endl;
  cout<<setprecision(7)<<"Total de vendas: R$ "<<total<<"0"<<endl<<"Total de pedidos: "<<m_pedidos.size();
}