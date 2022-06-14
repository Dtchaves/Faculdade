#include <stdio.h>

typedef struct data{
float dia;
float mes; 
int ano;

}diamesano;

typedef struct evento{
char nome[100];
char local[100];
diamesano data;
}Evento;


void cadastrar_eventos(Evento agenda[], int n){
int i;
	
	for(i = 0; i < n ; i++){	
		scanf("%s %s %f %f %i",agenda[i].nome,agenda[i].local,&agenda[i].data.dia,&agenda[i].data.mes,&agenda[i].data.ano);
	}


}


void imprimir_eventos(Evento agenda[], diamesano d, int n) {
int i,contador = 0;
	for (i =0 ; i<n; i ++){
		if (agenda[i].data.ano == d.ano){
			if (agenda[i].data.mes == d.mes){
				if (agenda[i].data.dia == d.dia){
					printf("%s %s\n",agenda[i].nome,agenda[i].local);
					contador ++;
				}
			}
		}
	}
	if (contador == 0){
		printf("Nenhum evento encontrado!");
	} 

}

void main (){

int n;
scanf("%i",&n);

Evento agenda[n];
diamesano d;

cadastrar_eventos(agenda,n);
scanf("%f %f %i",&d.dia,&d.mes,&d.ano);
imprimir_eventos(agenda,d,n);

}









