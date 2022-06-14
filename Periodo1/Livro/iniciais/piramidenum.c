#include <stdio.h>
#include <stdlib.h>

int main ()
{

int x,c,diferenca = 1,ultimalinha = 0;

scanf("%i",&x);

  for(c=1;c<=x;c++) {
   printf("%i ",c);

     if (c-ultimalinha == diferenca) {
       diferenca++;
       printf("\n");
       ultimalinha = c;
     }
   }

return 0;
}
