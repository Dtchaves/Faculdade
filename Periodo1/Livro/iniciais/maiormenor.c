#include <stdio.h>
#include <stdlib.h>

int main ()
{

float maior=0,menor=0,valor_recebido;

 for(int c=0;c<10;c++) {
  scanf("%f",&valor_recebido);

   if (maior<valor_recebido) {
    maior = valor_recebido;
   }

   if (menor>valor_recebido) {
    menor = valor_recebido;
   }
 }
printf("\n maior = %f\n menor= %f\n",maior,menor);
return 0;
}


