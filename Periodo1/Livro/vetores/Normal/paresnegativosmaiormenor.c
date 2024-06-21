#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main () {

int contadorpar = 0,contadornegativo = 0,maiornumero = INT_MIN,menornumero = INT_MAX ,soma = 0,i;
int vet[10];

for(i = 0; i<10; i++) {
	scanf("%i",&vet[i]);
}

for(i = 0; i<10; i++) {
	soma += vet[i];

		if(vet[i] % 2 ==0){
			contadorpar++;
		}
		
		if(vet[i] < 0){
			contadornegativo++;
		}

		if(vet[i]>maiornumero){
			maiornumero = vet[i];
		}
		
		if(vet[i]<menornumero){
			menornumero = vet[i];
		}
}


printf("\n");

printf(" Esse vetor possui %i numeros pares %i numeros negativos, seu maior número é %i, seu menor é %i e sua soma é %i\n",contadorpar,contadornegativo,maiornumero,menornumero,soma);


return 0;
