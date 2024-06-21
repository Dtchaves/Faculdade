/*13) Crie uma função que receba um vetor de tamanho N e ordene os seus valores.
15) Elabore uma função que receba um vetor contendo N valores e retorne por refe-
rência o maior e o menor elemento desse vetor.
16) Elabore uma função que receba um vetor contendo N valores e retorne por refe-
rência o maior elemento do vetor e o número de vezes que esse elemento ocorreu
no vetor.
*/

#include <stdio.h>


typedef struct vetor{
float vet[10];
float maior,menor;
int vezesmenor,vezesmaior;
}vetor;

void ordenar(vetor *x){
int i,j,aux = 1;
float troca;

	for (i = 0;i<10;i++){
		for( j = aux; j < 10;j++){
			if(x->vet[i]>x->vet[j]){
				troca = x->vet[i];
				x->vet[i] = x->vet[j];
				x->vet[j] = troca;
			}
		}
		aux++;
	}
	
	x->maior = x->vet[9];
	x->menor = x->vet[0];
}

void vezesm(vetor *x){
int i;
 x -> vezesmenor = 0;
x -> vezesmaior = 0;
ordenar(x);

	for (i = 0;i<10;i++){
		if(x->vet[i] == x->maior){
			x->vezesmaior++;
		}

		if(x->vet[i] == x->maior){
			x->vezesmenor++;
		}

	}
}


int main () {
vetor entrada;
int i;

for(i = 0; i<10;i++){
	scanf("%f",&entrada.vet[i]);
}
vezesm(&entrada);
printf("maior = %f\naparece %i vezes\nmenor = %f\naparece %i vezes\n",entrada.maior,entrada.vezesmaior,entrada.menor,entrada.vezesmenor);

return 0;
}





