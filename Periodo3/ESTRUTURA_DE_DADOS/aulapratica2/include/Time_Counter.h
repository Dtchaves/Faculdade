#ifndef TIME_COUNTER
#define TIME_COUNTER

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>

//To keep results
struct results{
    double Time_Clock_Recursive, Time_Clock_Iterative;
    double Time_User_Recursive, Time_User_Iterative; 
    double Time_System_Recursive, Time_System_Iterative; 
    long long int Function_Result_Recursive, Function_Result_Iterative;
};

//
double Time_Clock_Combine(struct timespec Time_Clock);

//
double Time_System_User_Combine(struct timeval Time_System_User);

//Give the process real clock time 
double Compare_Clock_Time(struct timespec Time_Clock_Begin,struct timespec Time_Clock_End);

//Give the process real system and user times
double Compare_System_User_Time(struct timeval Time_System_User_Begin,struct timeval Time_System_User_End);

//Return the real clock time, system time, user time and value of the function
struct results Analise_Time(int func, int num);

#endif