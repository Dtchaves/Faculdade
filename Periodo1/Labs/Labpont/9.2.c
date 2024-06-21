#include <stdio.h>

void imprime(int vetor[], int n){
int i;

	for(i = 0; i < n; i++){
		printf("%i ",vetor[i]);
	}
	printf ("\n");
}

void multiplica(int vetor[], int n, double v){
int i,aux;

	for(i = 0; i < n; i++){
	    aux = (int) vetor[i]*v;
		printf("%i ", aux);
	}
	printf ("\n");
}

void main (){

int n;
scanf ("%i",&n);

int vet[n],i;
double v;

	for(i = 0; i < n; i++){
		scanf("%i ",&vet[i]);
	}
scanf("%lf",&v);

imprime(vet,n);
multiplica(vet,n,v);
imprime(vet,n);
}




