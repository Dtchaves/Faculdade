#include <stdio.h>
#include <stdlib.h>

int main () {

int i,vet[20],vetquadrado[20];

for(i=0;i<20;i++){
scanf("%i",&vet[i]);
vetquadrado[i] = vet[i]*vet[i];
}

for(i=0;i<20;i++){
printf("%i ",vet[i]);
}

printf("\n");

for(i=0;i<20;i++){
printf("%i ",vetquadrado[i]);
}

printf("\n");

return 0;
}

