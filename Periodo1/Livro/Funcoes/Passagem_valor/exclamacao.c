/*Elabore uma função que receba como parâmetro um valor inteiro n e gere como
saída n linhas com pontos de exclamação, conforme o exemplo a seguir, em que
usamos n = 5:
!
!!
!!!
!!!!
!!!!! */

#include <stdio.h>


void exclamacao(int n){
int i,j;
	for(j=1;j<=n;j++){
		for(i = 1;i<=j;i++){
			printf("!");
		}
	printf("\n");
	}
}

void main (){
int x;
scanf("%i",&x);
exclamacao(x);

}



