#include <stdio.h>
#include <stdlib.h>

int sera(int x){
int i;
for(i=2;i*i<=x;i++){
	if(x%i == 0) {
		return 0;		
	}
}
return 1;
}

void primos(int m, int *p1, int *p2){
int i = 1;

while(!sera(m - i)){ //menor que m
	i ++;
}
*p1 = m - i;
i = 1;

while(!sera(m + i)){ // maior que m
	i ++;
}
*p2 = m + i;
}

void main (){
int entrada, p1,p2;
scanf("%d",&entrada);

primos(entrada,&p1,&p2);

printf("%d\n%d",p1,p2);

}
