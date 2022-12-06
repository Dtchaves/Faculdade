#include "racional.h"

#include<iostream>
#include<string>
#include <cmath>

using namespace std;

  ostream& operator<<(ostream& out, Racional r){
    out<<r.numerador()<<"/"<<r.denominador();
    return out;
  }
  
  istream& operator>>(istream& in, Racional& r){
    int d,n;
    in>>d>>n;
    r = Racional(d,n);
    return in;
  } 

  Racional::Racional(){}

  Racional::Racional(int n):numerador_(n),denominador_(1){}

  Racional::Racional(int n, int d){
    if(d == 0) throw ExcecaoDivisaoPorZero();
    else{
      numerador_ = n;
      denominador_ = d;
      this->Simplificar();
    }
  } 

  int Racional::numerador() const{return numerador_;} 

  int Racional::denominador() const{return denominador_;}  

  Racional Racional::operator-() const{return Racional(-numerador_,denominador_);}  

  Racional Racional::operator+(Racional k) const{
    Racional aux( ((numerador_ * k.denominador_) + (denominador_* k.numerador_)), (denominador_ * k.denominador_) );
    aux.Simplificar();
    return Racional(aux.numerador_, aux.denominador_);
  }

  Racional Racional::operator-(Racional k) const{
    Racional aux( ((numerador_ * k.denominador_) - (denominador_* k.numerador_)), (denominador_ * k.denominador_) );
    aux.Simplificar();
    return Racional(aux.numerador_, aux.denominador_);
  }

  Racional Racional::operator*(Racional k) const{
    Racional aux( (numerador_* k.numerador_), (denominador_ * k.denominador_) );
    aux.Simplificar();
    return Racional(aux.numerador_, aux.denominador_);
  }

  Racional Racional::operator/(Racional k) const{
    Racional aux( (numerador_* k.denominador_ ), (denominador_ * k.numerador_) );
    aux.Simplificar();
    return Racional(aux.numerador_, aux.denominador_);
  }

  Racional::operator float() const{
    return float(numerador_)/float(denominador_);
  }

  Racional::operator string() const{
    return to_string(numerador_) + "/" + to_string(denominador_);
  }
  
  void Racional::Simplificar(){
    if(denominador_<0){
      numerador_*=-1;
      denominador_ *= -1;
    }
    if(numerador_== 0) denominador_ = 1;
    else{
      int nume =  numerador_;
      int deno = denominador_;
      for (int i = abs((int) fmin(nume,deno)); i > 1 ;i--){
        if(!(nume % i || deno %i)){
          numerador_ = nume/i;
          denominador_ = deno/i;
          break;
        }
      }
      if(denominador_ < 0) denominador_ *= - 1; 
    }

  }
  
