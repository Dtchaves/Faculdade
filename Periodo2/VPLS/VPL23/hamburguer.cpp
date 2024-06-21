#include "hamburguer.hpp"

using namespace std;

std::string Hamburguer::descricao() const {
  // TODO: Implemente este metodo.
  /*
   * Note que aqui voce deve retornar uma descricao detalhada do Hamburguer.
   *
   * Exemplos:
   * 1X Hamburguer X-tudo artesanal.
   * 1X Hamburguer X-tudo simples.
   */
  if(artesanal) return to_string(m_qtd) + "X Hamburguer " + tipo + " artesanal.";
  else return to_string(m_qtd) + "X Hamburguer " + tipo + " simples.";
}

Hamburguer::Hamburguer(const std::string& tipo,                       
                       bool artesanal,
                       int qtd,
                       float valor_unitario):tipo(tipo),artesanal(artesanal){
  m_qtd =qtd;
  m_valor_unitario = valor_unitario;
}
