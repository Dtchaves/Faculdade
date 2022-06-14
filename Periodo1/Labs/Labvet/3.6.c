#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int i,j;
    scanf("%i %i",&i,&j);
    
    int matriz[i][j],l,c,auxiliar;
    
    for(l=0;l<i;l++){
        for(c=0;c<j;c++){
            scanf("%i",&auxiliar);
            matriz[l][c] = -auxiliar;
        }  
        
        
    }
    
    for(l=0;l<i;l++){
        for(c=0;c<j;c++){
           printf("%i ",matriz[l][c]);
        }
        
        printf("\n");
    }


return 0;    
}
