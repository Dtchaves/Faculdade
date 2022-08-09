#include <stdio.h>

float menorelemento(float v[],int n,int aux) {
// recursiva
int i;
i = n-1;

if (i < 0) {
return v[aux] ;
}
	else {
		if (v[i]<v[aux]){
			aux = i;
		}
	}
return menorelemento(v,n-1,aux);
}



int main () {

float n[10];
int i;

for(i = 0; i<10;i++){
	scanf("%f",&n[i]);
}

printf("%f\n",menorelemento(n,10,0));

return 0;
}
