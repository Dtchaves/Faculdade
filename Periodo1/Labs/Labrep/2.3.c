#include <stdio.h>
#include <stdlib.h>

int main()
{
 int x=233;

 do {
   
    if(x<300 || x>400) {
       x=x+5;
       printf("%i\n",x);
                       }
      else {
       x=x+3;
       printf("%i\n",x);
           }            

    } while(x<=457);



return 0;
}

