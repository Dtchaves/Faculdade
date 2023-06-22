#include <../include/Tempo.hpp>


double Time_Clock_Combine(struct timespec Time_Clock){
    return ((Time_Clock.tv_sec) + ((Time_Clock.tv_nsec)/10e9));
}

double Compare_Clock_Time(struct timespec Time_Clock_Begin,struct timespec Time_Clock_End){

    struct timespec Time_Clock;

    if (Time_Clock_End.tv_nsec < Time_Clock_Begin.tv_nsec){
        /*Ajuste necessario, utilizando um segundo de tv_sec*/
        Time_Clock.tv_nsec = 1000000000+Time_Clock_End.tv_nsec-Time_Clock_Begin.tv_nsec;
        Time_Clock.tv_sec = Time_Clock_End.tv_sec-Time_Clock_Begin.tv_sec-1;
    } else {
        Time_Clock.tv_nsec = Time_Clock_End.tv_nsec-Time_Clock_Begin.tv_nsec;
        Time_Clock.tv_sec = Time_Clock_End.tv_sec-Time_Clock_Begin.tv_sec;
    }
    return Time_Clock_Combine(Time_Clock);
}


