#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.1415

long int mdc(long int a, long int b){
    if(a<b) return 0;

    long int r_one = b;
    long int r_two = a%b;
    long int aux;

    while(r_two){
        aux = r_two;
        r_two = r_one%r_two;
        r_one = aux;
    }
    return r_one;
}

int main(){

    srand(time(NULL));
    long int a;
    long int b;
    int equal_one;
    float result;

    int times_[] = {10,100,1000,10000,100000};
    for(int i = 0;i<5;i++){
        equal_one = 0;
        for(int j = 0;j<times_[i];j++){
            a = 0;
            b = 1;
            while( a < b ){
                a = rand();
                b = rand();
            }
            if(mdc(a,b) == 1) equal_one++;
        }
        result = (float) equal_one/times_[i];
        printf("Para %d casos o valor é %f \n", times_[i],result);
    }
    printf("6/pi^2 = %f \n", 6/pow(PI,2));
    printf("Logo podemos ver que os valores estão se aproximando dessa constante.\n");

    return 0;
}