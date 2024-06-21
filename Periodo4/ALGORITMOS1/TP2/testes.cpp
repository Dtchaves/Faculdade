#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include<climits>

using namespace std;


struct Aresta {
    int origem;
    int destino;
    long long int ano;
    long long int tempo;
    long long int custo;
};

struct Vertice{
    vector<Aresta> arestas;
};


/*QUESTÃO 1*/
struct Vertice_Tempo{
    int vertice;
    long long int tempo_atual;
};  

struct Comparador_Dijkstra {
    bool operator() (Vertice_Tempo a, Vertice_Tempo b) const {
        return a.tempo_atual > b.tempo_atual; 
    }
};

struct Retorno_Dijkstra{
    vector<long long int> tempos;
    long long int ano_min;
};

Retorno_Dijkstra Dijkstra_Adaptado(Vertice* Grafo, int& num_vertices){
    long long int infinito = INT_MAX;
    vector<long long int> tempos(num_vertices, infinito);
    vector<long long int> anos(num_vertices, 0);
    tempos[0] = 0;
    
    priority_queue<Vertice_Tempo,vector<Vertice_Tempo>,Comparador_Dijkstra> Q;
    Q.push({0,tempos[0]});

    while(!Q.empty()){
        int vertice_v =  (Q.top()).vertice;
        Q.pop();
        for(int i =0; i < Grafo[vertice_v].arestas.size();i++){
            int vertice_u = (Grafo[vertice_v].arestas[i].destino-1);
            if(tempos[vertice_u] > (tempos[vertice_v] + Grafo[vertice_v].arestas[i].tempo)){
                tempos[vertice_u] = tempos[vertice_v] + Grafo[vertice_v].arestas[i].tempo;
                if(anos[vertice_v] > Grafo[vertice_v].arestas[i].ano){
                    anos[vertice_u] = anos[vertice_v];
                }
                else {
                    anos[vertice_u] = Grafo[vertice_v].arestas[i].ano;
                }
                Q.push({vertice_u,tempos[vertice_u]});
            }
        }
    }
    Retorno_Dijkstra ret;
    ret.tempos = tempos;
    auto ano_min = max_element(anos.begin(), anos.end());
    ret.ano_min = *ano_min;
    return ret;
}

/*QUESTÕES 2 e 3*/
struct Componentes{
    int componente;
    int tamanho;
};

vector<Componentes> Montarset(int& num_vertices){
    vector<Componentes> ret(num_vertices);
    for(int i =0; i<num_vertices;i++){
        ret[i].componente = i;
        ret[i].tamanho = 1;
    }
    return ret;
}

int AcharComp(int v, vector<Componentes>& comp){
    if(v != comp[v].componente){
        comp[v].componente = AcharComp(comp[v].componente,comp);
    }
    return comp[v].componente;
}

void Uniao(int a,int b,vector<Componentes>& comp){
    a = AcharComp(a,comp);
    b = AcharComp(b,comp);

    if(comp[a].tamanho < comp[b].tamanho){
        comp[a].componente = b;
        comp[b].tamanho = comp[b].tamanho + comp[a].tamanho;
    }
    else{
        comp[b].componente = a;
        comp[a].tamanho = comp[a].tamanho + comp[b].tamanho;
    }
    return;
}

bool Comparador_Kruskal_Menor_Ano(Aresta a, Aresta b) {
    return a.ano < b.ano;
}

long long int Kruskal_Menor_Ano(int& num_vertices, vector<Aresta> Arestas_Grafo,int num_arestas){
    vector<Componentes>  comp = Montarset(num_vertices);
    long long int menor_ano = 0;
    sort(Arestas_Grafo.begin(),Arestas_Grafo.end(),Comparador_Kruskal_Menor_Ano);
    Aresta uv;
    for(int i = 0; i<num_arestas;i++){
        uv = Arestas_Grafo[i];
        if(AcharComp(uv.origem-1,comp) != AcharComp(uv.destino-1,comp)){
            if(menor_ano < uv.ano){
                menor_ano = uv.ano;
            }
            Uniao((uv.origem-1),(uv.destino-1),comp);
        }
    }
    return menor_ano;
}

bool Comparador_Kruskal_Menor_Custo(Aresta a, Aresta b) {
    return a.custo < b.custo;
}

long long int Kruskal_Menor_Custo(int& num_vertices, vector<Aresta> Arestas_Grafo,int num_arestas){
    vector<Componentes>  comp = Montarset(num_vertices);
    long long int menor_custo = 0;
    sort(Arestas_Grafo.begin(),Arestas_Grafo.end(),Comparador_Kruskal_Menor_Custo);
    Aresta uv;
    for(int i = 0; i<num_arestas;i++){
        uv = Arestas_Grafo[i];
        if(AcharComp(uv.origem-1,comp) != AcharComp(uv.destino-1,comp)){
            menor_custo += uv.custo;
            Uniao((uv.origem-1),(uv.destino-1),comp);
        }
    }
    return menor_custo;
}



int main(){

    int num_vertices;
    int num_arestas;
        cin>>num_vertices>>num_arestas;
    
    num_arestas = num_arestas*2; //ida e volta
    
    int i;
    int j;
    int aux_int;
    Aresta aux_aresta;

    Vertice* Grafo = new Vertice[num_vertices];
    vector<Aresta> Arestas_Grafo;

    for(i =0; i<(num_arestas/2);i++){
        int ida;
        scanf("%d", &ida);
        aux_aresta.origem = ida;
        ida--;
        scanf("%d", &aux_aresta.destino);
        scanf("%lld", &aux_aresta.ano);
        scanf("%lld", &aux_aresta.tempo);
        scanf("%lld", &aux_aresta.custo);
        Grafo[ida].arestas.push_back(aux_aresta);
        Arestas_Grafo.push_back({(ida+1),aux_aresta.destino,aux_aresta.ano,aux_aresta.tempo,aux_aresta.custo});
        aux_aresta.origem = aux_aresta.destino;
        int volta = aux_aresta.destino - 1;
        aux_aresta.destino = ida + 1;
        Grafo[volta].arestas.push_back(aux_aresta);
        Arestas_Grafo.push_back({(volta+1),aux_aresta.destino,aux_aresta.ano,aux_aresta.tempo,aux_aresta.custo});
    }

    cout<<endl<<"---------------------------VÉRTICES -------------------------------"<<endl<<endl;


    for(i =0; i<num_vertices;i++){
        cout<<"ORIGEM = "<<(i+1)<<endl;
        for(j=0;j< Grafo[i].arestas.size();j++){
            cout<<"DESTINO = "<<Grafo[i].arestas[j].destino<<"  ";
            cout<<"ANO = "<<Grafo[i].arestas[j].ano<<"  ";
            cout<<"TEMPO = "<<Grafo[i].arestas[j].tempo<<"  ";
            cout<<"CUSTO = "<<Grafo[i].arestas[j].custo<<"  ";
        }
        cout<<endl;
    }

    cout<<endl<<"---------------------------ARESTAS -------------------------------"<<endl<<endl;

    for(i =0; i<num_arestas;i++){
        cout<<"ORIGEM = "<<Arestas_Grafo[i].origem<<"  ";
        cout<<"DESTINO = "<<Arestas_Grafo[i].destino<<"  ";
        cout<<"ANO = "<<Arestas_Grafo[i].ano<<"  ";
        cout<<"TEMPO = "<<Arestas_Grafo[i].tempo<<"  ";
        cout<<"CUSTO = "<<Arestas_Grafo[i].custo<<"  ";
        cout<<endl;
    }


    cout<<endl<<"---------------------------QUESTÂO 1 -------------------------------"<<endl<<endl;


    Retorno_Dijkstra D = Dijkstra_Adaptado(Grafo,num_vertices);
    for(i =0; i<num_vertices;i++){
        cout<<"VERTICE = "<<(i+1)<<"  ";
        cout<<"CUSTO = "<<(D.tempos)[i]<<endl;
    }
        cout<<"ANO MIN = "<<D.ano_min<<endl;

    cout<<endl<<"---------------------------QUESTÂO 2 -------------------------------"<<endl<<endl;

    long long int menor_ano = Kruskal_Menor_Ano(num_vertices,Arestas_Grafo,num_arestas);

    cout<<"ANO MIN = "<<menor_ano<<endl;

        cout<<endl<<"---------------------------QUESTÂO 3 -------------------------------"<<endl<<endl;

    long long int menor_custo = Kruskal_Menor_Custo(num_vertices,Arestas_Grafo,num_arestas);

    cout<<"CUSTO MIN = "<<menor_custo<<endl<<endl;





    return 0;
}