/*Escreva uma função que receba como parâmetro um vetor contendo N valores in-
teiros. Essa função deve retornar, por referência, dois valores: a soma dos números
pares e ímpares.
*/

#include <stdio.h>

typedef struct somas{
long int pares,impares;
}somas;

somas calcularsomas(int v[]){
somas x;
int i;

x.pares = 0;
x.impares = 0;

for (i = 0; i<10;i++){
	if (v[i] % 2 == 0){
		x.pares+= v[i];
	}	
		else{
			x.impares+= v[i];
		}
}


return x;
}


int main () {
int i,v[10];

for(i = 0; i<10;i++){
	scanf("%i",&v[i]);
}

printf("Soma pares = %ld\nSoma impares = %ld\n",calcularsomas(v).pares,calcularsomas(v).impares);

return 0;
}





