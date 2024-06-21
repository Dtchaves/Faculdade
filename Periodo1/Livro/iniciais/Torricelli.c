#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()//V2=Vo2 + 2ad
{
 float Vf,Vo,a,d,y,w;
 int x=1;
 
 while (x!=0)
 {
  
 printf("\nEscolha qual variavel você deseja achar na equação de Torricelli sendo:\n1-Velocidade final\n2-Velocidade inicial\n3-Aceleração\n4-Deslocamento\ndigite 0 para parar\n\n");
 scanf(" %i",&x);

   if (x>4)
 { 
  printf("\nNúmero inválido\n\n");
 
 }
  else
  {
  
   switch (x) 
   {
     case 1:
      printf("\nColoque\n-um em cada linha-\n1-Velocidade inicial\n2-Aceleração\n3-Deslocamento\n\n");
      scanf("%f %f %f",&Vo,&a,&d);
      Vf = sqrt(Vo*Vo + 2*a*d);
      printf("\nA velocidade final é %f \n\n",Vf);
      break;
   
    case 2:
      printf("\nColoque\n-um em cada linha-\n1-Velocidade final\n2-Aceleração\n3-Deslocamento\n\n");
      scanf("%f %f %f",&Vf,&a,&d);
      Vo = sqrt(Vf*Vf - 2*a*d);
      printf("\nA velocidade inicial é %f \n\n",Vo);
      break; 
   
    case 3:
     printf("\nColoque\n-um em cada linha-\n1-Velocidade inicial\n2-Velocidade final\n3-Deslocamento\n\n");
     scanf("%f %f %f",&Vo,&Vf,&d);
     y = Vf*Vf - Vo*Vo; 
     w = 2*d;
     a = y/w;
     printf("\nA aceleração é %f \n\n",a);
     break;
   
    case 4:
     printf("\nColoque\n-um em cada linha-\n1-Velocidade inical\n2-Velocidade final\n3-Aceleração\n\n");
     scanf("%f %f %f",&Vo,&Vf,&a);
     y = Vf*Vf - Vo*Vo; 
     w = 2*a;
     d = y/w;
     printf("\nO deslocamento é %f \n\n",d);
     break;
  }
 }
}
return 0;
}

//gcc Torricelli.c -o





