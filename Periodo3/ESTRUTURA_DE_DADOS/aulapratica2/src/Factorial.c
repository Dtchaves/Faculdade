#include <stdio.h>
#include <stdlib.h>
#include <../include/Factorial.h>

long long int Factorial_Recursive(long int n){
	if (n == 1){
		return 1;
	}
	else{
		return n*Factorial_Recursive(n-1);
	}
}

long long int Factorial_Iterative(long int n){
	long long int aux = 1;
	for(long int i = 2; i <=n; i ++){
		aux *= i;
	}
	return aux;
}

