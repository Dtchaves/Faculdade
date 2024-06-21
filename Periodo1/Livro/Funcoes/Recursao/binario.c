/*Escreva uma função recursiva que receba um valor inteiro em base decimal e o
imprima em base binária.*/

#include <stdio.h>
#include <stdlib.h>

unsigned long long int binario(long int n){
//recursiva

if (n == 0){
	return 0;
}
	else {
		return n%2 + 10*binario(n/2);
	}
}





int main (){
	long int c;
	scanf("%ld",&c);
	printf("%llu\n",binario(c));

return 0;
}


