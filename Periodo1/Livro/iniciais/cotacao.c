#include <stdio.h>
#include <stdlib.h>

int main()
{

float r,c,d;
int x;

while (x!=0)
{

 printf("Digite 1 para achar o valor em real, 2 para achar o valor em dolar ou 3 para achar a cotação\n-digite 0 para parar_\n");
 scanf("%i",&x);
 
 if (x>3 || x<0) 
 {
  printf("valor invalido\n\n");
  }
  
  else {
   switch (x) {
  
  case 1://achar valor em real 
   printf("Coloque a cotação comercial do dolar e o valor em dolar que você deseja converter para real\n");
   scanf("%f %f",&c,&d);
   r = d*c;
   printf("O valor em real é %f\n",r);
   break;

  case 2://achar valor em dolar
   printf("Coloque a cotação comercial do dolar e o valor em real que você deseja converter para dolar\n");
   scanf("%f %f",&c,&r);
   d = r/c;
   printf("O valor em dolar é %f\n",d);
   break;

  case 3:
    printf("Coloque o valor dolar e o valor em real que você deseja converter para dolar\n");
   scanf("%f %f",&d,&r);
   c = r/d;
   printf("O valor da cotação é %f\n",c);
   break;
    }
  }
}
return 0;
}
