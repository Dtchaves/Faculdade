/*Escreva uma função recursiva que receba um valor inteiro e o retorne invertido.
Exemplo:
		
Número lido = 123.
Número retornado = 321.*/

#include <stdio.h>
#include <stdlib.h>

long int inversao(int n){
//recursiva
int auxiliar = 10,i = n;

while(i/auxiliar > 0){
auxiliar *= 10;
}
auxiliar /= 10;

if (i > 0 && i < 10){
	return i;
}
	else {
		return (n%10)*auxiliar + inversao(n/10);
	}
}





int main (){
	int c;
	scanf("%i",&c);
	printf("%ld\n",inversao(c));

return 0;
}


