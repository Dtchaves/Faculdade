#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
char str[1000];
int size,navigator,lastspace,c = 0;

fgets(str,1000,stdin);
size = strlen(str) - 1;
lastspace = size - 1;
size /= 2;

for(navigator = 0; navigator < size; navigator++, lastspace--){
	if(str[navigator] == str[lastspace])
		c++;
}

if(c == size){
	printf("sim");}
	else {
	printf("não");}


return 0;
}
