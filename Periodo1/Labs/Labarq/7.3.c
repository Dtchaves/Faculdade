#include <stdio.h>
#include <stdlib.h>


int main () {

int i,j;

char arquivo[100];
	scanf("%s",arquivo);


FILE *entrada;
	entrada = fopen(arquivo,"rb");

long long int ml1[5][5],ml2[5][5];
	for (i = 0;i<5;i++){
		for(j = 0;j<5;j++){
			fscanf(entrada,"%lld ",ml1[i]+j);
		}
	}
	for (i = 0;i<5;i++){
		for(j = 0;j<5;j++){
			fscanf(entrada,"%lld ",ml2[i]+j);
		}
	}
	
for (i = 0;i<5;i++){
	for(j = 0;j<5;j++){
		printf("%lld ",ml1[i][j]+ml2[i][j]);
	}
putchar('\n');
}

fclose(entrada);
return 0;
}