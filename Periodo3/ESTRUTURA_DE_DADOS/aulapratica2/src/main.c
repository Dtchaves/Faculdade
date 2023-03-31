#include <stdio.h>
#include <stdlib.h>
#include <../include/Time_Counter.h>
#include <../include/Factorial.h>
#include <../include/Fibonacci.h>

int main(int argc, char **argv){

    //0 = Fatorial 1= Fibonacci
    int func = atoi(argv[1]);

    //numero
    long int num = atoi(argv[2]);

    //Fibonacci
    if(func == 0){
        struct results analise = Analise_Time(func,num);

        printf("\n \t Fibonacci de %ld \n",num);
        printf("Recursivo:\n");
        printf("Valor = %lld \n",analise.Function_Result_Recursive);
        printf("Tempo de Relógio = %.10gs \n",analise.Time_Clock_Recursive);
        printf("Tempo de Sistema = %.10gs \n",analise.Time_System_Recursive);
        printf("Tempo de Usuário = %.10gs \n",analise.Time_User_Recursive);
        printf("Iterativo:\n");
        printf("Valor = %lld \n",analise.Function_Result_Iterative);
        printf("Tempo de Relógio = %.10gs \n",analise.Time_Clock_Iterative);
        printf("Tempo de Sistema = %.10gs \n",analise.Time_System_Iterative);
        printf("Tempo de Usuário = %.10gs \n",analise.Time_User_Iterative);
        }
    
    //Factorial
    else{
        struct results analise = Analise_Time(func,num);

        printf("\n \t Fatorial de %ld \n",num);
        printf("Recursivo:\n");
        printf("Valor = %lld \n",analise.Function_Result_Recursive);
        printf("Tempo de Relógio = %.10gs \n",analise.Time_Clock_Recursive);
        printf("Tempo de Sistema = %.10gs \n",analise.Time_System_Recursive);
        printf("Tempo de Usuário = %.10gs \n",analise.Time_User_Recursive);
        printf("Iterativo:\n");
        printf("Valor = %lld \n",analise.Function_Result_Iterative);
        printf("Tempo de Relógio = %.10gs \n",analise.Time_Clock_Iterative);
        printf("Tempo de Sistema = %.10gs \n",analise.Time_System_Iterative);
        printf("Tempo de Usuário = %.10gs \n",analise.Time_User_Iterative);
        }


    return 0;
}

