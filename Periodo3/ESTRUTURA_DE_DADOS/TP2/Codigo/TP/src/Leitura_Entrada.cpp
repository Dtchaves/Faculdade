#include <../include/Leitura_Entrada.hpp>

ifstream Abre_Arquivo(int argc,char ** argv){

    /*Ao ir tentando abrir o arquivo a função usa o throw para informar os diferentes erros possíveis*/
    string Nome_do_Arquivo_de_Entrada;
    if(argc == 2)Nome_do_Arquivo_de_Entrada.assign(argv[1]);
    if(argc > 2) throw Muitos_Argumentos{argc};
    if(argc < 2) throw Poucos_Argumentos{argc};

    ifstream Arquivo_de_Entrada(Nome_do_Arquivo_de_Entrada);
    if(!Arquivo_de_Entrada)throw Arquivo_Invalido{Nome_do_Arquivo_de_Entrada};

    return Arquivo_de_Entrada;
}

Pontos_Quantidade* Le_Arquivo(ifstream* Arquivo_de_Entrada){
    Pilha<Ponto> Entrada;
    string Auxiliar_X,Auxiliar_Y;

    /*Pegando os pontos com uma pilha auxiliar pois o tamanho de entrada não foi fornecido*/
    while(*Arquivo_de_Entrada>>Auxiliar_X>>Auxiliar_Y){
        /*Empilhando os pontos*/
        Ponto Auxiliar;
        Auxiliar.Monta_Ponto(stoi(Auxiliar_X),stoi(Auxiliar_Y));
        Entrada.Empilha(Auxiliar);
        Auxiliar_X = "";
        Auxiliar_Y = "";
    }

    /*Esses pontos e seu tamanho são passados para um vetor de pontos dentro da struct "Pontos_Quantidade"*/
    int Tamanho_Entrada = Entrada.Retorna_Tamanho();
    Pontos_Quantidade* Retorno = new Pontos_Quantidade;
    Retorno->Vetor_Pontos = new Ponto[Tamanho_Entrada];
    Retorno->Tamanho = Tamanho_Entrada;
    int i;
    for(i = 0;i<Tamanho_Entrada;i++){
        Retorno->Vetor_Pontos[i] = Entrada.Desempilha();
    }   

    return Retorno;
}
