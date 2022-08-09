/*Escreva uma função recursiva que calcule a soma dos primeiros n cubos:
S = 1 3 + 2 3 + ... + n 3*/

#include <stdio.h>
#include <stdlib.h>

long int somacubos(int n){
//recursiva
int i = n;

if (i == 1){
	return 1;
}
	else {
		return (i*i*i) + somacubos(n-1);
	}

}





int main (){
	int c;
	scanf("%i",&c);
	printf("%ld\n",somacubos(c));

return 0;
}



