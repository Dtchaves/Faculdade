
#include <stdio.h>
#include <stdlib.h>

int main()
{
 
 int n,contador;
 float xo,x,r;

  scanf("%i %f %f",&n,&xo,&x);//xn = 4*xn-1-2*xn-2

  printf("\n%f\n",xo);

   for(contador=1;n>=contador;contador++)
    {
     printf("\n%f\n",x);
     r=4*x-2*xo; 
     xo=x; 
     x=r;             
    }

return 0;
} 






































