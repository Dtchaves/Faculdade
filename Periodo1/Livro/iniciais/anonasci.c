#include <stdio.h>
#include <stdlib.h>

int main ()
{
  int x,y;

  printf("Coloque sua idade e o ano atual para saber seu ano de nascimento\n");
  scanf("%i %i",&x,&y);
  
  printf("%i\n\n",y-x);  
  
return 0;
}
