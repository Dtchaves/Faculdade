

#include <stdio.h>

typedef struct matriz {
int m[6][6],diagonalp,diagonals;
}matriz;

void diagonais(matriz *x){
int i,j;
x->diagonalp = 0;
x->diagonals = 0;

for (i=0; i < 6; i++){
	for (j=0; j < 6; j++){
		if( i == j){
			x->diagonalp += x->m[i][j];
		}
	}
}

j = 5;
for (i=0; i < 6; i++){
	x->diagonals += x->m[i][j];
	j--;
}

}


int main () {
matriz x;
int i,j;

for(i = 0; i<6;i++){
	for(j = 0; j<6;j++){
		scanf("%i",&x.m[i][j]);

	}

}
diagonais(&x);
printf("principal = %i\nsecundaria = %i\n",x.diagonalp,x.diagonals);

return 0;
}





