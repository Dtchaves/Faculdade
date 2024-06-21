#include "racional.hpp"

#include <cmath>
#include <iostream>



void Racional::Normalizar() {
  int nume =  numerador_;
  int deno = denominador_;
  for (int i = abs((int) fmin(nume,deno)); i > 1 ;i--)
  {
    if(!(nume % i || deno %i))
    {
      numerador_ = nume/i;
      denominador_ = deno/i;
      break;
    }
  }
  if(denominador_ < 0) denominador_ *= - 1; 
}

Racional::Racional() {
    numerador_ = 0;
    denominador_ = 1;
}

Racional::Racional(int n)  {
    numerador_ = n;
    denominador_ = 1;
}

Racional::Racional(int n, int d) {
    numerador_ = n;
    if(d!= 0) denominador_ = d;

}

int Racional::numerador() const {
  return numerador_;
}

int Racional::denominador() const {
  return denominador_;
}

Racional Racional::simetrico() const{
  Racional aux( -numerador_,denominador_);
  aux.Normalizar();
  return Racional(aux.numerador_, aux.denominador_);
}

Racional Racional::somar(Racional k) const {

  Racional aux( ((numerador_ * k.denominador_) + (denominador_* k.numerador_)), (denominador_ * k.denominador_) );
  aux.Normalizar();
  return Racional(aux.numerador_, aux.denominador_);
}

Racional Racional::subtrair(Racional k) const {

  Racional aux( ((numerador_ * k.denominador_) - (denominador_* k.numerador_)), (denominador_ * k.denominador_) );
  aux.Normalizar();

  return Racional(aux.numerador_, aux.denominador_);
}

Racional Racional::multiplicar(Racional k) const {

  Racional aux( (numerador_* k.numerador_), (denominador_ * k.denominador_) );
  aux.Normalizar();

  return Racional(aux.numerador_, aux.denominador_);
}

Racional Racional::dividir(Racional k) const {

  Racional aux( (numerador_* k.denominador_ ), (denominador_ * k.numerador_) );
  aux.Normalizar();

  return Racional(aux.numerador_, aux.denominador_);
}

