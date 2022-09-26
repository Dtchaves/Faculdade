#include "racional.hpp"

#include <cmath>
#include <iostream>



void Racional::Normalizar() {
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
  int nume =  numerador_;
  int deno = denominador_;

  for (int i = abs((int) fmin(nume,deno)); i > 1 ;i--)
  {
    if(!(nume % i || deno %i))
    {
      nume = nume/i;
      deno = deno/i;
      break;
    }
  }

  return Racional(-nume,deno);
}

Racional Racional::somar(Racional k) const {
  int deno =  denominador_ * k.denominador_;
  int nume = (numerador_ * k.denominador_) + (denominador_* k.numerador_) ;

  for (int i = abs((int) fmin(nume,deno)); i > 1 ;i--)
  {
    if(!(nume % i || deno %i))
    {
      nume = nume/i;
      deno = deno/i;
      break;
    }
  }

  return Racional(nume, deno);
}

Racional Racional::subtrair(Racional k) const {
  int deno =  denominador_ * k.denominador_;
  int nume = (numerador_ * k.denominador_) - (denominador_* k.numerador_) ;

  for (int i = abs((int) fmin(nume,deno)); i > 1 ;i--)
  {
    if(!(nume % i || deno %i))
    {
      nume = nume/i;
      deno = deno/i;
      break;
    }
  }

  return Racional(nume, deno);
}

Racional Racional::multiplicar(Racional k) const {
  int nume =  numerador_* k.numerador_;
  int deno = denominador_ * k.denominador_;

  for (int i = abs((int) fmin(nume,deno)); i > 1 ;i--)
  {
    if(!(nume % i || deno %i))
    {
      nume = nume/i;
      deno = deno/i;
      break;
    }
  }

  return Racional(nume,deno);
}

Racional Racional::dividir(Racional k) const {
  int nume =  numerador_* k.denominador_ ;
  int deno = denominador_ * k.numerador_;

  for (int i = abs((int) fmin(nume,deno)); i > 1 ;i--)
  {
    if(!(nume % i || deno %i))
    {
      nume = nume/i;
      deno = deno/i;
      break;
    }
  }

  return Racional(nume,deno);
}

