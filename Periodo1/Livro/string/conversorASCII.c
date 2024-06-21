#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
char str[1000];
int ascii[1000],i,tamanho;

fgets(str,1000,stdin);
tamanho = strlen(str) - 1;

for(i = 0; i < tamanho; i++) {
	ascii[i] = str[i];
	if(ascii[i] != 32) {
		if(ascii[i] < 92) {
			str[i] = ascii[i] + 32;
		}
			else {
				str[i] = ascii[i] - 32;
			}
	}
}

fputs(str,stdout);

return 0;
}
