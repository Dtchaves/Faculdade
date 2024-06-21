#include <stdio.h>
#include <stdlib.h>

long long int fibo(int n){

if (n == 0||n == 1){
    return n;
}
        else {
                return fibo(n-1) + fibo(n - 2);
        }
}

int main(){

    int n;
    scanf("%i",&n);
    printf("%lld",fibo(n));
return 0;
}