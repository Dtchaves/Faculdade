/* Escreva um programa que recebe uma string S e dois valores inteiros não negati-
vos i e j. Em seguida, imprima os caracteres contidos no segmento que vai de i a j
da string S. */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
char str1[1000],str2[1000];
char alfabeto[1000] = "abcdefghijklmnopqrstuvwxyz";
int contador = 0,x,y;

fgets(str1,1000,stdin);
fgets(str2,1000,stdin);

x = 0;
while(str1[x] != '\n' && str2[x] != '\n' && contador == 0) {
	for(y = 0; y < 26; y++) {
		if(str1[x] == alfabeto[y] && str2[x] != alfabeto[y]) {
			contador = 1;
			break;
		}

		if(str1[x] != alfabeto[y] && str2[x] == alfabeto[y]) {
			contador = 2;
			break;
		}
	}
x++;
}

printf("%i",contador);

if(contador == 0) {
	x = strlen(str1);
	y = strlen(str2);
	
	if (x > y)
		printf("\n%s%s",str2,str1);
	if (x < y)
		printf("\n%s%s",str1,str2);
}


if(contador == 1)
	printf("\n%s%s",str1,str2);

if(contador == 2)
	printf("\n%s%s",str2,str1);


return 0;
}
