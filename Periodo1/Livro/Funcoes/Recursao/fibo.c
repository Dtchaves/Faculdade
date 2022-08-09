/*Escreva uma função recursiva que receba um número inteiro, maior ou igual a
zero, e retorne o enésimo termo da sequência de Fibonacci. Essa sequência começa
no termo de ordem zero e, a partir do segundo termo, seu valor é dado pela soma
dos dois termos anteriores. Alguns termos dessa sequência são: 0, 1, 1, 2, 3, 5, 8,
13, 21, 34.*/

#include <stdio.h>
#include <stdlib.h>

long int fibonacci(int n){
//recursiva
int i = n;

if (i == 1 || i == 0){
	return i;
}
	else {
		return fibonacci(n-2) + fibonacci(n-1);
	}

}





int main (){
	int c;
	scanf("%i",&c);
	printf("%ld\n",fibonacci(c));

return 0;
}


