#define _POSIX_C_SOURCE 199309L
#include <iostream>
#include <iomanip>
#include <fstream>

#include <../include/entrada.hpp>
#include <../include/tempo.hpp>
#include <../include/compactar.hpp>
#include <../include/descompactar.hpp>

using namespace std;

int main(int argc,char ** argv){

    ifstream arquivo_de_entrada;
    ofstream arquivo_de_saida;
    string opcao;

    bool valido = 1;
    try{
    /*Try usado de forma estratégica para conseguir receber os diferentes erros e mostrar mensagens 
    diferentes de acordo com cada um deles*/
        le_args(argc,argv,arquivo_de_entrada,arquivo_de_saida,opcao);
    }
    catch(muitos_argumentos invalido){
        cerr<<"ERRO: Muitos argumentos foram passados como entrada"<<endl;
        valido = 0;
    }
    catch(poucos_argumentos invalido){
        cerr<<"ERRO: Não foram passados argumentos suficientes como entrada"<<endl;
        valido = 0;
    }
    catch(arquivo_invalido invalido){
        cerr<<"ERRO: Arquivo \""<<invalido.invalido<<"\" inválido"<<endl;
        valido = 0;
    }
    catch(opcao_invalida invalido){
        cerr<<"ERRO: Opção \""<<invalido.invalido<<"\" inválida"<<endl;
        valido = 0;
    }


    /*Sendo a opção e os arquivos válidos é feito a compactação ou descompactação*/
    if(valido){
        struct timespec Time_Clock_Begin, Time_Clock_End;
        double tempo;
        if(opcao == "-c"){
            cout<<"Compactando..."<<endl;
            clock_gettime(CLOCK_MONOTONIC,&(Time_Clock_Begin));
            compactar(arquivo_de_entrada,arquivo_de_saida);
            clock_gettime(CLOCK_MONOTONIC,&(Time_Clock_End));
            cout<<"Arquivo compactado com sucesso!"<<endl;
            tempo = Compare_Clock_Time((Time_Clock_Begin),(Time_Clock_End));
            cout<<"Tempo gasto para compactar: "<<tempo<<"s"<<endl;


        }
        if(opcao == "-d"){
            cout<<"Desompactando..."<<endl;
            clock_gettime(CLOCK_MONOTONIC,&(Time_Clock_Begin));
            descompactar(arquivo_de_entrada,arquivo_de_saida);
            clock_gettime(CLOCK_MONOTONIC,&(Time_Clock_End));
            cout<<"Arquivo descompactado com sucesso!"<<endl;
            tempo = Compare_Clock_Time((Time_Clock_Begin),(Time_Clock_End));
            cout<<"Tempo gasto para descompactar: "<<tempo<<"s"<<endl;

        }
        arquivo_de_entrada.close();
        arquivo_de_saida.close();
    }

    return 0;
}