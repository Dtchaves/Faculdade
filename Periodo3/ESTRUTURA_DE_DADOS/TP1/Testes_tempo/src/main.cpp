#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include <sys/resource.h>
#include <../include/Arvore.hpp>
#include <../include/Leitura_Entrada.hpp>

using namespace std;

//COPIAAAAAAAAAAAAAAAAAAAAAAAAAAA

double Time_Clock_Combine(struct timespec Time_Clock){
    return (Time_Clock.tv_sec) + ((Time_Clock.tv_nsec)/10e9);
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

int main(int argc,char ** argv){

    struct timespec Time_Clock_Begin, Time_Clock_End;

    clock_gettime(CLOCK_MONOTONIC,&(Time_Clock_Begin));

    /*Variável que vai armazenar a expressão em forma de arvore e vai retornar todos os possíveis valores dela*/
    Arvore Armazenamento;
    /*Variável que vai armazenar se o arquivo de entrada é válida ou não*/
    bool Arquivo_Valido = true;
    /*Variável que vai armazenar se a expressão de entrada é válida ou não*/
    bool Expressao_Valida = true;
    double tempo_primeira_parte;
    
    FILE* Arquivo_de_Entrada;
    try{
        /*Try usado de forma estratégica para conseguir receber os diferentes erros e mostrar mensagens 
        diferentes de acordo com cada um deles*/
        Arquivo_de_Entrada = Abre_Arquivo(argc,argv);
    }
    catch(Muitos_Argumentos Invalido){
        cout<<"Muitos argumentos foram passados como entrada"<<endl;
        Arquivo_Valido = 0;
    }
    catch(Poucos_Argumentos Invalido){
        cout<<"Não foram passados argumentos como entrada"<<endl;
        Arquivo_Valido = 0;
    }
    catch(Arquivo_Invalido Invalido){
        cout<<"Arquivo inválido"<<endl;
        Arquivo_Valido = 0;
    } 

    clock_gettime(CLOCK_MONOTONIC,&(Time_Clock_End));
    tempo_primeira_parte = Compare_Clock_Time((Time_Clock_Begin),(Time_Clock_End));
    tempo_primeira_parte = tempo_primeira_parte*1000;

    int contador = 0;

    double media_tempo = 0;

    if(Arquivo_Valido){
        char Linha_Entrada[1100];
        while(fgets(Linha_Entrada,1100,Arquivo_de_Entrada)){
            string Entrada(Linha_Entrada);

            clock_gettime(CLOCK_MONOTONIC,&(Time_Clock_Begin));
            while(contador < 3){
                int i = 0;
                /* Informa qual operação tem que ser feita*/
                string Funcao = Retorna_Funcao(&Entrada,&i);
            
                /*São as possíveis operações que devem ser feitas*/
                /*Ler a expressão, ver se é válida e se sim armazenar*/
                if(Funcao == "LER") Expressao_Valida =  Ler_Expressao(i,Entrada,&Armazenamento);
                /*Retornar a expressão posfixa se tiver uma expressão armazenada ou uma mensagem de erro se não tiver*/
                if(Funcao == "POSFIXA") Retornar_Posfixa(Expressao_Valida,&Armazenamento);
                /*Retornar a expressão infixa se tiver uma expressão armazenada ou uma mensagem de erro se não tiver*/
                if(Funcao == "INFIXA") Retornar_Infixa(Expressao_Valida,&Armazenamento);
                /*Retornar o resultado se tiver uma expressão armazenada ou uma mensagem de erro se não tiver*/
                if(Funcao == "RESOLVE") Retornar_Resultado(Expressao_Valida,&Armazenamento);
                /*Qualquer coisa além das operaçõs citadas é inválido*/
                if((Funcao != "LER")&&(Funcao != "POSFIXA")&&(Funcao != "INFIXA")&&(Funcao != "RESOLVE")) cout<<"A operação \'"<<Funcao<<"\' nao é váida"<<endl;
                contador++;

                if(contador != 2){
                    fgets(Linha_Entrada,1100,Arquivo_de_Entrada);
                    string aux(Linha_Entrada);
                    Entrada = aux;
                }
            }
            clock_gettime(CLOCK_MONOTONIC,&(Time_Clock_End));
            double resultado;
            resultado = Compare_Clock_Time((Time_Clock_Begin),(Time_Clock_End));
            resultado = resultado*1000;
            resultado += tempo_primeira_parte;
            media_tempo += resultado;
            contador = 0;
        }

        fclose(Arquivo_de_Entrada);
    }

     printf("%.10gms \n",media_tempo/4);
    return 0;
}