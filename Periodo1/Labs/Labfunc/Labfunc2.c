#include <stdio.h>
#include <stdlib.h>


int primo (long long unsigned int  x){
	int i;
	if(x<2){
		return -1;	
	}
		else{
			for(i=2;i<x;i++){
				if(x%i == 0) {
					return 0;		
				}
			}
			return 1;
		}
}

int main (){

long long unsigned int y;

while(scanf("%llu",&y)!= EOF){
    printf("%i\n",primo(y));
}
return 0;
}







