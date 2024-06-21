#include <stdio.h>
#include <stdlib.h>

int main () 
{

int c,x,soma=0;
 
scanf("%i",&x);

for(c=1; c<x; c++) {

 if(x%c == 0) {
 soma += c;
 }
}

printf("%i\n",soma);

return 0;
}
