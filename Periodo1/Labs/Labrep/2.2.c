#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

 int contadorsaida = 0, imparpar = 1;
 double galls=0,subtracao = 1,ap,denominador = 1.0;

  printf("Coloque uma diferença máxima para saber quantas interações da série infinita de Gregory-Leibniz são necessárias para obte-lá em relação a Pi\n\n");
  scanf("%lf",&ap);

 if(ap > 4 - M_PI){
   printf("Diferença inválida (maior possível é %lf)\n",4 - M_PI);
          }
          
    while ( subtracao > ap || -subtracao > ap) {
      if(imparpar%2 == 0){ //par
        galls = galls - 4/denominador;
        subtracao = M_PI - galls;
        denominador = denominador+2;
        imparpar++;
        contadorsaida++; 
        }
        else {//impar
          galls = galls + 4/denominador;
          subtracao = M_PI - galls;
          denominador = denominador+2;
          imparpar++;
          contadorsaida++;
          }
     }

  printf("\n%i\n\n",contadorsaida);

return 0;
}
