/*Crie uma estrutura representando uma hora. Essa estrutura deve conter os campos
hora, minuto e segundo. Agora, escreva um programa que leia um vetor de cinco
posições dessa estrutura e imprima a maior hora.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct time {
	int hour, minutes,seconds;
}time;

void trocadevalores(time x[],int n,int m) {
	int help;
				help = x[n].hour;
				x[n].hour = x[m].hour;
				x[m].hour = help;

				help = x[n].minutes;
				x[n].minutes = x[m].minutes;
				x[m].minutes = help;

				help = x[n].seconds;
				x[n].seconds = x[m].seconds;
				x[m].seconds = help;
}



int main (){
	time read[5];
	int i,j,aux = 1, help;

	for(i = 0; i<5;i++) {
		scanf("%i %i %i",&read[i].hour,&read[i].minutes,&read[i].seconds);
			if (read[i].seconds > 60){
			read[i].minutes += read[i].seconds/60;
			read[i].seconds %= 60;
			}
			if (read[i].minutes > 60){
			read[i].hour += read[i].minutes/60;
			read[i].minutes %= 60;
			}
	}

	for(i = 0; i<5;i++) {
		for(j = aux; j<5;j++) {
 			if(read[i].hour > read[aux].hour) {
				trocadevalores(read,i,aux);
			}

			if(read[i].hour == read[aux].hour) {
				if(read[i].minutes > read[aux].minutes) {
					trocadevalores(read,i,aux);
				}

				if(read[i].minutes == read[aux].minutes) {
					if(read[i].minutes > read[aux].minutes) {
						trocadevalores(read,i,aux);
					}
				}
			}


		}
		aux++;
	}
	
	printf("\n");
	for(i = 0; i<5;i++) {
	printf("%i %i %i\n",read[i].hour,read[i].minutes,read[i].seconds);
	}

return 0;
}







