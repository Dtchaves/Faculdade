#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int a=-1,b=-1,auxiliar,contador,p=0,A = 0;
    
    while(a>10000 || a<0 || b>10000 || b<0 ){
        scanf("%i %i",&a,&b);
    
        if (a > b){
            auxiliar = b;
            b = a;
         }
       
    }    
    for(A = a;A<=b;A++){
        for(contador=1;contador < A; contador ++ ) {
            auxiliar = A%contador;
            
                if(auxiliar == 0){
                    p++;    
                }
        }
        if(p == 1) {
            printf("%i ",A);
        }
        
        p = 0;
    }
    
return 0;
}
