/*Elabore uma função que receba como parâmetro um valor inteiro n e gere como
saída um triângulo lateral formado por asteriscos conforme o exemplo a seguir,
em que usamos n = 4:
*
**
***
****
***
**
* */

#include <stdio.h>


void asterisco(int n){
int i,j;
	for(j=1;j<=n;j++){
		for(i = 1;i<=j;i++){
			printf("*");
		}
	printf("\n");
	}

	for(j=n-1;j>=1;j--){
		for(i = 1;i<=j;i++){
			printf("*");
		}
	printf("\n");
	}
}

void main (){
int x;
scanf("%i",&x);
asterisco(x);

}



