#include <stdio.h>


void main(){

int x=10;
int *px,**ppx;
px = &x;
ppx = &px;

printf("\n&x = %p\n",&x);
printf("px = %p\n",px);
printf("ppx = %p\n",*ppx);
}



