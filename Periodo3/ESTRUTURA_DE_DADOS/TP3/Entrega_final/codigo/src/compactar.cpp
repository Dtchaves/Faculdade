#include <../include/compactar.hpp>

unsigned char bit_buffer;

void escreve_bit (int bit, ofstream& arquivo_de_saida)
{
    static int contador_bit = 0;

    if (bit){
        bit_buffer |= (1<<contador_bit);
    }

    contador_bit++;
    /*Toda vez que tivermos 8 bits, ou um byte, escrevemos no arquivo de saída*/
    if (contador_bit == 8)
    {
        arquivo_de_saida.write(reinterpret_cast<const char*>(&bit_buffer), sizeof(bit_buffer));
        contador_bit = 0;
        bit_buffer = 0; 
    }
}

vocabulario* ocorrencia_com_hash(ifstream& arquivo_de_entrada){
    vocabulario* retorno = new vocabulario;
    string palavra,pont;
    long tamanho = 0;
    /*Cria o hash*/
    elemento_hash_leitura* hash = new elemento_hash_leitura[MAX_HASH];


    while(arquivo_de_entrada>>palavra){

        int vaga_hash = soma_letras(palavra)%MAX_HASH;
        /*Caso a palavra exista o procura_incrementa ja incrementa normalmente*/
        if(!hash[vaga_hash].procura_incrementa(palavra)){
            /*Caso não exista a palavra é adicionada*/
            hash[vaga_hash].insere(palavra);
            tamanho++;
        }
    }

    retorno->tamanho = tamanho;
    retorno->vetor = new palavra_ocorrencia[tamanho];
    int aux = 0;

    /*Passa as palavras e ocorrencias da entrada para um vetor de vocabulário*/
    for(int i = 0; i < MAX_HASH; i++){
        while(!hash[i].vazio()){
            retorno->vetor[aux] = hash[i].remove();
            aux++;
        }
    }

    delete [] hash;
    return retorno;
}

void escrever_chave(ifstream& arquivo_de_entrada,ofstream& arquivo_de_saida,vocabulario* vocab){
    /*Escreve a quantidade de palavras distintas*/
    arquivo_de_saida<<vocab->tamanho<<" ";
    /*Escreve as palavras e sua frequência em ordem decrescente(ordenado por frequência)*/
    for(int i = 0; i < vocab->tamanho ;i++){
       arquivo_de_saida<<vocab->vetor[i].palavra<<" "<<vocab->vetor[i].ocorrencia<<" ";
    }
    arquivo_de_saida<<endl;
}


void escrever_compactado(ifstream& arquivo_de_entrada,ofstream& arquivo_de_saida,int tamanho, dicionario* dic ){

    string palavra;
    int i;

    /*Hash para poder fazer as buscas pelo dicionario de forma mais rápida*/
    elemento_hash_escrita* hash = new elemento_hash_escrita[MAX_HASH];
    for(i = 0; i < tamanho;i++){
        /*A função de hash vai ser definida em função das palavras, tendo em vista que queremos achar os códigos correspondentes*/
        int vaga_hash = soma_letras(dic[i].palavra)%MAX_HASH;
        hash[vaga_hash].insere(dic[i]);
    }

    /*Escreve as palavras compactadas*/
    dicionario prox;
    while(arquivo_de_entrada>>palavra){
        int vaga_hash = soma_letras(palavra)%MAX_HASH;
        prox = hash[vaga_hash].procura_palavra(palavra);

        /*Acha os bits e vai escrevendo*/
        for (int j = prox.num_bits - 1; j >= 0; j--) {
            int bit = (prox.codigo >> j) & 1;
            escreve_bit(bit,arquivo_de_saida);
        }
    }
    /*Escreve o que sobrou no buffer, sendo que qualquer lixo escrito é tratado na leitura*/
    arquivo_de_saida.write(reinterpret_cast<const char*>(&bit_buffer), sizeof(bit_buffer));

    delete [] hash;
}

void compactar(ifstream& arquivo_de_entrada,ofstream& arquivo_de_saida){

    int i;

    /*Pega o vocabulário do arquivo de entrada e o ordena de forma decrescente usando o quicksort*/
    vocabulario* vocab = ocorrencia_com_hash(arquivo_de_entrada);
    arquivo_de_entrada.clear();
    arquivo_de_entrada.seekg(0,ios::beg);
    quicksort(vocab->vetor,vocab->tamanho);

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
    escrever_chave(arquivo_de_entrada,arquivo_de_saida,vocab);
    cout<<"Escrevendo arquivo de saida..."<<endl;
    escrever_compactado(arquivo_de_entrada,arquivo_de_saida,vocab->tamanho,dic);
    arquivo_de_saida.flush(); 
    
    delete [] base;
    delete [] offset;
    delete [] vocab->vetor;
    delete vocab;
    delete [] dic;

}