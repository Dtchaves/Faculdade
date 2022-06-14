/* Escreva uma função que receba um array de 10 elementos e retorne a sua soma.*/

#include <stdio.h>

float soma(float x[],int n){
int i = n-1;
 
if (i < 0){
return 0;
}
	else {
		return x[i] + soma (x,n-1);
	}

}



int main () {
float v[10];
int i;

for(i = 0;i<10;i++){
	scanf("%f",&v[i]);
}

printf("%f\n",soma(v,10));

return 0;
}





