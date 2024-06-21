#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main ()
{
double valor=6.5,parteinteira,partefracao;

partefracao = modf(valor,&parteinteira);
printf("%lf %lf",partefracao,parteinteira);

return 0;
}
