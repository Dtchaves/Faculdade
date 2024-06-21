#include <stdlib.h>
#include <stdio.h>
#include <../include/Fibonacci.h>

long long int Fibonacci_Recursive(long int n){
	if(n == 1){
		return 1;
	}
	else if(n == 2){
		return 1;
	}
	else{
		return Fibonacci_Recursive(n-1) + Fibonacci_Recursive(n-2);
	}
}

long long int Fibonacci_Iterative(long int n){
	long long int a2 = 1;
	long int a1 = 1;
	for(long int i = n-2;i > 0;i --){
		long long int aux = a2;
		a2 += a1;
		a1 = aux;
	}	
	return a2;
}
