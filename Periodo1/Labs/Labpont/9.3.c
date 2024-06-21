#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct florzinha {
double valores[4]; //0 = largura da sépala | 1 = comprimento da pétala | 2 = largura da pétala |3 = comprimento da sépala
char tipo [50];
}iris;


//Realizar a leitura de n registros do tipo Iris;

void leitura_catalogar(iris vet[], int n) {
int i;

	for(i = 0; i < n; i++){
		scanf("%lf %lf %lf %lf",&vet[i].valores[0],&vet[i].valores[1],&vet[i].valores[2], &vet[i].valores[3]);
		scanf("%s",vet[i].tipo);
	}  
}

/*Encontrar o registro que possui a menor distância euclidiana em relação aos valores lidos;
Imprimir o tipo da flor deste registro com a menor distância euclidiana.*/

void classificar(iris x, iris vet[], int n){
double euclidiana = 0,aux = 0;
int j,i, guardarvaga = 0;

for( j = 0; j < 4; j++){
	euclidiana += pow((vet[0].valores[j] - x.valores[j]),2);
}
euclidiana = sqrt(euclidiana);

for( i = 0; i < n; i++){
	for( j = 0; j < 4; j++){
		aux += pow((vet[i].valores[j] - x.valores[j]),2);
	}
	aux = sqrt(aux);
	if(aux < euclidiana){
		guardarvaga = i;
		euclidiana = aux;
	}
	aux = 0;
}

strcpy(x.tipo,vet[guardarvaga].tipo);
printf("%s",x.tipo);

}

void main() {
int n;
scanf("%i",&n);

iris vet[n],diferente;

leitura_catalogar(vet,n);
scanf("%lf %lf %lf %lf",&diferente.valores[0],&diferente.valores[1],&diferente.valores[2],&diferente.valores[3]);
classificar(diferente,vet, n);


}






