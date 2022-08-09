#include <stdio.h>
#include <stdlib.h>

int main () {

int **m,i,j;

m = (int **) malloc (3*sizeof(int));

for (i = 0; i<3; i++){
m[i] = (int *) malloc (3*sizeof(int));
}

for (i = 0; i<3; i++){
	for (j = 0; j<3; j++){
		printf("%p ",*(m+i)+j);
	}
	printf("\n");
}

return 0;
}



