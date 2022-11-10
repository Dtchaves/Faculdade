#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 8
#define MIN -1

/*
funcao para fazer o backtracking de forma recursiva sendo:
-> atual = ponto atual que o cavalo está
-> tabuleiro = o tabuleiro em si 
-> casa_atual= qual o numero de casas que ja foram visitas, em outras palavras é qual a casa que a funcao esta atualmetne
*/
int best_path(int linha_atual,int coluna_atual, int tabuleiro [][MAX], int casa_atual, int* casas_visitadas,int* recursividade);

/*
funcao para preencher a matriz com 0s
*/
void fill_matriz(int tabuleiro [][MAX]);

/*
funcao para printar a matriz 
*/
void print_matriz(int tabuleiro [][MAX]);

int verificar(int linha, int coluna);

int main()
{
    srand(time(NULL));
    int aux,confirmador;
    int tabuleiro[MAX][MAX];
        /*tabuleiro = (int**) malloc (MAX*sizeof(int*));
            for(aux = 0; aux < MAX; aux++)
            {
                *tabuleiro = (int*) malloc (MAX*sizeof(int));
            }*/
    int linha_inicial,coluna_inicial;
    int casas_visitadas,retrocedidas;

//1. Apresente um possível passeio do cavalo começando na posição mais acima e mais a esquerda do tabuleiro,i.e., posição (1, 1) .    linha_inicial = rand()%8;
    linha_inicial = 0; // em c a primeira casa é 0 e não 1
    coluna_inicial = 0;
    fill_matriz(tabuleiro);
    aux = 1;
    casas_visitadas = 0;
    retrocedidas = 0;
    confirmador = best_path(linha_inicial,coluna_inicial,tabuleiro, aux,&casas_visitadas,&retrocedidas);
    printf("Passeio 1 para (%i,%i)\n\n",linha_inicial,coluna_inicial);
    print_matriz(tabuleiro);
    if (confirmador) printf("\nTabuleiro completo!\n");
        else printf("\nTabuleiro incompleto!\n");
    printf("\nQuantidade de casas visitadas = %d\nQuantidade de casas que tiveram que ser retrocedidas = %d\n",casas_visitadas,retrocedidas);
    printf("\n\n\n");
//2. Apresente um possível passeio do cavalo começando em uma posição aleatória do tabuleiro diferente da posição (1, 1) .
   do
    {
        linha_inicial = rand()%MAX;
        coluna_inicial = rand()%MAX; 

    } while (linha_inicial && coluna_inicial);
    
    fill_matriz(tabuleiro);
    aux = 0;
    casas_visitadas = 0;
    retrocedidas = 0;
    confirmador = best_path(linha_inicial,coluna_inicial,tabuleiro, aux,&casas_visitadas,&retrocedidas);
    printf("Passeio 2 para (%i,%i)\n\n",linha_inicial,coluna_inicial);
    print_matriz(tabuleiro);
    if (confirmador) printf("\nTabuleiro completo!\n");
        else printf("\nTabuleiro incompleto!\n");
    printf("\nQuantidade de casas visitadas = %d\nQuantidade de casas que tiveram que ser retrocedidas = %d\n",casas_visitadas,retrocedidas);


    return 0;
}

int verificar(int linha, int coluna)
{
    if(coluna<MAX && linha<MAX && coluna>-1 && linha >-1)
    {
        return 0;
    }
        else 
        {
            return 1;
        }

}

int best_path(int linha_atual,int coluna_atual, int tabuleiro [][MAX], int casa_atual, int* casas_visitadas,int* retrocedidas)
{
    if( verificar(linha_atual,coluna_atual))
    {
        return 0;
    }

    *casas_visitadas= *casas_visitadas + 1;
    tabuleiro[linha_atual][coluna_atual] = casa_atual;


    if (casa_atual == MAX*MAX)
    {
        return 1;
    }

 //m7 do tp
    if(tabuleiro[linha_atual + 2][coluna_atual+ 1] == 0)
    { 
        if (best_path(linha_atual + 2,coluna_atual + 1, tabuleiro,casa_atual+1,casas_visitadas,retrocedidas))
        {
             return 1;
        }
        *retrocedidas=*retrocedidas + 1;
    }

//m6 do tp
    if(tabuleiro[linha_atual + 2][coluna_atual - 1] == 0)
    {         
        if (best_path(linha_atual + 2,coluna_atual -1 , tabuleiro,casa_atual+1,casas_visitadas,retrocedidas))
        {
                return 1;
        }
        *retrocedidas=*retrocedidas + 1;
    }       
        


//m8 do tp
    if(tabuleiro[linha_atual + 1][coluna_atual+ 2] == 0)
    { 
        if (best_path(linha_atual + 1,coluna_atual + 2, tabuleiro,casa_atual+1,casas_visitadas,retrocedidas))
        {
            return 1;
        }
        *retrocedidas=*retrocedidas + 1;
                      
    }

//m5 do tp
    if(tabuleiro[linha_atual + 1][coluna_atual - 2] == 0)
    { 
        if (best_path(linha_atual + 1,coluna_atual -2 , tabuleiro,casa_atual+1,casas_visitadas,retrocedidas))
        {
            return 1;
        }
        *retrocedidas=*retrocedidas + 1;
    }

//m2 do tp
    if(tabuleiro[linha_atual -2 ][coluna_atual+ 1] == 0)
    { 
        if (best_path(linha_atual - 2,coluna_atual + 1, tabuleiro,casa_atual+1,casas_visitadas,retrocedidas))
        {
            return 1;
        }
        *retrocedidas=*retrocedidas + 1;

    }

//m3 do tp   
    if(tabuleiro[linha_atual - 2][coluna_atual - 1] == 0)
    { 
        if(best_path(linha_atual - 2,coluna_atual -1 , tabuleiro,casa_atual+1,casas_visitadas,retrocedidas))
        {
            return 1;
        }
        *retrocedidas=*retrocedidas + 1;
    }
        


//m1 do tp
    if(tabuleiro[linha_atual - 1][coluna_atual+ 2] == 0)
    { 
        if(best_path(linha_atual - 1,coluna_atual + 2, tabuleiro,casa_atual+1,casas_visitadas,retrocedidas))
        {
            return 1;
        }
        *retrocedidas=*retrocedidas + 1;
    }
        

//m4 do tp
    if(tabuleiro[linha_atual - 1][coluna_atual - 2] == 0)
    { 
        if(best_path(linha_atual - 1,coluna_atual -2 , tabuleiro,casa_atual+1,casas_visitadas,retrocedidas))
        {
            return 1;
        }
        *retrocedidas=*retrocedidas + 1;
    }

    
    tabuleiro[linha_atual][coluna_atual] = 0;
    return 0;

}

void fill_matriz(int tabuleiro [][MAX])
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

void print_matriz(int tabuleiro [][MAX])
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