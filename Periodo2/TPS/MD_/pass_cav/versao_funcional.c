#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 8
#define MIN -1

int tabuleiro[MAX][MAX];

typedef struct movimentos_possiveis
{
    int x,y;

}cavalo;

cavalo movimentos[8] = {{1,2},{-1,-2},{-1,2},{1,-2},{2,1},{-2,-1},{-2,1},{2,-1}};

typedef struct ponto_com_rank
{
    int linha;
    int coluna;
    int rank;

}ponto;

void ordenar_por_rank(ponto ordenando[],int tamanho); // mudar para merge assim q codigo funcionar

void rank_da_funcao(ponto *analisando);

int verificar(int linha, int coluna);

int caminho(int linha_atual,int coluna_atual,int casa_atual, int* casas_visitadas,int* recursividade);

void preencher_matriz();

void print_matriz();


int main()
{

    srand(time(NULL));
    int aux,confirmador;
    int linha_inicial,coluna_inicial;
    int casas_visitadas,retrocedidas;

    linha_inicial = 0; 
    coluna_inicial = 7;
    preencher_matriz();
    aux = 1;
    casas_visitadas = 0;
    retrocedidas = 0;
    confirmador = caminho(linha_inicial,coluna_inicial,aux,&casas_visitadas,&retrocedidas);
    printf("Passeio 1 para (%i,%i)\n\n",linha_inicial,coluna_inicial);
    print_matriz();
    if (confirmador) printf("\nTabuleiro completo!\n");
        else printf("\nTabuleiro incompleto!\n");
    printf("\nQuantidade de casas visitadas = %d\nQuantidade de casas que tiveram que ser retrocedidas = %d\n",casas_visitadas,retrocedidas);
    printf("\n\n\n");
//2. Apresente um possível passeio do cavalo começando em uma posição aleatória do tabuleiro diferente da posição (1, 1) .
   do
    {
        linha_inicial = rand()%MAX;
        coluna_inicial = rand()%MAX;

    } while (!(linha_inicial && coluna_inicial));

    preencher_matriz();
    aux = 1;
    casas_visitadas = 0;
    retrocedidas = 0;
    confirmador = caminho(linha_inicial,coluna_inicial, aux,&casas_visitadas,&retrocedidas);
    printf("Passeio 2 para (%i,%i)\n\n",linha_inicial,coluna_inicial);
    print_matriz();
    if (confirmador) printf("\nTabuleiro completo!\n");
        else printf("\nTabuleiro incompleto!\n");
    printf("\nQuantidade de casas visitadas = %d\nQuantidade de casas que tiveram que ser retrocedidas = %d\n",casas_visitadas,retrocedidas);


    return 0;
}

int verificar(int linha, int coluna)
{
    return coluna<MAX && linha<MAX && coluna>-1 && linha >-1;
}

void rank_da_funcao(ponto *analisando)
{
    int i;
    analisando->rank = 0;

    for(i = 0; i<8;i++)
    {
        if(verificar(analisando->linha + movimentos[i].x,analisando->coluna + movimentos[i].y))
        {
            if(tabuleiro[analisando->linha + movimentos[i].x][analisando->coluna + movimentos[i].y] == 0)
            {
                analisando->rank++;
            }
        }
    }

}

void ordenar_por_rank(ponto ordenando[],int tamanho) // mudar para merge assim q codigo funcionar
{
        int i,j;
        ponto troca;

        for (i = 0; i < tamanho; i++)
        {
            for (j = i+1;j < tamanho; j++)
            {
                if ((ordenando+i)->rank > ordenando[j].rank  )
                {
                    troca = ordenando[i];
                    ordenando[i] = ordenando[j];
                    ordenando[j] = troca;

                }
            }
        }

}

int caminho(int linha_atual,int coluna_atual,int casa_atual, int* casas_visitadas,int* retrocedidas)
{
    ponto possiveis_mov[MAX];
    int aux = 0,i,j;
    //printf("%d \n",*retrocedidas);

    *casas_visitadas= *casas_visitadas + 1;
    tabuleiro[linha_atual][coluna_atual] = casa_atual;


    if (casa_atual == MAX*MAX)
    {
        return 1;
    }


    for(i = 0; i<8;i++)
    {
        int l = linha_atual + movimentos[i].x;
        int c = coluna_atual + movimentos[i].y;

        if(verificar(l,c))
        {
            if(tabuleiro[l][c] == 0)
            {
                possiveis_mov[aux].linha = l;
                possiveis_mov[aux].coluna = c;

                rank_da_funcao(&possiveis_mov[aux]);
                aux++;
            }
        }
    }

    ordenar_por_rank(possiveis_mov,aux);

    for(j = 0; j<aux;j++)
    {

        if(caminho(possiveis_mov[j].linha,possiveis_mov[j].coluna,casa_atual + 1,casas_visitadas,retrocedidas))
        {
            return 1;
        }
        *retrocedidas = *retrocedidas + 1;
    }


    tabuleiro[linha_atual][coluna_atual] = 0;
    return 0;

}

void preencher_matriz()
{
    int i,j;

    for(i = 0; i < MAX; i++)
    {
        for(j = 0; j < MAX; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }

}

void print_matriz()
{
    int i,j;

    for(i = 0; i < MAX; i++)
    {
        for(j = 0; j < MAX; j++)
        {
            if(tabuleiro[i][j] >= 10)
            {
                printf("%d ",tabuleiro[i][j]);
            }
                else
                {
                    printf(" %d ",tabuleiro[i][j]);
                }
        }
        putchar('\n');
    }
}
