#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int c,l;
    scanf("%i %i",&l,&c);
    
    int matriz[l][c],maior=-99999999,i,j;
    
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
