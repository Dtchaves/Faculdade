#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
 float a,b,c,x[2],delta;

 scanf("%f %f %f",&a,&b,&c);
 delta = b*b - 4*a*c;

  if (delta < 0){
   printf("Essa equação não tem solução pois o delta é igual a %f e esse valor é menor que 0\n",delta);
  }
  
  if (delta >= 0){
    x[0] = (-b + sqrt(delta))/2*a;
    x[1] = (-b - sqrt(delta))/2*a;

    if(delta == 0){
     printf("Essa equação possui apenas uma solução pois delta é igual a 0 e essa solução é %f\n",x[0]);
    }
     else {
     printf("Essa equação possui duas soluções pois delta é igual a 0 e essas soluções são %f e %f\n",x[0],x[1]);
    }
  }
return 0;  
}































