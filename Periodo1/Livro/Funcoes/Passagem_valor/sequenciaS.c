#include <stdio.h>


double buceta(double n){
double s = 0.0;

	double auxiliar = 2/4.0;
	double numerador = 2.0,ajuda = 1.0 , denominador = 4.0 ;


	while(auxiliar <= ((n*n) + 1)/(n+3)) {
		s += auxiliar;
		denominador++;
		ajuda++;
		numerador = ajuda*ajuda + 1;
		auxiliar = numerador/denominador;
		//printf("%lf\n\n",((n*n) + 1)/(n+3));
		//printf("%lf\n",auxiliar);
	}

return s;
}



void main (){

double x;

scanf("%lf",&x);
printf("%0.2lf",buceta(x));

}



