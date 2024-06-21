/*Faça uma função que receba um número inteiro de 1 a 12 e imprima em tela o
mês e a sua quantidade de dias de acordo com o número digitado pelo usuário.
Exemplo: Entrada = 4. Saída = abril. */

#include <stdio.h>
#include <string.h>

typedef struct mes{
char x[50];
} mes;

mes retornador(int n){
mes y;

	switch(n) {
	case 1:{
	 strcpy(y.x,"janeiro");
	}
	break;
	case 2:{
	 strcpy(y.x,"fevereiro");
	}
	break;
	case 3:{
	 strcpy(y.x,"marco");
	}
	break;
	case 4:{
	 strcpy(y.x,"abril");
	}
	break;
	case 5:{
	 strcpy(y.x,"maio");
	}
	break;
	case 6:{
	 strcpy(y.x,"junho");
	}
	break;
	case 7:{
	 strcpy(y.x,"julho");
	}
	break;
	case 8:{
	 strcpy(y.x,"agosto");
	}
	break;
	case 9:{
	 strcpy(y.x,"setembro");
	}
	break;
	case 10:{
	 strcpy(y.x,"outubro");
	}
	break;
	case 11:{
	 strcpy(y.x,"novembro");
	}
	break;
	case 12:{
	 strcpy(y.x,"dezembro");
	}
	break;
	}


return y;
}

int main (){
int i;

do{
scanf("%d",&i);
}while(i>12 || i<1);
printf("%s\n",retornador(i).x);

return 0;
}


