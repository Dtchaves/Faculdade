#include <stdio.h>
#include <stdlib.h>

int main ()
{

double s=0 ,debaixo=1,decima=1;

	while(debaixo <= 55) {
 	 s = s + decima/debaixo;
	 decima +=2;
        debaixo++;	  	
 	}
printf("%lf\n",s);


return 0;
}
