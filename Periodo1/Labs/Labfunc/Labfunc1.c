#include <stdio.h>
#include <stdlib.h>

typedef struct data{
float ano,mes,dia;
}data;

void mudadata(data *x,data *y) {
	int help;

	help = x->ano;
	x->ano = y->ano;
	y->ano = help;

	help = x->mes;
	x->mes = y->mes;
	y->mes = help;

	help = x->dia;
	x->dia = y->dia;
	y->dia = help;
}

void maiordata(data *menor,data *maior) {
	int help;
		if(menor->ano > maior->ano) {
			mudadata(menor,maior);
		}

		if(menor->ano == maior->ano) {
			if(menor->mes > maior->mes) {
				mudadata(menor,maior);
			}
			if(menor->mes == maior->mes) {
				if(menor->dia > maior->dia) {
					mudadata(menor,maior);
				}
			}
		}
}		
long unsigned int contadordiasentre(data menor, data maior) {
	long unsigned int ret = 0,diasmesdomenor,diasmesdomaior,somador = 0;
	long unsigned int diasentreanos = 0,diferenca,auxiliar = 0;
	int i;	
		diasmesdomenor = menor.mes + 1;
		diasmesdomaior = maior.mes - 1;

		if(maior.ano!=menor.ano){
			for(i = diasmesdomenor; i <= 12; i++){
				if (i==2){
					somador += 28;				
				}

				if (i==4 || i==6 || i==9 || i == 11){
					somador += 30;			
				}
				
				if (i==1 || i==3 || i==5 || i == 7 || i==8 || i==10 || i==12 ){
					somador += 31;			
				}
			}

			diasmesdomenor = somador;
			somador = 0;

			for(i = 1; i <= diasmesdomaior; i++){
				if (i==2){
					somador += 28;				
				}

				if (i==4 || i==6 || i==9 || i == 11){
					somador += 30;			
				}
				
				if (i==1 || i==3 || i==5 || i == 7 || i==8 || i==10 || i==12 ){
					somador += 31;			
				}
			}
			diasmesdomaior = somador;
			somador = 0;

				if(menor.mes < 2) {
					if((int) menor.ano%4 == 0){
						if((int) menor.ano%100 == 0 && (int) menor.ano%400 != 0){

						}
							else {
								diasentreanos++;
							}		
					}
				}
				
				if(menor.mes == 2){
					if((int) menor.ano%4 == 0 && menor.dia != 29){
						if((int) menor.ano%100 == 0 && (int) menor.ano%400 != 0){

						}
							else {
								diasentreanos++;
							}		
					}
				}
				
				if(maior.mes > 2 ) {
					if((int) maior.ano%4 == 0){
						if((int) maior.ano%100 == 0 && (int) maior.ano%400 != 0){

						}
							else {
								diasentreanos++;
							}
								
					}
				}
				for (auxiliar = menor.ano + 1;auxiliar < maior.ano;auxiliar++){
					if((int) auxiliar%4 == 0){
						if((int) auxiliar%100 == 0 && (int) auxiliar%400 != 0){

						}
							else {
								diasentreanos += 366;
							}
					}
						
						else {
							diasentreanos += 365;
						}
				}
				auxiliar =  0;
			
				if (menor.mes == 2 && menor.dia == 29){

				}
					else{
						if (menor.mes==2){
							auxiliar = abs(28 - menor.dia);				
						}

						if (menor.mes==4 || menor.mes==6 || menor.mes==9 || menor.mes== 11){
							auxiliar = 30 - menor.dia;			
						}
						
						if (menor.mes==1||menor.mes==3||menor.mes==5||menor.mes==7||menor.mes==8||menor.mes==10
							||menor.mes==12) {
							auxiliar= 31 - menor.dia;			
						}
					}
			ret = diasentreanos+diasmesdomenor+diasmesdomaior+maior.dia+auxiliar+1;
			}


		
		if(maior.ano==menor.ano){
			if(maior.mes==menor.mes){
					ret = abs(maior.dia-menor.dia) + 1;
			}
				else {
					if(menor.mes < 2) {
						if((int) menor.ano%4 == 0){
							if((int) menor.ano%100 == 0 && (int) menor.ano%400 != 0){

							}
							else {
								somador++;
							}		
						}
					}
						
						if(menor.mes == 2){
							if((int) menor.ano%4 == 0 && menor.dia != 29){
								if((int) menor.ano%100 == 0 && (int) menor.ano%400 != 0){

								}
									else {
										somador++;
									}		
							}
						}

					if (menor.mes==2){
					    if(menor.dia != 29){
						auxiliar = 28 - menor.dia;			
					    }
					}

					if (menor.mes==4 || menor.mes==6 || menor.mes==9 || menor.mes== 11){
						auxiliar = 30 - menor.dia;			
					}
								
					if (menor.mes==1||menor.mes==3||menor.mes==5||menor.mes==7||menor.mes==8||menor.mes==10
						||menor.mes==12) {
					auxiliar= 31 - menor.dia;
					}
				
					for(i = menor.mes+1; i <= maior.mes-1; i++){
						if (i==2){
							somador += 28;				
						}

						if (i==4 || i==6 || i==9 || i == 11){
							somador += 30;			
						}
						
						if (i==1 || i==3 || i==5 || i == 7 || i==8 || i==10 || i==12 ){
							somador += 31;			
						}
					}
					ret = somador+auxiliar+maior.dia+1;


				}
		}



	return ret;
}


int main() {

data x,y;
long unsigned int resposta;
y.ano = 2020;
y.mes = 9;
y.dia = 17;

while(scanf("%f %f %f",&x.dia,&x.mes,&x.ano)!=EOF){
	maiordata(&x,&y);
	resposta = contadordiasentre(x,y);
	printf("%lu\n",resposta);
}
return 0;
}
