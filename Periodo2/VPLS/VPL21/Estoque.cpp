#include <bits/stdc++.h>

#include "Estoque.hpp"

void Estoque::add_mercadoria(const std::string& mercadoria, unsigned int qtd) {
    if(produtos_.find(mercadoria) == produtos_.end()) produtos_[mercadoria] = qtd;
    else produtos_[mercadoria] += qtd;
}

void Estoque::sub_mercadoria(const std::string& mercadoria, unsigned int qtd) {
    if(produtos_.find(mercadoria) == produtos_.end()) cout<<mercadoria<<" inexistente"<<endl;
    else if(qtd > produtos_[mercadoria]) cout<<mercadoria<<" insuficiente"<<endl;
         else produtos_[mercadoria] -= qtd;
}

unsigned int Estoque::get_qtd(const std::string& mercadoria) const {
    if(produtos_.find(mercadoria) != produtos_.end()) return (produtos_.find(mercadoria))->second;
  return 0;
}

void Estoque::imprime_estoque() const {
  for(auto it = produtos_.begin();it!=produtos_.end();it++){
    cout<<it->first<<", "<<it->second<<endl;
  }
}

Estoque& Estoque::operator += (const Estoque& rhs) {
  for(auto it = rhs.produtos_.begin();it!=rhs.produtos_.end();it++){
    add_mercadoria(it->first, it->second);
  }
  return *this;
}

Estoque& Estoque::operator -= (const Estoque& rhs) {
  for(auto it = rhs.produtos_.begin();it!=rhs.produtos_.end();it++){
    sub_mercadoria(it->first, it->second);
  }
  return *this;
}

bool operator < (Estoque& lhs, Estoque& rhs) {
  auto it = lhs.produtos_.begin();
  for(;it!=lhs.produtos_.end();it++){
    if(rhs.produtos_.find(it->first) == rhs.produtos_.end()) break;
    else if(rhs.produtos_.find(it->first)->second <= it->second) break;
  }
  
  if(it == lhs.produtos_.end()) return true;
  return false;
}

bool operator > (Estoque& lhs, Estoque& rhs) {
  auto it = rhs.produtos_.begin();
  for(;it!=rhs.produtos_.end();it++){
    if(lhs.produtos_.find(it->first) == lhs.produtos_.end()) break;
    else if(lhs.produtos_.find(it->first)->second <= it->second) break;
  }

  if(it == rhs.produtos_.end()) return true;
  return false;
  return false;
}