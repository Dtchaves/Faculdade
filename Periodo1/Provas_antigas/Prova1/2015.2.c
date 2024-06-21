
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
long double f_x_y = 0, auxiliar;
float x,x1,x2,y,auxiliar2 = 0;


scanf("%f %f %f",&x1,&x2,&y);
	if(x1<x2)
		auxiliar2 = x1;
		x1 = x2;
		x2 = auxiliar2;

	for(x = x2;x <= x1; x++) {
		if (x >= abs(pow(y,3))) {
 			f_x_y = y;
		}
	
		if (x < 0) {
 			f_x_y = y * (sin(-x));
		}

		if (x >= 0 && x < abs(pow(y,3))) {
			auxiliar = -y*x;
 			f_x_y = y * (exp(auxiliar));
		}


	printf("f(x,lambida)= %Lf\n para o x=%f\n",f_x_y,x);
	}

return 0;
}
