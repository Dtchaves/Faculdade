/*Faça um programa que permita ao usuário entrar com uma matriz de tamanho 3
× 3 de números inteiros. Em seguida, calcule um vetor contendo três posições, em
que cada posição deverá armazenar a soma dos números de cada coluna da matriz.
Exiba na tela esse array. Por exemplo, a matriz*/

#include <stdio.h>
#include <stdlib.h>


int main ()
{
 int matriz[3][3],i,j,vetorsoma[3];

	for(i=0;i<3;i++){
		vetorsoma[i] = 0;
	}

	for(i = 0; i < 3 ; i++) {
		for(j = 0; j <3; j++){
			scanf("%i",&matriz[i][j]);
		}
	}

	for(j = 0; j <3; j++){
		for(i = 0; i < 3 ; i++){
			vetorsoma[j] += matriz[i][j];
		}
	}

	printf("\n");

	for(i = 0; i < 3 ; i++) {
		for(j = 0; j <3; j++){
			printf("%i \t",matriz[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	for(i=0;i<3;i++){
		printf("%i \t",vetorsoma[i]);
	}



return 0;
}








