#include <stdio.h>
#include <stdlib.h>


int primo (long long int x){
	int i;

	if(x<2){
		return -1;	
	}
		else{
			for(i=2;i*i<=x;i++){
				if(x%i == 0) {
					return 0;		
				}
			}
			return 1;
		}
}


 long long int somaprimos(long long int n) {
    long long int soma = 0;
	int i=2,contador = 1;
	
	while (contador <= n){
        if(primo(i)){
         contador++;
         soma += i;
        }
		i++;	
	}	
	

return soma;
} 

int main (){

long long int y;
 long long int soma;

while(scanf("%lld",&y) != EOF){

	printf("%lld\n",somaprimos(y));
}

return 0;
}









