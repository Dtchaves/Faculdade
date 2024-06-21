#include <../include/descompactar.hpp>


int le_bit(ifstream& arquivo_de_entrada){
    static int vaga = 8;
    unsigned char byte;
    static int bit[8];
    int retorno;

    /*Se a vaga atual que está sendo usada for 8 significa que percorremos o byte inteiro e precisamos de um novo*/
    if(vaga == 8){
        arquivo_de_entrada.read(reinterpret_cast<char*>(&byte), sizeof(byte));
        for(int i = 7;i > -1; i--){
            bit [i] = (byte >> i) & 1;
        }
        vaga = 0;
    }

    /*Retorna individualmente cada bit do byte que foi lido*/
    retorno = bit[vaga];
    vaga++;
    return retorno;

}

long total_palavras(vocabulario* vocab){
    int i;
    long tamanho = 0;
    /*Percorre o vetor de frequencias somando para achar o total de palavras no texto*/
    for(i = 0;i<vocab->tamanho;i++){
        tamanho += vocab->vetor[i].ocorrencia;
    }
    return tamanho;
}

vocabulario* ler_chave(ifstream& arquivo_de_entrada){
    /*Pega a primeira linha, que de fato é onde esta as palavras e as frequencias*/
    string l;
    getline(arquivo_de_entrada, l);
    stringstream linha(l);

    /*Retorna o total de palavras distintas que o texto possui*/
    int tamanho;
    linha>>tamanho;

    /*Cria um vocabulario*/
    vocabulario* vocab = new vocabulario;
    vocab->tamanho = tamanho;
    vocab->vetor = new palavra_ocorrencia[tamanho];
    string palavra;
    int freq;
    int i = 0;
    /*Vai pegando individualmente as palavras e suas frequencias que, de fato já foram escritas de forma ordenada a fim de minimizar custos*/
    while(linha>>palavra>>freq){
        vocab->vetor[i].palavra = palavra;
        vocab->vetor[i].ocorrencia = freq;
        i++;
    }
    return vocab;
}

void escrever_descompactado(ifstream& arquivo_de_entrada,ofstream& arquivo_de_saida,long* base, long* offset,long* comprimentos,vocabulario* vocab,dicionario* dic, long total_p){
    int i;

    /*Hash para poder fazer as buscas pelo dicionario de forma mais rápida*/
    elemento_hash_escrita* hash = new elemento_hash_escrita[MAX_HASH];
    for(i = 0; i < vocab->tamanho;i++){
        /*A função de hash vai ser definida em função dos códigos, tendo em vista que queremos achar as palavras correspondentes*/
        int vaga_hash = (dic[i].codigo)%(MAX_HASH);
        hash[vaga_hash].insere(dic[i]);
    }
    
    string byte;
    dicionario prox;
    int num_palavras = 0;
    while (1){
        int c = 1;
        long long int cod = le_bit(arquivo_de_entrada);
        /*Loop para achar o código através de uma comparação com o vetor base*/
        while(((cod<<1) >= base[c]) && (c + 1 <= comprimentos[(vocab->tamanho)-1])){
            cod = le_bit(arquivo_de_entrada) | (cod << 1);
            c++;
        }
        
        /*Utiliza o hash criado para achar a palavra através do código*/
        int vaga_hash = cod%(MAX_HASH);
        prox = hash[vaga_hash].procura_cod(cod);

        /*Escreve as palavras no arquivo de saída*/
        if((num_palavras+1) == total_p){
            arquivo_de_saida<<prox.palavra;
            break;
        }
        else{
            arquivo_de_saida<<prox.palavra<<" ";
        }
        num_palavras++;
    }


    delete [] hash;
}


void descompactar(ifstream& arquivo_de_entrada,ofstream& arquivo_de_saida){

    /*Pega o vocabulário do arquivo de entrada*/
    vocabulario* vocab = ler_chave(arquivo_de_entrada);
    long total_p = total_palavras(vocab);

    int i;

    /*Cria o vetor com as ocorrencias que, utilizando o algoritmo de Moffat e Katajainen, irá se tornar um vetor das alturas que cada
    palavra ocuparia na árvore de huffman*/
    long * comprimentos = new long[vocab->tamanho];
    for(i = 0;i<vocab->tamanho;i++){
        comprimentos[i] = vocab->vetor[i].ocorrencia;
    }

    /*Usa o huffman para calcular as alturas das palavras na árvore que, de fato, são iguais aos comprimentos dos códigos das palavras*/
    calcula_comprimento(comprimentos,vocab->tamanho);

    /*A partir das alturas obtidas é montado os vetores base e offset que, utilizando também as ideias de Moffat e Katajainen irá dar origem 
    aos códigos*/
    long* base = new long [comprimentos[vocab->tamanho-1]]();
    long* offset = new long [comprimentos[vocab->tamanho-1]]();
    monta_off_base(comprimentos,vocab->tamanho,base,offset);

    /*Monta o dicionario com as palavras e seus códigos*/
    dicionario* dic = new dicionario[vocab->tamanho];
    monta_dicionario(vocab,base,offset,comprimentos,dic);

    /*Faz a escrita*/
    cout<<"Escrevendo arquivo de saida..."<<endl;
    escrever_descompactado(arquivo_de_entrada,arquivo_de_saida,base,offset,comprimentos,vocab,dic,total_p);
    arquivo_de_saida.flush(); 
    
        delete [] base;
        delete [] offset;
        delete [] vocab->vetor;
        delete vocab;
        delete [] dic;

}