#include <stdio.h>
#include <stdlib.h>

int main ()
{
 double valorlido, maior=0;
 int n, contadorsaida = 0,contadorn ;

 scanf("%i",&n);

	for(contadorn = 1; contadorn <= n; contadorn++) {
	  scanf("%lf",&valorlido);
		if(valorlido == maior) {
		 contadorsaida++;
		}
		if(valorlido > maior) {
  		 maior = valorlido;
		 contadorsaida = 1;		
		}
 	} 

printf("O maior número é o %lf e ele aparece %i vezes",maior,contadorsaida);



return 0;
}
