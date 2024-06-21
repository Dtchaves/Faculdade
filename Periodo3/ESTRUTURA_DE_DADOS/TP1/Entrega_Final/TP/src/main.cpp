#include <iostream>
#include <iomanip>
#include <string>
#include <../include/Arvore.hpp>
#include <../include/Leitura_Entrada.hpp>

using namespace std;


int main(int argc,char ** argv){

    /*Variável que vai armazenar a expressão em forma de arvore e vai retornar todos os possíveis valores dela*/
    Arvore Armazenamento;
    /*Variável que vai armazenar se o arquivo de entrada é válida ou não*/
    bool Arquivo_Valido = true;
    /*Variável que vai armazenar se a expressão de entrada é válida ou não*/
    bool Expressao_Valida = true;


    FILE* Arquivo_de_Entrada;
    try{
        /*Try usado de forma estratégica para conseguir receber os diferentes erros e mostrar mensagens 
        diferentes de acordo com cada um deles*/
        Arquivo_de_Entrada = Abre_Arquivo(argc,argv);
    }
    catch(Muitos_Argumentos Invalido){
        cout<<"ERRO: Muitos argumentos foram passados como entrada"<<endl;
        Arquivo_Valido = 0;
    }
    catch(Poucos_Argumentos Invalido){
        cout<<"ERRO: Não foram passados argumentos como entrada"<<endl;
        Arquivo_Valido = 0;
    }
    catch(Arquivo_Invalido Invalido){
        cout<<"ERRO: Arquivo inválido"<<endl;
        Arquivo_Valido = 0;
    } 

    if(Arquivo_Valido){
        char Linha_Entrada[1100];
        while(fgets(Linha_Entrada,1100,Arquivo_de_Entrada)){
            string Entrada(Linha_Entrada);
            
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
            if((Funcao != "LER")&&(Funcao != "POSFIXA")&&(Funcao != "INFIXA")&&(Funcao != "RESOLVE")) cout<<"A operação \'"<<Funcao<<"\' nao é válida"<<endl;
        }

        fclose(Arquivo_de_Entrada);
    }
    
    return 0;
}