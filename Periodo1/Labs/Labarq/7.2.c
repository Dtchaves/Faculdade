#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contadorletra(char x, FILE *p){
	int i = 0;
	char m;

	while(1){
		m = fgetc(p);

		if(feof(p)){
			break;
		}
			
		if(m == x){
			i++;
		}
	}
return i;
}


int main () {

char arquivo[100];

scanf("%s",arquivo);

int c = 'a';
	//scanf("%c",&c);

FILE *entrada;

entrada = fopen(arquivo,"rb");

printf("%i",contadorletra(c,entrada));

return 0;
}
