#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main () {

int i,j,x,y,vet[10],guardar[10],contador= 0;

for(i=0;i<10;i++){
	scanf("%i",&vet[i]);
}

x=0;
printf("\n");

for(i=0;i<10;i++){
	for(j=x;j<10;j++){
		if(vet[i] == vet [j] && i != j) {//tava dando problema ent tive q colocar isso
			guardar[contador] = vet[j]; // esse vetor armazena os numeros iguais 
			contador++; //esse contador - 1 esta preenchido 
			break;
		}
	}
x++; //analisar 0, 1 é igual 1, 0 
}

y=0;
x=0;

for(i=0;i<contador;i++){ 
	for(j=x;j<contador;j++){
		if(guardar[i] == guardar[j] && i != j) 
			y++;
	}

	if(y == 0)
		printf("%i\n",guardar[i]);
	x++;
	y=0;
}

return 0;
}
