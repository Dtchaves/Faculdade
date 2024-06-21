#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
long double f_x_y = 0, auxiliar;
float x,y;

scanf("%f %f",&x,&y);
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


printf("%Lf\n",f_x_y);

return 0;
}











