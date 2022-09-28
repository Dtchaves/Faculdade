#include "complexo.h"
#include <cmath>

Complexo::Complexo() {
    real_ = 0.0;
    imag_ = 0.0;
}

Complexo::Complexo(double a, double b) {
    real_ = a;
    imag_ = b;
}

double Complexo::real() {
    return real_;
}

double Complexo::imag() {
    return imag_;
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
    return  sqrt((pow(real_,2))+(pow(imag_,2)));
}

Complexo Complexo::conjugado() {
    Complexo c;
    c.real_ = real_;
    c.imag_ = -imag_;
    return c;
}

Complexo Complexo::simetrico() {
    Complexo c;
    c.real_ = -real_;
    c.imag_ = -imag_;
    return c;
}

Complexo Complexo::inverso() {
    Complexo i;
    double denominador = pow(real_,2) - pow(imag_,2);
    i.imag_ = imag_/denominador;
    i.real_ = real_/denominador;
     return i;
}

Complexo Complexo::somar(Complexo y) {
    Complexo s;
    s.real_ = real_ + y.real_;
    s.imag_ = imag_ + y.imag_;
    return s;
}

Complexo Complexo::subtrair(Complexo y) {
    Complexo s;
    s.real_ = real_ - y.real_;
    s.imag_ = imag_ - y.imag_;
    return s;
}

Complexo Complexo::multiplicar(Complexo y) {
    Complexo p;
    p.imag_ = (real_*y.imag_) + (imag_*y.real_);
    p.real_ = (real_*y.real_) + (imag_*y.imag_);
    return p;
}

Complexo Complexo::dividir(Complexo y) {
    Complexo d;
    double denominador = pow(y.real_,2) - pow(y.imag_,2);
    d = this->multiplicar(y.conjugado());
    d.imag_ = imag_/denominador;
    d.real_ = real_/denominador;

    return d;
}