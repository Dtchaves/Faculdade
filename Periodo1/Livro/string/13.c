#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
char i,j,str[1001];
int x,contador = 0,tamanho,auxiliar = 0,a = 0;

fgets(str,1000,stdin);

scanf("%c",&i);
setbuf(stdin,NULL);
scanf("%c",&j);
tamanho = strlen(str);

for(x = 0; x < tamanho ;x++) {
	if (str[x] == i) {
		auxiliar = x;
		while(str[auxiliar] != j) {
			auxiliar++;
		}
	if(auxiliar < tamanho - 1){
	contador++;
	a = x;
	}
	break;
	}
}

if(contador == 1) {
	for( ; a <= auxiliar ;a++) {
		printf("%c",str[a]);
	}
}

return 0;
}
