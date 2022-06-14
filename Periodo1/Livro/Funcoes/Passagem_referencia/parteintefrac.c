/* Escreva uma função que, dado um número real passado como parâmetro, retorne
a parte inteira e a parte fracionária desse número por referência.*/

#include <stdio.h>

typedef struct nu{
float fracionada,numero;
int inteira;

}numero;

void partes(numero *n) {

n->inteira = (int) n->numero;
n->fracionada = n->numero - n->inteira;

}



int main () {

numero i;

scanf("%f",&i.numero);
partes(&i);
printf("parte inteira = %d\nparte fracionaria= %f\n",i.inteira,i.fracionada);

return 0;
}
