#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>
#include <../include/Time_Counter.h>
#include <../include/Factorial.h>
#include <../include/Fibonacci.h>

double Time_Clock_Combine(struct timespec Time_Clock){
    return (Time_Clock.tv_sec) + ((Time_Clock.tv_nsec)/10e9);
}

double Time_System_User_Combine(struct timeval Time_System_User){
    return ((Time_System_User.tv_sec) + ((Time_System_User.tv_usec)/10e6));
}

double Compare_Clock_Time(struct timespec Time_Clock_Begin,struct timespec Time_Clock_End){

    struct timespec Time_Clock;

    if (Time_Clock_End.tv_nsec < Time_Clock_Begin.tv_nsec){
        // ajuste necessario, utilizando um segundo de tv_sec
        Time_Clock.tv_nsec = 1000000000+Time_Clock_End.tv_nsec-Time_Clock_Begin.tv_nsec;
        Time_Clock.tv_sec = Time_Clock_End.tv_sec-Time_Clock_Begin.tv_sec-1;
    } else {
        Time_Clock.tv_nsec = Time_Clock_End.tv_nsec-Time_Clock_Begin.tv_nsec;
        Time_Clock.tv_sec = Time_Clock_End.tv_sec-Time_Clock_Begin.tv_sec;
    }
    return Time_Clock_Combine(Time_Clock);
}

double Compare_System_User_Time(struct timeval Time_System_User_Begin,struct timeval Time_System_User_End){

    struct timeval Time_System_User;

    if (Time_System_User_End.tv_usec < Time_System_User_Begin.tv_usec){
        // ajuste necessario, utilizando um segundo de tv_sec
        Time_System_User.tv_usec = 1000000+Time_System_User_End.tv_usec-Time_System_User_Begin.tv_usec;
        Time_System_User.tv_sec = Time_System_User_End.tv_sec-Time_System_User_Begin.tv_sec-1;
    } else {
        Time_System_User.tv_usec = Time_System_User_End.tv_usec-Time_System_User_Begin.tv_usec;
        Time_System_User.tv_sec = Time_System_User_End.tv_sec-Time_System_User_Begin.tv_sec;
    }
    return Time_System_User_Combine(Time_System_User);
}

struct results Analise_Time(int func, int num){

    struct results Return_Value;
    struct timespec Time_Clock_Begin, Time_Clock_End;
    struct rusage Time_System_User_Begin,Time_System_User_End; 

    //Fibonacci
    if(func == 0){
        //Recursive time
        clock_gettime(CLOCK_MONOTONIC,&(Time_Clock_Begin));
        getrusage(RUSAGE_SELF,&(Time_System_User_Begin));

        Return_Value.Function_Result_Recursive = Fibonacci_Recursive(num);

        clock_gettime(CLOCK_MONOTONIC,&(Time_Clock_End));
        getrusage(RUSAGE_SELF,&(Time_System_User_End));

        Return_Value.Time_Clock_Recursive = Compare_Clock_Time((Time_Clock_Begin),(Time_Clock_End));
        Return_Value.Time_User_Recursive = Compare_System_User_Time((Time_System_User_Begin.ru_utime),(Time_System_User_End.ru_utime));
        Return_Value.Time_System_Recursive = Compare_System_User_Time((Time_System_User_Begin.ru_stime),(Time_System_User_End.ru_stime));


        //Iterative time
        clock_gettime(CLOCK_MONOTONIC,&(Time_Clock_Begin));
        getrusage(RUSAGE_SELF,&(Time_System_User_Begin));

        Return_Value.Function_Result_Iterative = Fibonacci_Iterative(num);

        clock_gettime(CLOCK_MONOTONIC,&(Time_Clock_End));
        getrusage(RUSAGE_SELF,&(Time_System_User_End));

        Return_Value.Time_Clock_Iterative = Compare_Clock_Time((Time_Clock_Begin),(Time_Clock_End));
        Return_Value.Time_User_Iterative = Compare_System_User_Time((Time_System_User_Begin.ru_utime),(Time_System_User_End.ru_utime));
        Return_Value.Time_System_Iterative = Compare_System_User_Time((Time_System_User_Begin.ru_stime),(Time_System_User_End.ru_stime));

    }

    //Fatorial
    else if(func == 1){
        //Recursive time
        clock_gettime(CLOCK_MONOTONIC,&(Time_Clock_Begin));
        getrusage(RUSAGE_SELF,&(Time_System_User_Begin));

        Return_Value.Function_Result_Recursive = Factorial_Recursive(num);

        clock_gettime(CLOCK_MONOTONIC,&(Time_Clock_End));
        getrusage(RUSAGE_SELF,&(Time_System_User_End));

        Return_Value.Time_Clock_Recursive = Compare_Clock_Time((Time_Clock_Begin),(Time_Clock_End));
        Return_Value.Time_User_Recursive = Compare_System_User_Time((Time_System_User_Begin.ru_utime),(Time_System_User_End.ru_utime));
        Return_Value.Time_System_Recursive = Compare_System_User_Time((Time_System_User_Begin.ru_stime),(Time_System_User_End.ru_stime));


        //Iterative time
        clock_gettime(CLOCK_MONOTONIC,&(Time_Clock_Begin));
        getrusage(RUSAGE_SELF,&(Time_System_User_Begin));

        Return_Value.Function_Result_Iterative = Factorial_Iterative(num);

        clock_gettime(CLOCK_MONOTONIC,&(Time_Clock_End));
        getrusage(RUSAGE_SELF,&(Time_System_User_End));

        Return_Value.Time_Clock_Iterative = Compare_Clock_Time((Time_Clock_Begin),(Time_Clock_End));
        Return_Value.Time_User_Iterative = Compare_System_User_Time((Time_System_User_Begin.ru_utime),(Time_System_User_End.ru_utime));
        Return_Value.Time_System_Iterative = Compare_System_User_Time((Time_System_User_Begin.ru_stime),(Time_System_User_End.ru_stime));

    }
    
    else {
        printf("ERRO");
    }

    return Return_Value;
}