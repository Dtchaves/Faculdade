
#include <stdio.h>
#include <stdlib.h>

int main () 
{
int a,b,c,d;
 
printf("Coloque o tamanho da primeira matriz com linhas e colunas menor ou igual a 50\n");
scanf("%i %i",&a,&b);

printf("Coloque o tamanho da segunda matriz com linhas e colunas menor ou igual a 50\n");
scanf("%i %i",&d,&c);

	while (a>50 || b>50 || c>50 || d>50) {
		printf("Valores invalidos\n");

		printf("Coloque o tamanho da primeira matriz com linhas e colunas menor ou igual a 50\n");
		scanf("%i %i",&a,&b);

		printf("Coloque o tamanho da segunda matriz com linhas e colunas menor ou igual a 50\n");
		scanf("%i %i",&d,&c);
	}

	while (a<0 || b<0 || c<0 || d<0) {
		printf("Valores invalidos\n");
		printf("Coloque o tamanho da primeira matriz com linhas e colunas menor ou igual a 50\n");
		scanf("%i %i",&a,&b);

		printf("Coloque o tamanho da segunda matriz com linhas e colunas menor ou igual a 50\n");
		scanf("%i %i",&d,&c);
	}


if(b==d) {
	float M1[a][b],M2[b][c],M3[a][c] ;
	int i,j,p;

	for(i=0; i<a; i++) {
		for(j=0; j<c; j++) {
			M3[i][j] = 0;
		}
	}

	printf("Coloque os valores da primeira matriz\n");

	for(i=0; i<a; i++) {
		for(j=0; j<b; j++) {
			scanf("%f",&M1[i][j]);
		}
	}

	printf("Coloque os valores da segunda matriz\n");

	for(i=0; i<b; i++) {
		for(j=0; j<c; j++) {
			scanf("%f",&M2[i][j]);
		}
	}

	printf("\nMatriz A:\n");

	for(i=0; i<a; i++) {
		for(j=0; j<b; j++) {
			printf("%f\t",M1[i][j]);
		}
	printf("\n");
	}

	printf("\nMatriz B:\n");

	for(i=0; i<b; i++) {
		for(j=0; j<c; j++) {
			printf("%f\t ",M2[i][j]);
		}
	printf("\n");
	}

	printf("\nMatriz A*B:\n");

	for(i=0; i<a; i++) {
		for(p=0; p<c; p++) {	
			for(j=0; j<b; j++) {
				M3[i][p] += M1[i][j] * M2[j][p];
			}
		printf("%f\t",M3[i][p]);
		}
	printf("\n");
	}
}
else
	printf("É impossível multiplicar essas matrizes pois o número de colunas da primeira é diferente do número de linhas da 		segunda\n");

return 0;
}




