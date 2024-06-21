#ifndef TEMPO_
#define TEMPO_

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*Auxiliar para "Time_Clock_Combine"*/
double Compare_Clock_Time(struct timespec Time_Clock_Begin,struct timespec Time_Clock_End);

/*Devolve a comparação de tempo em ms*/
double Time_Clock_Combine(struct timespec Time_Clock);


/*clock_gettime(CLOCK_MONOTONIC,&(Time_Clock_?));*/

#endif