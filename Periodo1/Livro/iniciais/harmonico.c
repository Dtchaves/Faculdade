#include <stdio.h>
#include <stdlib.h>

int main ()
{
float Hn = 1 ,n,c;


scanf("%f",&n);

 for(c=2.0; c<=n; c++) {
  Hn= Hn + 1/c;
 }


printf("%f",Hn);


return 0;

}
