/*Escreva uma função que receba uma string e retorne se ela é um palíndromo (1)
ou não (0). Um palíndromo é uma palavra que tem a propriedade de poder ser
lida tanto da direita para a esquerda como da esquerda para a direita. Exemplos:
ovo, arara, rever, asa, osso etc.*/

#include <stdio.h>
#include <string.h>

int palindromo(char s []) {
int ret = 0;

int t,i,j;
char contraria[100];
t = strlen(s);

for (i = 0, j = t-1; j >= 0; j--,i++){
	contraria[i] = s[j];
}
contraria [t] = '\0';

if(!strcmp(s,contraria)){
ret = 1;
}
return ret;
}

int main () {
char v[100];
int i;

scanf("%s",v);

printf("%i\n",palindromo(v));

return 0;
}





