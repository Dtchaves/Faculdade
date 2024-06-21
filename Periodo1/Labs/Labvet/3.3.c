#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int vetor[9],i;

    for(i=0;i<10;i++){
        scanf("%i",&vetor[i]);
    }
    
    for(i=9;i>=0;i--){
        printf("%i\n",vetor[i]);
    }    
    

return 0;    
}
