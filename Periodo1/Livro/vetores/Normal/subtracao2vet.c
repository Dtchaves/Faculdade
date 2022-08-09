#include <stdio.h>
#include <stdlib.h>

int main () {

int veta[10],vetb[10],i,vetc[10];

for(i = 0; i<10; i++) {
	scanf("%i",&veta[i]);
}
for(i = 0; i<10; i++) {
	scanf("%i",&vetb[i]);
}

for(i = 0; i<10; i++) {
	vetc[i] = veta[i] - vetb[i];
}


printf("\n");

for(i = 0; i<10; i++) {
	printf("%i",vetc[i]);
}


return 0;
}
