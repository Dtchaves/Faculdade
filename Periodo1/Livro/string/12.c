#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
char nomeproduto[1000];
int tamanho;
float preco,desconto,vista;

fgets(nomeproduto,1000,stdin);
tamanho = strlen(nomeproduto);
nomeproduto[tamanho - 1] = '\0';
scanf("%f",&preco);
desconto = preco * 0.1;
vista = preco - desconto;

printf("\n A mercadoria %s tem o preço de $%.2f. Ao pagar a vista você recebe o desconto de $%.2f e o preco fica $%.2f\n",nomeproduto,preco,desconto,vista);

return 0;
}
