#include <stdio.h>

double sequencia (float n) {
// recursiva

if (n == 1) {
return 2;
}
	else {
		return (((n*n) + 1)/n) + sequencia(n - 1);
	}
}

int main () {

float n;

scanf("%f",&n);
printf("%lf\n",sequencia(n));

return 0;
}
