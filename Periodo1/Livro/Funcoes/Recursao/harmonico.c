#include <stdio.h>

float harmonico(float n) {
// recursiva

if (n == 1) {
return 1;
}
	else {
		return (1/n) + harmonico(n-1);
		}
}



int main () {

float i;

scanf("%f",&i);
printf("%f",harmonico(i));

return 0;
}
