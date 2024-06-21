#include <stdio.h>
#include <stdlib.h>

int main()
{
 int numero,contador,soma=0;
 
 printf("Coloque um número para saber a soma de todos os números de 1 até ele\n");
 scanf("%i",&numero);
 
  for(contador=1; contador<=numero ; contador++) 
  {
   soma = soma + contador;
  }

printf("\n%i\n\n",soma);

return 0;
}
