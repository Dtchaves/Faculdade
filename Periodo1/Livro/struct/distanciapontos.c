#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ponto {
int x,y;
}ponto;


int dist_(ponto n,ponto m) {
int d;

m.x -= n.x;
m.y -= n.y;
d = m.x*m.x + m.y*m.y;
return sqrt(d);
}

void main () {

ponto um,dois;
int dsi;

scanf("%i %i", &um.x,&um.y);
scanf("%i %i", &dois.x,&dois.y);
dsi = dist_(um,dois);

printf("%i",dsi);
return;
}












