
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
char str[100];
int contador,tamanho,auxiliar,tam,x;

fgets(str,99,stdin);
tamanho = strlen(str) - 1;
x = tamanho/2;
tamanho -= 1;

for(contador = 0; contador < x; contador++,tamanho--){
	auxiliar = str[contador];
	str[contador] = str[tamanho];
	str[tamanho] = auxiliar;

}

fputs(str,stdout);
printf("\n");





return 0;
}





