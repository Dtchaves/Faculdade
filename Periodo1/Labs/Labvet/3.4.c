#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int a;
    scanf("%i",&a);
    
    int aeds[a],i;

for(i=0;i<a;i++){
    scanf("%i",&aeds[i]);
}

    int b;
    scanf("%i",&b);
    
    int cal[b];

for(i=0;i<b;i++){
    scanf("%i ",&cal[i]);
}

    int navegadora,navegadorb;

for(navegadora=0;navegadora<a;navegadora++){
    for(navegadorb=0;navegadorb<b;navegadorb++){
        if(aeds[navegadora] == cal[navegadorb]){
            printf("%i\n",aeds[navegadora]);
        }
    }
    
    
    
} 





return 0;    
}

