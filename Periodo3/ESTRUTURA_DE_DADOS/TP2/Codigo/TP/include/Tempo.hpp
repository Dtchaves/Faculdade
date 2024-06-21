#ifndef TEMPO_
#define TEMPO_

#include <iostream>
#include <ctime>

using namespace std;

/*Auxiliar para "Time_Clock_Combine"*/
double Compare_Clock_Time(struct timespec Time_Clock_Begin,struct timespec Time_Clock_End);

/*Devolve a comparação de tempo em s*/
double Time_Clock_Combine(struct timespec Time_Clock);


/*Usamos "clock_gettime(CLOCK_MONOTONIC,&(VARIAVEL_TIMESPEC))" na main para pegar o tempos iniciais e finais*/

#endif