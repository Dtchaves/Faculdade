#include <../include/entrada.hpp>

void le_args(int argc,char ** argv,ifstream& arquivo_de_entrada,ofstream& arquivo_de_saida,string& opcao){

    /*Ao ir tentando abrir o arquivo a função usa o throw para informar os diferentes erros possíveis*/
    string nome_do_arquivo_de_entrada,nome_do_arquivo_de_saida;
    if(argc == 4){
        opcao = (argv[1]);
        nome_do_arquivo_de_entrada.assign(argv[2]);
        nome_do_arquivo_de_saida.assign(argv[3]);

    }
    if(argc > 4) throw muitos_argumentos{argc};
    if(argc < 4) throw poucos_argumentos{argc};

    /*Checando a opção*/
    if((opcao != "-c")&&(opcao != "-d")) throw opcao_invalida{opcao};

    /*Abrindo os arquivos*/
    /*Na compactação a saída é binária*/
    if(opcao == "-c"){
        arquivo_de_entrada.open(nome_do_arquivo_de_entrada);
        if(!arquivo_de_entrada)throw arquivo_invalido{nome_do_arquivo_de_entrada};

        arquivo_de_saida.open(nome_do_arquivo_de_saida,ios::binary);
        if(!arquivo_de_saida)throw arquivo_invalido{nome_do_arquivo_de_saida};
    }

    /*Na descompactação a entrada é binária*/
    if(opcao == "-d"){
        arquivo_de_entrada.open(nome_do_arquivo_de_entrada,ios::binary);
        if(!arquivo_de_entrada)throw arquivo_invalido{nome_do_arquivo_de_entrada};

        arquivo_de_saida.open(nome_do_arquivo_de_saida);
        if(!arquivo_de_saida)throw arquivo_invalido{nome_do_arquivo_de_saida};
    }


    return;
}