/* Escreva uma função que receba por parâmetro a altura e o raio de um cilindro
circular e retorne o volume desse cilindro. O volume de um cilindro circular é
calculado por meio da seguinte fórmula:
V = π * raio 2 * altura,
em que π = 3.1414592
 Escreva uma função para o cálculo do volume de uma esfera
V = 4/3π * r 3 ,
em que π = 3.1414592 valor do raio r deve ser passado por parâmetro */

#include <stdio.h>
#define pi 3.1414592

typedef struct cilindro{
double raio,altura;
}cilindro;

double volumedocilindro (cilindro x) {
double volume;

volume = pi * x.raio * x.raio * x.altura;

return volume;
}

double volumedaesfera (double raio) {
double volume;

volume = (4/(3*pi)) *raio*raio*raio;

return volume;
}


int main (){

cilindro entrada;
double raioentrada;

	printf("Coloque o raio do cilindro seguido da altura\n");
	scanf("%lf %lf",&entrada.raio,&entrada.altura);
	printf("Coloque o raio da esfera\n");
	scanf("%lf",&raioentrada);

	printf("O volume do cilindro é %lf e da esfera é %lf\n",volumedocilindro(entrada),volumedaesfera(raioentrada));


return 0;
}


