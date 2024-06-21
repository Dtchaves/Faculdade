#include "pedido.hpp"

using namespace std;

Pedido::~Pedido() {
  // TODO: Implemente este metodo.
  /**
   * Aqui voce deve deletar os ponteiros contidos na lista m_produtos
   */
  while(!m_produtos.empty())
  {
      auto it = m_produtos.begin();
      delete *it;
      m_produtos.erase(it);
  }
}

void Pedido::setEndereco(const std::string& endereco) {m_endereco = endereco;}

float Pedido::calculaTotal() const {
float total = 0;
for(auto it = m_produtos.begin();it != m_produtos.end();it++){
  total += ((*it)->getQtd()) *((*it)->getValor());
}
return total;
}

void Pedido::adicionaProduto(Produto* p) {m_produtos.push_back(p);}

std::string Pedido::resumo() const {
  // TODO: Implemente este metodo.
  /**
   * Aqui voce deve percorrer a lista de produtos para criar um resumo completo
   * do pedido. A cada iteracao, utilize o metodo descricao de cada produto para
   * montar o resumo do pedido. Por fim, adicione o endereco de entrega.
   *
   */
  string aux = "";
  for(auto it = m_produtos.begin();it != m_produtos.end();it++)
  {
    aux += ((*it)->descricao()) + '\n';
  }
  aux += "Endereco: ";
  aux += m_endereco;
  aux += '\n';
  return aux;
}