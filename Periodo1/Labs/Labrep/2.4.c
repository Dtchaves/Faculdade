#include <stdio.h>
#include <stdlib.h>

int main()
{
  float entrada;
  int contador = 1,dois=0,tres=0,cinco=0;
  
  printf("Coloque um número para saber quantos são os múltiplos de 2, de 3 e de 5 entre 1 e ele\n");
  scanf("%f",&entrada); 

   while (contador <= entrada) {

    if(contador%2 == 0){
      dois++;
                       }
    if(contador%3 == 0){
      tres++;
                       }
    if(contador%5 == 0){
      cinco++;
                       }

     contador++;
                               }

 printf("\n Múltiplos de 2: %i\n Múltiplos de 3: %i\n Múltiplos de 5: %i\n",dois,tres,cinco);

return 0;
}

