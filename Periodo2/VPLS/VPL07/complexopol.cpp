
#include "complexo.h"

#include <cmath>

Complexo::Complexo() {
    real_ = 0.0;
    imag_ = 0.0;
}

Complexo::Complexo(double a, double b) {
  imag_ = atan(b/a);
  real_ = sqrt(pow(a,2)+pow(b,2));
}

double Complexo::real() {
  return cos(imag_)*real_;
}

double Complexo::imag() {
  return sin(imag_)*real_;
}

bool Complexo::igual(Complexo x) {
  bool retorno = false;
  if (x.real_ == real_ && x.imag_ == imag_) retorno = true;
  return retorno;
}

void Complexo::Atribuir(Complexo x) {
  *this = x;
}

double Complexo::modulo() {
  return real_;
}

Complexo Complexo::conjugado() {
  Complexo c;
  c.real_ = real_;
  c.imag_ = -imag_;
  return c;
}

Complexo Complexo::simetrico() {
  Complexo c;
  c.imag_ = imag_ + 4*atan(1); // seria imag_ + pi
  return c;
}

Complexo Complexo::inverso() {
  Complexo i;
  double a,b;
  a = cos(imag_)*real_;
  b = sin(imag_)*real_;
  double denominador = pow(a,2) - pow(b,2);
  i.imag_ = a/denominador;
  i.real_ = b/denominador;
  return i;
}

Complexo Complexo::somar(Complexo y) {
  Complexo s;
  double a,b,ya,yb;
  a = cos(imag_)*real_;
  b = sin(imag_)*real_;
  ya = cos(y.imag_)*y.real_;
  yb = sin(y.imag_)*y.real_;

  s.real_ = a + ya;
  s.imag_ = b + yb;
  return s;
}

Complexo Complexo::subtrair(Complexo y) {
  Complexo s;
  double a,b,ya,yb;
  a = cos(imag_)*real_;
  b = sin(imag_)*real_;
  ya = cos(y.imag_)*y.real_;
  yb = sin(y.imag_)*y.real_;

  s.real_ = a - ya;
  s.imag_ = b - yb;
  return s;
}

Complexo Complexo::multiplicar(Complexo y) {
  Complexo p;
  p.real_ = real_ * y.real_;
  p.imag_ = imag_ + y.imag_;
  return p;
}

Complexo Complexo::dividir(Complexo y) {
  Complexo d;
  d.real_ = real_/y.real_;
  d.imag_ = imag_ - y.imag_;
  return d;
}