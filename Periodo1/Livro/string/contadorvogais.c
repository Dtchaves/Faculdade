#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
char vogais[5] = "aeiou",lido[1000],substituto;
int andadorv,andadorl,tamanhol,contadorv;

fgets(lido,1000,stdin);
tamanhol = strlen(lido) - 1;
setbuf(stdin,NULL);
scanf("%c",&substituto);

for (andadorl = 0; andadorl < tamanhol; andadorl++) {
	for (andadorv = 0; andadorv < 5; andadorv++) {
		if ( lido[andadorl] == vogais[andadorv]) {
			lido[andadorl] = substituto;
			contadorv++;
			break;
		}
	}
}

printf("\n%i\n",contadorv);
printf("%s",lido);

contadorv = 0;

for (andadorl = 0; andadorl < tamanhol; andadorl++) {
	for (andadorv = 0; andadorv < 5; andadorv++) {
		if ( lido[andadorl] == vogais[andadorv]) {
			contadorv++;
			break;
		}
	}
}

printf("\n%i",contadorv);

return 0;
}

