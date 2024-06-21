#include <../include/huffman.hpp>

void primeira_fase(long* vetor, long tamanho){
    long raiz = tamanho;
    long folha = tamanho;

    for(int prox = tamanho; prox >= 2;prox--){
        /*Procura posição*/
        if((folha == 0)||((raiz > prox)&&(vetor[raiz-1] <= vetor[folha-1]))){
            /*Temos um nó interno*/
            vetor[prox-1] = vetor[raiz-1] ;
            vetor[raiz-1] = prox;
            raiz--;
        }
        else{
            /*Temos um nó folha*/
            vetor[prox-1] = vetor[folha-1];
            folha--;
        }
        /*Atualiza frequências*/
        if((folha == 0)||((raiz > prox)&&(vetor[raiz-1] <= vetor[folha-1]))){
            /*Temos um nó interno*/
            vetor[prox-1] = vetor[prox-1] + vetor[raiz-1];
            vetor[raiz-1] = prox;
            raiz--;
        }
        else{
            /*Temos um nó folha*/
            vetor[prox-1] = vetor[prox-1] + vetor[folha-1];
            folha--;
        }
    }

}

void segunda_fase(long* vetor, long tamanho){
    vetor[1] = 0;
    /*Vamos passando pelas vagas do vetor montando as profundidades baseado nos índices
    dos pais*/
    for(int prox = 3; prox <= tamanho;prox++){
        vetor[prox-1] = vetor[vetor[prox-1]-1] + 1;
    }
}

void terceira_fase(long* vetor, long tamanho){
    long disp = 1;
    long u = 0;
    long h = 0;
    long raiz = 2;
    long prox = 1;

    /*Utilizando as profundidades dos nós internos podemos ir atualizando o vetor
    para achar as alturas das folhas, que seriam as palavras*/
    while(disp>0){
        while((raiz <= tamanho)&&(vetor[raiz-1] == h)){
            u++;
            raiz++;
        }
        while(disp>u){
            vetor[prox-1] = h;
            prox++;
            disp--;
        }
        disp = 2*u;
        h++;
        u = 0;
    } 
}

void calcula_comprimento(long* vetor, long tamanho){
    primeira_fase(vetor,tamanho);
    segunda_fase(vetor,tamanho);
    terceira_fase(vetor,tamanho);
}

void monta_off_base(long* vetor,long tamanho,long* base, long* offset){

    long freqa = 0;
    long freqn = 0;
    int aux = 1;

    /*O vetor é o índice no vocabulário da primeira palavra com o comprimento c e o base 
    é definido recursivamente como:
    se c == 0 -> base[c] = 0
    c.c. -> base[c] = 2 *(base[c-1]+ numero de códigos com o comprimento c-1)
    foram feitos ajustes à esses vetores a fim de minimizar a quantidade de nós internos 
    na árvore de huffman teoricamente criada*/
    for(int c = 1; c <= vetor[tamanho-1]; c++){
        if(vetor[aux-1] == c){
            offset[c-1] = aux;
            while(vetor[aux-1] == c){
                freqn++;
                aux++;
            }
        }
        else{
            if(aux != 1) aux--;
            offset[c-1] = aux;
            if(aux != 1) aux++;
        }

        if(c == 1){
            base[c-1] = 0;
        }
        else{
            base[c-1] = 2*(base[c-2]+freqa);
        }
        freqa = freqn;
        freqn = 0;
    }
}

long long int codifica(long* base, long* offset,int vaga,long maxcode){
    int c = 1;
    /*Utiliza um algoritmo simples e os vetores base e offset para codificar uma palavra*/
    while((vaga >= offset[c])&&(c+1<=maxcode)){
        c++;
    }
    return vaga - offset[c-1] + base[c-1];
}

void monta_dicionario(vocabulario* vocab,long* base, long* offset,long* comprimentos, dicionario* dic){

    /*Utiliza da função codifica para ir codificando individualmente cada palavra do vocabulario, ou seja,
    cada palavra distinta do texto*/
    for(int i = 0;i<vocab->tamanho;i++){
        dic[i].palavra = vocab->vetor[i].palavra;
        dic[i].codigo = codifica(base,offset,(i+1),comprimentos[vocab->tamanho-1]);
        dic[i].num_bits = comprimentos[i];
    }
}