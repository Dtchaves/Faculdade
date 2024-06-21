#include <bits/stdc++.h>
#include "jogo_da_vida.h"

using namespace std;

  // Cria um jogo cujo torus tem l linhas e c colunas.
  // Todas as células são inicializadas como mortas.
  JogoDaVida::JogoDaVida(int l, int c)
  {
    vivas_.resize(l,vector<bool> (c,false));
  }

int JogoDaVida::linhas() 
{
    return vivas_.size();
}

int JogoDaVida::colunas() 
{
    return vivas_[0].size();
}

 bool JogoDaVida::viva(int i, int j)
 {
    return vivas_[i][j];
 }

void JogoDaVida::Matar(int i, int j)
{
    vivas_[i][j] = false;
}

void JogoDaVida::Reviver(int i, int j)
{
    if(i < 0 || i >= linhas() || j < 0 || j >= colunas()) throw ExcecaoCelulaInvalida {i,j};

    vivas_[i][j] = true;
}

int JogoDaVida::NumeroDeVizinhasVivas(int x, int y)
{
    int i,contador = 0;
    for(i = 0;i<8;i++)
    {
        int linha = x + get<0>(operacoes[i]);
        int coluna = y + get<1>(operacoes[i]);
        if(linha == -1) linha = linhas() - 1;
        if(coluna == -1) coluna = colunas() - 1;
        if(linha  == linhas()) linha = 0;
        if(coluna == colunas()) coluna = 0;

        if(vivas_[linha][coluna]) contador++;
    }
    return contador;
}

void JogoDaVida::ExecutarProximaIteracao()
{
    int i,j;
    vector<vector<bool>>* ajuda = new vector<vector<bool>>;

    *ajuda = vivas_;
    for(i=0;i<linhas();i++)
    {
        for(j=0;j<colunas();j++)
        {
            int aux = NumeroDeVizinhasVivas(i,j);
            if(vivas_[i][j]) 
            {
                if((aux== 1) || (aux == 0) || (aux > 3))
                {
                    (*ajuda)[i][j] = false;
                }
            }

            else 
            {
                if(aux == 3) 
                {
                    (*ajuda)[i][j] = true;
                }
            }
        }
    }
    vivas_= *ajuda;
    delete ajuda;
}