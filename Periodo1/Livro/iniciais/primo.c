#include <stdio.h>
#include <stdlib.h>

int main ()
{

int x,c,cc = 0;

scanf("%i",&x);

for(c=1;c<x;c++){
 if(x%c == 0){
  cc++;
 }
}
 if (cc == 1){
  printf("O número %i é primo\n",x);
 }
  else {
   printf("O número %i não é primo\n",x);
  }
return 0;
}

