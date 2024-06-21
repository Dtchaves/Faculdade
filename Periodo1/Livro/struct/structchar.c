#include <stdio.h>
#include <stdlib.h>

typedef struct teste {
int idade;
char nome [20];
char sexualidade;
}pessoa;

int main ()
{
 
pessoa x = {18, "Diogo",'g'},y;
y = x;

printf("idade %d e nome %s %c",y.idade,y.nome,y.sexualidade);


return 0;
}
