/* Crie uma função que receba uma matriz A contendo cinco linhas e cinco colunas.
Calcule na própria matriz A a sua transposta (se B é a matriz transposta de A,
então A[i][j] = B[j][i]).*/

#include <stdio.h>

void transposta(int m[][3]){
int i,j;
int n = 0,aux;

	for (i = 0;i<3;i++){
		for( j = 2; j > n;j--){
			aux = m[i][j];
			m[i][j] = m[j][i];
			m[j][i] = aux;
		}
		n ++; 
	}
}


void lermat(int m[][3]){
int i,j;

	for (i = 0;i<3;i++){
		for( j = 0; j < 3;j++){
			scanf("%i",&m[i][j]);
		}
	}


}

void imprimir(int m[][3]){
int i,j;

	for (i = 0;i<3;i++){
		for( j = 0; j < 3;j++){
			printf("%i ",m[i][j]);
		}
		printf("\n");
	}


}
int main () {
int matriz [3][3];

lermat(matriz);
imprimir(matriz);
transposta(matriz);
printf("\n");
imprimir(matriz);

return 0;
}





