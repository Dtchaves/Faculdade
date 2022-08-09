#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contadorletra(char x, FILE *p){
	int i = 0;
	char m;

	while((m = fgetc(p)) != EOF){
		if(m == x){
			i++;
		}
	}
return i;
}


int main (int argc,char **argv) {

char arquivo[100],c = 'a';
	strcpy(arquivo,argv[1]);
	//scanf("%c",&c);

FILE *entrada;

entrada = fopen(arquivo,"r+");

printf("%i",contadorletra(c,entrada));

return 0;
}
