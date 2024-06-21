#define _POSIX_C_SOURCE 199309L
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <../include/Tempo.h>
#include <../include/Heapsort.h>
#include <../include/Shellsort.h>
#include <../include/Insertsort.h>
#include <../include/Vetor.h>

int main(int argc,char **argv){

    srand(time(NULL));
    struct timespec Time_Clock_Begin, Time_Clock_End;
    double Time_Heap = 0.0, Time_Shell_H1 = 0.0, Time_Shell_H2 = 0.0, Time_Insert = 0.0;

    /*Arquivos csv com as info de tempo para passar para o código em python*/
    FILE *Heap_csv;
    Heap_csv = fopen("./Time_Heap.csv","w");
    fprintf(Heap_csv, "Tamanho do Vetor,Tempo do Heap em ms \n");

    FILE *Insert_csv;
    Insert_csv = fopen("./Time_Insert.csv","w");
    fprintf(Insert_csv, "Tamanho do Vetor,Tempo do Insertsort em ms \n");

    FILE *Shell_H1_csv; 
    Shell_H1_csv = fopen("./Time_Shell_H1.csv","w");
    fprintf(Shell_H1_csv, "Tamanho do Vetor,Tempo do Shellsort_1 em ms \n");

    FILE *Shell_H2_csv;
    Shell_H2_csv = fopen("./Time_Shell_H2.csv","w");
    fprintf(Shell_H2_csv, "Tamanho do Vetor,Tempo do Shellsort_2 em ms \n");

    for(int Tamanho = 100000; Tamanho <= 1000000; Tamanho += 100000){  
        
        int Testes = 1;
        /*Para Cada um dos tamanhos são feitos 10 testes e a media do tempo é levada para análise*/
        while(Testes <= 10){
            int* Vetor = (int *) malloc(sizeof(int)*Tamanho);
            int i;
            for (i = 0; i < Tamanho;  i++) {
                Vetor[i] = rand()%Tamanho;
            }
            /*Toda vez antes de chamar um ordenador é necessário criar uma cópia do vetor antes dele ser ordenado,
            se não perderiamos esse vetor e não teriamos como comparar*/
            int* Vetor_Copia = (int *) malloc(sizeof(int)*Tamanho);

            /*Descobre os tempos para depois fazer a media para analise*/
            /*Heapsort*/
            Copia_Vetor(Vetor, Vetor_Copia,Tamanho);
            clock_gettime(CLOCK_MONOTONIC,&(Time_Clock_Begin));
            Heapsort(Vetor_Copia,Tamanho);
            clock_gettime(CLOCK_MONOTONIC,&(Time_Clock_End));
            Time_Heap += Compare_Clock_Time((Time_Clock_Begin),(Time_Clock_End));

            /*Insertsort*/
            Copia_Vetor(Vetor, Vetor_Copia,Tamanho);
            clock_gettime(CLOCK_MONOTONIC,&(Time_Clock_Begin));
            //Insertsort(Vetor_Copia,Tamanho);
            clock_gettime(CLOCK_MONOTONIC,&(Time_Clock_End));
            Time_Insert += Compare_Clock_Time((Time_Clock_Begin),(Time_Clock_End));


            /*Shellsort com H1*/
            Copia_Vetor(Vetor, Vetor_Copia,Tamanho);
            clock_gettime(CLOCK_MONOTONIC,&(Time_Clock_Begin));
            Shellsort_H1(Vetor_Copia,Tamanho);
            clock_gettime(CLOCK_MONOTONIC,&(Time_Clock_End));
            Time_Shell_H1 += Compare_Clock_Time((Time_Clock_Begin),(Time_Clock_End));

            /*Shellsort com H2*/
            Copia_Vetor(Vetor, Vetor_Copia,Tamanho);
            clock_gettime(CLOCK_MONOTONIC,&(Time_Clock_Begin));
            Shellsort_H2(Vetor_Copia,Tamanho);
            clock_gettime(CLOCK_MONOTONIC,&(Time_Clock_End));
            Time_Shell_H2 += Compare_Clock_Time((Time_Clock_Begin),(Time_Clock_End));

            Testes++;
        }
        /*Descobre a média e passa para o csv*/
        fprintf(Heap_csv, "%d,%lf \n",Tamanho,(Time_Heap/10.0));
        fprintf(Shell_H1_csv, "%d,%lf \n",Tamanho,(Time_Shell_H1/10.0));
        fprintf(Shell_H2_csv, "%d,%lf \n",Tamanho,(Time_Shell_H2/10.0));
        fprintf(Insert_csv, "%d,%lf \n",Tamanho,(Time_Insert/10.0));

        Time_Heap = 0.0;
        Time_Shell_H1 = 0.0;
        Time_Shell_H2 = 0.0;
        Time_Insert = 0.0;

    }

    fclose(Heap_csv);
    fclose(Shell_H1_csv);
    fclose(Shell_H2_csv);
    fclose(Insert_csv);

    return 0;
}