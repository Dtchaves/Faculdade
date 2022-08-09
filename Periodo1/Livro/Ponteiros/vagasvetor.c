#include <stdio.h>
#include <stdlib.h>

int main () {

int *v,i;

v = (int *) malloc (10*sizeof(int));

for (i = 0; i<10; i++){
	printf("%p\n",v+i);
}

return 0;
}



