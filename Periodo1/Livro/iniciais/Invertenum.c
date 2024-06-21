#include <stdio.h>
#include <stdlib.h>

int main()
{
int x,c,d,u;

while(x!=0){
 
  printf("Coloque um número de 3 digitos para inverter a ordem de seus algorismos\n");
  scanf("%i",&x);

   if(x>999 || x<100 && x!=0) {
  	 printf ("Valor inválido\n"); }
 
   else {
    c = x/100;
    d = x/10 - 10*c;
    u = x - 100*c - 10*d;
 
    x= 100*u + 10*d + c;

     printf("%i\n\n",x); }
}

return 0;
}








