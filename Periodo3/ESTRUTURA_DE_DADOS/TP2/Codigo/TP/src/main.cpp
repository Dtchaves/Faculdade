#define _POSIX_C_SOURCE 199309L
#include <iostream>
#include <iomanip>
#include <fstream>

#include <../include/Tempo.hpp>
#include "../include/Ponto.hpp"
#include "../include/Reta.hpp"
#include "../include/Leitura_Entrada.hpp"
#include <../include/Fecho_Convexo.hpp>



using namespace std;

int main(int argc,char ** argv){


    ifstream* Arquivo_de_Entrada = new ifstream;
    bool Valido = 1;
    try{
    /*Try usado de forma estratégica para conseguir receber os diferentes erros e mostrar mensagens 
    diferentes de acordo com cada um deles*/

        *Arquivo_de_Entrada = Abre_Arquivo(argc,argv);
    }
    catch(Muitos_Argumentos Invalido){
        cerr<<"ERRO: Muitos argumentos foram passados como entrada"<<endl;
        Valido = 0;
    }
    catch(Poucos_Argumentos Invalido){
        cerr<<"ERRO: Não foram passados argumentos como entrada"<<endl;
        Valido = 0;
    }
    catch(Arquivo_Invalido Invalido){
        cerr<<"ERRO: Arquivo inválido"<<endl;
        Valido = 0;
    } 

    if(Valido){
        srand(time(NULL));
        struct timespec Time_Clock_Begin, Time_Clock_End;
        double Time_Jarvismarch = 0.0, Time_Grahamscan_Insert = 0.0, Time_Grahamscan_Merge = 0.0, Time_Grahamscan_Bucket = 0.0;

        Pontos_Quantidade* Entrada = Le_Arquivo(Arquivo_de_Entrada);
        Fecho_Convexo Jarvismarch;
        Fecho_Convexo Grahamscan_Insert;
        Fecho_Convexo Grahamscan_Merge;
        Fecho_Convexo Grahamscan_Bucket;

        try{
        /*Try usado de forma estratégica para conseguir receber os diferentes erros e mostrar mensagens 
        diferentes de acordo com cada um deles*/

            /*Tempo do JARVIS*/
            clock_gettime(CLOCK_MONOTONIC,&(Time_Clock_Begin));
            Jarvismarch.Montar_Fecho_Convexo("Jarvismarch","NENHUMA ORDENAÇÂO",Entrada->Vetor_Pontos,Entrada->Tamanho);
            clock_gettime(CLOCK_MONOTONIC,&(Time_Clock_End));
            Time_Jarvismarch = Compare_Clock_Time((Time_Clock_Begin),(Time_Clock_End));

            /*Tempo do GRAHAM+MERGESORT*/
            clock_gettime(CLOCK_MONOTONIC,&(Time_Clock_Begin));
            Grahamscan_Merge.Montar_Fecho_Convexo("Grahamscan","MergeSort",Entrada->Vetor_Pontos,Entrada->Tamanho);
            clock_gettime(CLOCK_MONOTONIC,&(Time_Clock_End));
            Time_Grahamscan_Merge = Compare_Clock_Time((Time_Clock_Begin),(Time_Clock_End));

            /*Tempo do GRAHAM+LINEAR*/
            clock_gettime(CLOCK_MONOTONIC,&(Time_Clock_Begin));
            Grahamscan_Bucket.Montar_Fecho_Convexo("Grahamscan","BucketSort",Entrada->Vetor_Pontos,Entrada->Tamanho);
            clock_gettime(CLOCK_MONOTONIC,&(Time_Clock_End));
            Time_Grahamscan_Bucket = Compare_Clock_Time((Time_Clock_Begin),(Time_Clock_End));
            
            /*Tempo do GRAHAM+INSERTIONSORT*/
            clock_gettime(CLOCK_MONOTONIC,&(Time_Clock_Begin));
            Grahamscan_Insert.Montar_Fecho_Convexo("Grahamscan","InsertionSort",Entrada->Vetor_Pontos,Entrada->Tamanho);
            clock_gettime(CLOCK_MONOTONIC,&(Time_Clock_End));
            Time_Grahamscan_Insert = Compare_Clock_Time((Time_Clock_Begin),(Time_Clock_End));
        }
        catch(Algoritmo_Invalido Invalido){
        cerr<<" \""<<Invalido.Algoritmo<<"\" não é um algoritmo válido"<<endl;
        Valido = 0;
        }
        catch(Ordenacao_Invalida Invalido){
        cerr<<" \""<<Invalido.Ordenacao<<"\" não é uma ordenação válida"<<endl;
        Valido = 0;
         }

        if(Valido){

            /*IMPRIMIR*/
            cout<<endl;
            cout<<"FECHO CONVEXO: "<<endl;
            Jarvismarch.Imprimir_Fecho_Convexo();

            cout << endl << fixed << setprecision(6);
            cout<<"GRAHAM+MERGESORT: "<<Time_Grahamscan_Merge<<endl;
            cout<<"GRAHAM+INSERTIONSORT: "<<Time_Grahamscan_Insert<<endl;
            cout<<"GRAHAM+LINEAR: " <<Time_Grahamscan_Bucket<<endl;
            cout<<"JARVIS: "<<Time_Jarvismarch<<endl;
            cout<<endl;

        }
        
        delete [] Entrada->Vetor_Pontos;
        delete Entrada;
    }

    delete Arquivo_de_Entrada;
    return 0;
}