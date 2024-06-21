#include <stdio.h>
#include <stdlib.h>

void escanear(double vet[], int n){
int j;
for (j = 0; j < n ; j++){
	scanf("%lf",&vet[j]);
} 
}


void media(double vet[], int n, int *i){
int j;
double media,aux;
media = 0;
for (j = 0; j < n ; j++){
	media += vet[j];
} 
media = media/n;

*i = 0;
aux = abs(vet[*i] - media);
for (j = 0; j < n ; j++){
	if((abs(vet[j] - media)) < aux){
		*i = j;
		aux = abs(vet[*i] - media);
	}
} 

}


void main (){
int n;
scanf("%i",&n);

double vet[n];
int i;
escanear(vet,n);
media(vet,n,&i);
printf("%i",i);

}




