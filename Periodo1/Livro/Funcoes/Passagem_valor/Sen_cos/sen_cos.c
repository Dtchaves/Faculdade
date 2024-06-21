#include "sen_cos.h"


void conversor(angulo *x) {
x->radiano = (x->grau*2*pi)/360;
}

double fatorial (double x) {
double fat = 1;

double i;

	for(i = 2; i<=x;i++){
		fat *= i;
	}

return fat;
}

double seno (angulo x){
double sen = 0;
	
	conversor(&x);

	double n;
	for(n = 0;n<6;n++){
		sen += ((pow(-1,n))/fatorial((2*n) +1))*pow(x.radiano,(2*n) +1);
	}

return sen;
}

double cosseno (angulo x){
double cos = 0;
	
	conversor(&x);

	double n;
	for(n = 0;n<6;n++){
		cos += ((pow(-1,n))/fatorial((2*n)))*pow(x.radiano,(2*n));
	}

return cos;
}

