#include <stdio.h>
#include <stdlib.h>
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

int caminho(int linha_atual,int coluna_atual,int casa_atual, int* casas_visitadas,int* recursividade);

void ordenar_por_rank(ponto ordenando[],int tamanho); 
void rank_da_funcao(ponto *analisando);
int averiguar(int linha, int coluna);

void preencher_matriz();
void print_matriz();


void passeio(int x, int y)  
{
    preencher_matriz();

    int linha_entrada,coluna_entrada;
        linha_entrada = x - 1 ;
        coluna_entrada = y - 1;
    printf("%d %d ",linha_entrada,coluna_entrada);
    int casa,casas_visitadas,casas_retrocedidas;
        casa = 1;
        casas_visitadas = 0;
        casas_retrocedidas = 0;

    FILE *saida;
        saida = fopen("saida.txt","a");

    caminho(linha_entrada,coluna_entrada,casa,&casas_visitadas,&casas_retrocedidas);

    print_matriz(saida);
    fprintf(saida, "%d %d\n",casas_visitadas,casas_retrocedidas);
    fclose(saida);
}

int caminho(int linha_atual,int coluna_atual,int casa_atual, int* casas_visitadas,int* retrocedidas)
{
    ponto possiveis_mov[MAX];
    int aux = 0,i,j;

    *casas_visitadas = *casas_visitadas + 1;
    tabuleiro[linha_atual][coluna_atual] = casa_atual;

    if (casa_atual == MAX*MAX)
    {
        return 1;
    }

    for(i = 0; i<8;i++)
    {
        int l = linha_atual + movimentos[i].x;
        int c = coluna_atual + movimentos[i].y;

        if(averiguar(l,c))
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
        if(caminho(possiveis_mov[j].linha, possiveis_mov[j].coluna, casa_atual + 1, casas_visitadas, retrocedidas))
        {
            return 1;
        }
        *retrocedidas = *retrocedidas + 1;
    }


    tabuleiro[linha_atual][coluna_atual] = 0;
    return 0;

}

int averiguar(int linha, int coluna)
{
    return coluna<MAX && linha<MAX && coluna>-1 && linha >-1;
}

void rank_da_funcao(ponto *analisando)
{
    int i;
    analisando->rank = 0;

    for(i = 0; i<8;i++)
    {
        int l = analisando->linha + movimentos[i].x;
        int c = analisando->coluna + movimentos[i].y;

        if(averiguar(l,c))
        {
            if(tabuleiro[l][c] == 0)
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

void print_matriz(FILE* saida)
{
    int i,j;

    for(i = 0; i < MAX; i++)
    {
        for(j = 0; j < MAX; j++)
        {
        fprintf(saida,"%d ",tabuleiro[i][j]);
        }
        fprintf(saida,"\n");
    }
}
