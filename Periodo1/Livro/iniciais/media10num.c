#include <stdio.h>
#include <stdlib.h>

int main ()
{

float soma=0,valor_recebido;

 for(int c=0;c<10;c++) {
  scanf("%f",&valor_recebido);
  soma += valor_recebido;

 }
printf("%f",soma/10.0);
return 0;

}


