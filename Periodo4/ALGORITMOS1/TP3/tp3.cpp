#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

#define inf 0x3f3f3f3f3f3f3f3f

using namespace std;

struct Secao{
    long long int bonificacao;
    long long int tempo;
};

struct Manobra{
    long long int pontuacao;
    long long int tempo;
};

vector<vector<Manobra>> create_binary_mask(int N_manobras,vector<Manobra>& manobras, int Possibilidades){

    vector<vector<Manobra>> Binary_mask(Possibilidades, vector<Manobra>(Possibilidades));


    int i,j;
    long long int point = 0;
    long long int sum_point = 0;
    long long int sum_time = 0;
    int safe = 0;
    int n_bit;

    int bit;

    /*Usamos todos as possiveis combinaçoes de manobras para a secao anterior*/
    for(i = 0;i<Possibilidades;i++){
        vector<int> Anterior;
        safe = i;
        /*Criar um vetor com as manobras da secao anterior*/
        for(n_bit = 0; n_bit < N_manobras;n_bit++){
            Anterior.push_back(safe & 1);
            safe = safe >> 1;
        }
        /*Usamos todos as possiveis combinaçoes de manobras para a secao atual*/
        for(j = 0;j<Possibilidades;j++){
            safe = j;
            point = 0;
            int tamanho = 0;
            sum_point = 0;
            sum_time = 0;

            /*Passamos por todas as manobras calculando a pontuação*/
            for(n_bit = 0; n_bit < N_manobras;n_bit++){
                bit = (safe & 1);
                safe = safe >> 1;
                if(bit){
                    point =manobras[n_bit].pontuacao;
                    tamanho++;

                    if(Anterior[n_bit]){
                        point = point/2;
                    }
                    sum_point += point;
                    sum_time += manobras[n_bit].tempo;
                }
            }

            Binary_mask[i][j].pontuacao = sum_point*tamanho;
            Binary_mask[i][j].tempo = sum_time;
        }
    }
    return Binary_mask;
}

struct F{
    long long int pontuacao;
    int manobra_anterior;
};



F Max_Score(int secao_atual,int manobra_da_secao,vector<vector<Manobra>>& Binary_mask,vector<vector<F>>& Max_secao_dado_manobra, vector<vector<bool>>& Visitados,int Possibilidades,vector<Secao>& pista){
    
    if(!Visitados[secao_atual][manobra_da_secao]){

        Visitados[secao_atual][manobra_da_secao] = true;

        if(secao_atual == 0){
            if(Binary_mask[0][manobra_da_secao].tempo > pista[secao_atual].tempo){
                 Max_secao_dado_manobra[secao_atual][manobra_da_secao].pontuacao =  -inf;
            }
            else{
                Max_secao_dado_manobra[secao_atual][manobra_da_secao].pontuacao = pista[secao_atual].bonificacao * Binary_mask[0][manobra_da_secao].pontuacao;
            }

            Max_secao_dado_manobra[secao_atual][manobra_da_secao].manobra_anterior = 0;
        }
        else{
            int Ultima_manobra = 0;
            long long int Maior_pont = -inf;
            long long int valor;
            for(int i=0;i<Possibilidades;i++){
                if(Binary_mask[i][manobra_da_secao].tempo > pista[secao_atual].tempo){
                    valor =  -inf;
                    continue;
                }
                else{
                    valor = Max_Score(secao_atual - 1, i, Binary_mask, Max_secao_dado_manobra, Visitados, Possibilidades, pista).pontuacao + pista[secao_atual].bonificacao * Binary_mask[i][manobra_da_secao].pontuacao;
                }
                if(valor > Maior_pont){
                    Maior_pont = valor;
                    Ultima_manobra = i;
                }
            }
            Max_secao_dado_manobra[secao_atual][manobra_da_secao].pontuacao = Maior_pont;
            Max_secao_dado_manobra[secao_atual][manobra_da_secao].manobra_anterior =  Ultima_manobra;
        }
    }



    return Max_secao_dado_manobra[secao_atual][manobra_da_secao];
}

struct printar{
    int tamanho;
    vector<int> manobras;
};

int main(){

    int i,j;
    int n_bit,bit;

    int N_secoes;
    int N_manobras;
    cin>>N_secoes>>N_manobras;

    vector<Secao> pista;
    Secao S_aux;

    for(i = 0; i<N_secoes;i++){
        cin>>S_aux.bonificacao>>S_aux.tempo;
        pista.push_back(S_aux);
    }
    S_aux.bonificacao = 1;
    S_aux.tempo = numeric_limits<long long int>::max();
    pista.push_back(S_aux);

    vector<Manobra> manobras;
    Manobra M_aux;

    for(i = 0; i<N_manobras;i++){
        cin>>M_aux.pontuacao>>M_aux.tempo;
        manobras.push_back(M_aux);
    }

    int Possibilidades = 2<<N_manobras - 1;

    vector<vector<Manobra>> Binary_mask =  create_binary_mask(N_manobras, manobras,Possibilidades);


    vector<vector<F>> Max_secao_dado_manobra(N_secoes+1, vector<F>(Possibilidades));

    vector<vector<bool>> Visitados(N_secoes+1, vector<bool>(Possibilidades,false));

    F resultado = Max_Score(N_secoes,0,Binary_mask,Max_secao_dado_manobra,Visitados,Possibilidades,pista);

    vector<printar> saida(N_secoes);
    cout<<resultado.pontuacao<<endl;

    int safe = resultado.manobra_anterior;
    int aux;
    for(i = N_secoes-1; i >= 0 ;i--){
        aux = safe;
        vector<int> Manobras_feitas;
        int tamanho = 0;
        for(n_bit = 0; n_bit < N_manobras;n_bit++){
            bit = (safe & 1);
            safe = safe >> 1;
            if(bit){
                Manobras_feitas.push_back(n_bit+1);
                tamanho++;
            }
        }
        saida[i].tamanho = tamanho;
        for(j = 0;j<tamanho;j++){
            saida[i].manobras.push_back(Manobras_feitas[j]);
        }
        safe = Max_secao_dado_manobra[i][aux].manobra_anterior;
    }

    for(i = 0; i < N_secoes ;i++){
        cout<<saida[i].tamanho;
        for(j = 0;j<saida[i].tamanho;j++){
            cout<<" "<<saida[i].manobras[j];
        }
        cout<<endl;
    }


    return 0;
}