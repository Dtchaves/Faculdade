#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int armazenador[800];
    int i,saida=1;
    
      armazenador[0] = 0;
      armazenador[1] = 1;
      

for(i=2;i<=800;i++){
    armazenador[i] = armazenador [i-1] + armazenador [i-2];
}


while (1) {
    scanf("%i",&saida);
    if (saida < 0 || saida > 800) {
        break;
    }
    printf("%i\n",armazenador[saida]);
    
}
    
return 0;    
}

