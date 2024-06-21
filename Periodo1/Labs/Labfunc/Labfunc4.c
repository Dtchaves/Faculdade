#include <stdio.h>
#include <stdlib.h>


int bissexto( int ano){
	if(ano%4 == 0){
		if(ano%100 == 0 && ano%400 != 0){
		}
			else{
				return 1;
			}
	}
return 0;
}

int main (){

int x;
while(scanf("%d",&x)!= EOF){
	printf("%d\n",bissexto(x));
}
return 0;
}








