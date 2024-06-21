#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{

 int centena, dezena ,unidade, numerorecebido,soma;
 scanf ("%i",&numerorecebido);
		
	centena = numerorecebido/100;
	dezena = numerorecebido/10 - centena*10;
	unidade = numerorecebido - centena*100 - dezena*10;
		
	centena = pow(centena,3);
	dezena = pow(dezena,3);
	unidade = pow(unidade,3);

	soma = unidade + centena + dezena;
			
		if (soma == numerorecebido) {
			printf("\nsim\n");
		}
			else  {
				printf("\nnão\n"); 
			}


return 0;
}
