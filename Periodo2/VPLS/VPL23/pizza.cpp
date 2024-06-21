#include "pizza.hpp"

using std::to_string;

std::string Pizza::descricao() const {
  // TODO: Implemente este metodo.
  /*
   * Note que aqui voce deve retornar uma descricao detalhada da pizza.
   *
   * Exemplos:
   * 2X Pizza Calabresa, 4 pedacos e borda recheada.
   * 2X Pizza Calabresa, 4 pedacos sem borda recheada.
   */
  if(borda_recheada) return to_string(m_qtd) + "X Pizza " + sabor + ", " + to_string(pedacos) + " pedacos e borda recheada.";
  else return to_string(m_qtd) + "X Pizza " + sabor + ", " + to_string(pedacos) + " pedacos e sem borda recheada.";
}

Pizza::Pizza(const std::string& sabor,
             int pedacos,
             bool borda_recheada,
             int qtd,
             float valor_unitario):sabor(sabor),pedacos(pedacos),borda_recheada(borda_recheada) {
  m_qtd =qtd;
  m_valor_unitario = valor_unitario;
}
