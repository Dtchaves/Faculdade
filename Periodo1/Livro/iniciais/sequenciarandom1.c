#include <stdio.h>
#include <stdlib.h>

int main ()
{

double soma=0, multiplicacao=1.0, n, c = 1.0;

scanf("%lf",&n);

	while(c<=n){
         multiplicacao *= c;
	 soma = soma + (1/multiplicacao);
 	 c++;
	}

printf("%lf\n",soma);

return 0;
}
