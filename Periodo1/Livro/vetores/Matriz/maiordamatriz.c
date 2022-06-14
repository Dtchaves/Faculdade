#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main ()
{
    int c,l;
    scanf("%i %i",&l,&c);
    
    int matriz[l][c],maior,i,j;

maior = INT_MIN;
    
for(i=0;i<l;i++){
    for(j=0;j<c;j++){
        scanf("%i",&matriz[i][j]);
    }
}
    
for(i=0;i<l;i++){
    for(j=0;j<c;j++){
        if (matriz[i][j] > maior) {
            maior = matriz[i][j];
        }
    }
}
    
printf("%i",maior);    


return 0;    
}
