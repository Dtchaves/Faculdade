#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int a;
    scanf("%i",&a);
    
    int aeds[a],i;

printf("\n");

for(i=0;i<a;i++){
    scanf("%i",&aeds[i]);
}

printf("\n");

    int b;
    scanf("%i",&b);
    
    int cal[b];

printf("\n");

for(i=0;i<b;i++){
    scanf("%i",&cal[i]);
}

    int navegadora,navegadorb;

printf("\nos valores em comum são:\n");
for(navegadora=0;navegadora<a;navegadora++){
    for(navegadorb=0;navegadorb<b;navegadorb++){
        if(aeds[navegadora] == cal[navegadorb]){
            printf("%i\n",aeds[navegadora]);
        }
    }
  
} 
return 0;    
}
