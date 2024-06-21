#include <stdio.h>
#include <stdlib.h>

int main ()
{

int a,primeiro,segundo;

  printf(" + = 1\n - = 2\n x = 3\n / = 4\n");
  scanf("%i",&a);
  scanf("%i %i",&primeiro,&segundo);

   if (a>4 || a<1) {
     printf("Valor invalido");
   }
    else {
     switch (a) {
 
       case 1 : {
        printf("%i\n",primeiro+segundo); 
        break;}

       case 2 : {
         printf("%i\n",primeiro-segundo); 
         break;}

        case 3 : {
         printf("%i\n",primeiro*segundo);
         break; }

        case 4 : {
         printf("%i\n",primeiro/segundo);
         break; }
    } 
      }

return 0;
}
