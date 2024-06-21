/*Escreva um programa que contenha duas variáveis inteiras. Compare seus endere-
ços e exiba o maior endereço */

#include <stdio.h>


void main(){

int x,y;
int *px,*py;
px = &x;
py = &y;


if (px > py) 
printf("%p\n",px);
if (px < py) 
printf("%p\n",py);
}



