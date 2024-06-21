/*Crie uma estrutura chamada Retângulo. Essa estrutura deverá conter o ponto
superior esquerdo e o ponto inferior direito do retângulo. Cada ponto é definido
por uma estrutura Ponto, a qual contém as posições X e Y. Faça um programa que
declare e leia uma estrutura Retângulo e exiba a área e o comprimento da diagonal
e o perímetro desse retângulo.*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ret{
	float superioresquerdox,superioresquerdoy;
	float inferiordireitox,inferiordireitoy;
}retangulo;

typedef struct ponto{
	float y;
	float x;

}ponto;

float area(retangulo ret) {
	float a;
	float n,m;

	n = ret.superioresquerdox - ret.inferiordireitox;
	m = ret.superioresquerdoy - ret.inferiordireitoy;
	a = n*m;

return abs(a);
}

float perimetro(retangulo ret) {
	float a;
	float n,m;

	n = ret.superioresquerdox - ret.inferiordireitox;
	m = ret.superioresquerdoy - ret.inferiordireitoy;
	a = n*2 + m*2;

return abs(a);
}

float diagonal(retangulo ret) {
	float a;
	float n,m;

	n = ret.superioresquerdox - ret.inferiordireitox;
	m = ret.superioresquerdoy - ret.inferiordireitoy;
	a = sqrt(n*n + m*m);

return abs(a);
}

int confereponto(retangulo ret,ponto p) {
	if ( p.x <= ret.superioresquerdox && p.y <= ret.superioresquerdoy && p.x >= ret.inferiordireitox && p.y >= ret.inferiordireitoy){
		return 1;
	}
		else {
			return 0;		
		}

}


void main () {

	retangulo teste;
	float a,d,p;
	ponto preguica;
	
	printf("coloque o superior esquerdo: ");
	scanf("%f %f",&teste.superioresquerdox,&teste.superioresquerdoy);
	printf("coloque o inferior direito: ");
	scanf("%f %f",&teste.inferiordireitox,&teste.inferiordireitoy);

	a = area(teste);
	d = diagonal(teste);
	p = perimetro(teste);

	printf("area=%0.2f diagonal=%0.2f perimetro=%0.2f\n",a,d,p);

	scanf("%f %f",&preguica.x,&preguica.y);
		if (confereponto(teste,preguica)) {
			printf("Pertence\n");		
		}
			else{
				printf("Nao pertence\n");
			}
}







