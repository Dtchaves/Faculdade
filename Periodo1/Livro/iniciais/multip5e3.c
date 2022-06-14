#include <stdio.h>
#include <stdlib.h>

int main ()
{
for(int c=0;c<=10000;c++)  {
 if (c%3 == 0 || c%5 == 0) {
  printf("%i\n",c);
  }
}

return 0;

}

