#include <stdio.h>
#include <stdlib.h>
#define a 5
#define b 3
#define c 4

int main () 
{
float M1[a][b],M2[b][c],M3[a][c] ;
int i,j,p;

for(i=0; i<a; i++) {
	for(j=0; j<c; j++) {
		M3[i][j] = 0;
	}
}


for(i=0; i<a; i++) {
	for(j=0; j<b; j++) {
		M1[i][j] = (int) rand()%30;
		printf("%f\t",M1[i][j]);
	}
printf("\n ");
}

printf("\n");

for(i=0; i<b; i++) {
	for(j=0; j<c; j++) {
		M2[i][j] = (int) rand()%30;
		printf("%f\t",M2[i][j]);
	}
printf("\n");
}

printf("\n");

for(i=0; i<a; i++) {
	for(p=0; p<c; p++) {	
		for(j=0; j<b; j++) {
			M3[i][p] += M1[i][j] * M2[j][p];
		}
	printf("%f\t",M3[i][p]);
	}
printf("\n");
}

return 0;

}
