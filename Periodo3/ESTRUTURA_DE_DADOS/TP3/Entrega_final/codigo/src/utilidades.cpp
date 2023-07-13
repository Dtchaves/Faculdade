#include <../include/utilidades.hpp>

int soma_letras(const string texto) {
    int soma = 0;
    int i = 0;
    char c = texto[i];
    /*Soma bem simples char a char*/
    while(texto[i] != '\0') {
        soma += static_cast<int>(c); 
        i++;
    }
    return soma;
}

void particao(int esq, int dir,int *i, int *j, palavra_ocorrencia *vetor){

    palavra_ocorrencia aux;
    palavra_ocorrencia  pivo = vetor[dir - 1];
    *i = esq; 
    *j = dir;
    do
    {
        /*Ordenaçaõ na ordem decrescente*/
        while (pivo.ocorrencia < vetor[*i].ocorrencia) (*i)++;
        while (pivo.ocorrencia > vetor[*j].ocorrencia) (*j)--;
        if (*i <= *j)
        {
            aux = vetor[*i];
            vetor[*i] = vetor[*j]; 
            vetor[*j] = aux;
            (*i)++; 
            (*j)--;
        }
    } while (*i <= *j);
}

void ordena(int esq, int dir, palavra_ocorrencia* vetor){
    int i;
    int j;
    int meio = (esq+dir)/2;
    palavra_ocorrencia aux;
    /*Melhoria do quick, mediana dos 3*/
        if(((vetor[esq].ocorrencia > vetor[dir].ocorrencia ) && (vetor[esq].ocorrencia < vetor[meio].ocorrencia)) || ((vetor[esq].ocorrencia < vetor[dir].ocorrencia ) && (vetor[esq].ocorrencia > vetor[meio].ocorrencia))){
            aux = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = aux;
        }
        else {
            if(((vetor[meio].ocorrencia > vetor[dir].ocorrencia ) && (vetor[esq].ocorrencia > vetor[meio].ocorrencia)) || ((vetor[meio].ocorrencia < vetor[dir].ocorrencia ) && (vetor[esq].ocorrencia < vetor[meio].ocorrencia))){
                aux = vetor[meio];
                vetor[meio] = vetor[dir];
                vetor[dir] = aux;
            }
        }


    particao(esq, dir, &i, &j, vetor);  
    if (esq < j) ordena(esq, j, vetor);
    if (i < dir) ordena(i, dir, vetor);
}

void quicksort(palavra_ocorrencia* vetor, long tamanho){
    ordena(0,(tamanho-1),vetor);
}