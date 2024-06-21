#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include<climits>

using namespace std;

/*Struct para representar uma aresta desse grafo, possuindo como elementos:
-> Os vértices que ela liga
-> O ano de construção dela
-> O tempo para sua travessia
->O seu custo
 */
struct Aresta {
    int origem;
    int destino;
    long long int ano;
    long long int tempo;
    long long int custo;
};


/*Struct para representar um vértice desse grafo, possuindo como elemento a lista de arestas que saem desse vértice*/
struct Vertice{
    vector<Aresta> arestas;
};

    /*---------------------------QUESTÂO 1 -------------------------------*/


/*Struct para armazenar as distancias minimas e o primeiro ano que elas podem ser alcançadas*/
struct Retorno_Dijkstra{
    vector<long long int> distancias;
    long long int primeiro_ano;
};

/*Dijkstra para responder a questão 1 e retornar a distancias mínimas e o primeiro ano que elas podem ser alcançadas*/
Retorno_Dijkstra Dijkstra(Vertice* Grafo, int num_vertices){

    int vertice_v,vertice_u,valor_aresta_vu,ano_vu,i;

    long long int infinito = LLONG_MAX;
    vector<long long int> distancias(num_vertices,infinito);
    distancias[0] = 0;

    vector<long long int> anos(num_vertices,-1);
    anos [0] = 0;
    
    set<int> Q;
    Q.insert(0);

    while(!Q.empty()){
        vertice_v = *(Q.begin());
        Q.erase(Q.begin());

        for(i = 0; i< (Grafo[vertice_v].arestas).size();i++){

            /*Pegamos a aresta de destino*/
            vertice_u = ((Grafo[vertice_v].arestas[i]).destino)-1;

            /*Pegamos o ano min em que o caminho que passa por v e chega em u é possível*/
            valor_aresta_vu = ((Grafo[vertice_v].arestas[i]).tempo);
            ano_vu = ((Grafo[vertice_v].arestas[i]).ano);
            if(anos[vertice_v]> ano_vu) ano_vu = anos[vertice_v];

            /*Atualizamos os caminhos como em um Dijkstra normal, usando o tempo como parâmetro*/
            if(distancias[vertice_u] > ( distancias[vertice_v] + valor_aresta_vu ) ){
                anos[vertice_u] = ano_vu;
                distancias[vertice_u] = distancias[vertice_v] + valor_aresta_vu;
                Q.insert(vertice_u);qq
            }
            else{
                /*Caso seja igual, queremos priorizar o caminho que poderá ocorrer no menor ano*/
                if(distancias[vertice_u] == ( distancias[vertice_v] + valor_aresta_vu ) ){
                    if(anos[vertice_u] > ano_vu){
                        anos[vertice_u] = ano_vu;
                    }
                }
            }
        }
    }
    return {distancias,*( max_element ( anos.begin(), anos.end() ) ) };
}


    /*---------------------------TAD PARA AS QUESTÕES 2 e 3 -------------------------------*/

/*Disjoint-Set Union para melhorar a eficiência do algoritmo de Kruskal*/
class DSU{

    public:

    /*Contrutor para montar os componentes*/
    DSU(int num_vertices){
        componente.resize(num_vertices);
        tamanho.resize(num_vertices);
        for(int i =0; i<num_vertices;i++){
            componente[i] = i;
            tamanho[i] = 1;
        }

    }

    /*Função para achar o componente do vértice indicado de forma recursiva*/
    int Achar_Componente(int v){
        if(v != componente[v]){
            componente[v] = Achar_Componente(componente[v]);
        }
        return componente[v];
    }

    /*Função para unir dois componentes*/
    void Uniao(int a,int b){
        a = Achar_Componente(a);
        b = Achar_Componente(b);

        if(tamanho[a] < tamanho[b]){
            componente[a]= b;
            tamanho[b] = tamanho[b] + tamanho[a];
        }
        else{
            componente[b]= a;
            tamanho[a] = tamanho[b] + tamanho[a];
        }
        return;
    }

    private:

    /*Representa o componente do vértice*/
    vector<int> componente;

    /*Representa os tamanhos dos componentes*/
    vector<int> tamanho;
};

    /*---------------------------QUESTÃO 2 -------------------------------*/

/*Função para conseguir ordenar o set por ano*/
bool Comparador_Kruskal_Menor_Ano(Aresta a, Aresta b) {
    return a.ano < b.ano;
}

/*Kruskal usando o DSU para achar a árvore geradora com menor ano*/
long long int Kruskal_Menor_Ano(int num_vertices, vector<Aresta>& Arestas_Grafo,int num_arestas){

    /*Declara o TAD e ordena as arestas pelo ano*/
    DSU componentes(num_vertices);
    long long int menor_ano = 0;
    sort(Arestas_Grafo.begin(),Arestas_Grafo.end(),Comparador_Kruskal_Menor_Ano);
    Aresta uv;

    /*Faz o Kruskal clássico escolhendo a menor aresta em relação ao ano e atualizando o menor ano possível caso essa aresta possua um ano maior que o armazenado*/
    for(int i = 0; i<num_arestas;i++){
        uv = Arestas_Grafo[i];
        if(componentes.Achar_Componente(uv.origem-1) != componentes.Achar_Componente(uv.destino-1)){
            if(menor_ano < uv.ano){
                menor_ano = uv.ano;
            }
            componentes.Uniao((uv.origem-1),(uv.destino-1));
        }
    }
    return menor_ano;
}


    /*---------------------------QUESTÃO 3 -------------------------------*/

/*Função para conseguir ordenar o set por custo*/
bool Comparador_Kruskal_Menor_Custo(Aresta a, Aresta b) {
    return a.custo < b.custo;
}

/*Kruskal usando o DSU para achar a árvore geradora com menor custo total*/
long long int Kruskal_Menor_Custo(int num_vertices, vector<Aresta>& Arestas_Grafo,int num_arestas){

    /*Declara o TAD e ordena as arestas pelo custo*/
    DSU componentes(num_vertices);
    long long int menor_custo = 0;
    sort(Arestas_Grafo.begin(),Arestas_Grafo.end(),Comparador_Kruskal_Menor_Custo);
    Aresta uv;

    /*Faz o Kruskal clássico escolhendo a menor aresta em relação ao custo e somando o novo custo ao acumulador*/
    for(int i = 0; i<num_arestas;i++){
        uv = Arestas_Grafo[i];
        if(componentes.Achar_Componente(uv.origem-1) != componentes.Achar_Componente(uv.destino-1)){
            menor_custo += uv.custo;
            componentes.Uniao((uv.origem-1),(uv.destino-1));
        }
    }
    return menor_custo;
}




int main(){

    /*Leitura do M e N do grafo*/
    int num_vertices;
    int num_arestas;
        cin>>num_vertices>>num_arestas;
    
    /*Toda aresta de ida também é de volta*/
    num_arestas = num_arestas*2; 
    
    /*Auxiliares*/
    int i;
    int j;
    int aux_int;
    Aresta aux_aresta;

    /*Vertices e suas listas de adjacencia para o Dijkstra*/
    Vertice* Grafo = new Vertice[num_vertices];

    /*Vetor de arestas para o Kruskal*/
    vector<Aresta> Arestas_Grafo;

    /*Montagem das duas estruturas acima lendo a entrada. Temos que lembrar que toda aresta de ida também é de volta*/
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

    /*Todas os valores de vértices estão armazenados em arestas conforme fornecidos na entrada.
    No entanto, em C++, o primeiro índice de vetor é 0, não 1. Portanto, devemos nos lembrar de subtrair 1 
    ao acessar o vértice no vetor "Grafo" para garantir que estamos usando os índices corretos.*/


    /*---------------------------QUESTÂO 1 -------------------------------*/
/*1. Apos a conclusao do projeto, qual sera a distancia minima do palacio real (localizado na vila de indice 1) para cada outro vila?
    (a) Qual o primeiro ano em que todas essas distancias podem ser realizadas ao mesmo tempo?*/

    /*Usando Dijkstra conseguimos esse caminhamento minimo e, com pequenas alterações no código, conseguimos a informação sobre o primeiro ano*/

    Retorno_Dijkstra DistanciasAnoMinimo = Dijkstra(Grafo,num_vertices);
    for(i =0; i<num_vertices;i++){
        cout<<(DistanciasAnoMinimo.distancias)[i]<<endl;
    }
        cout<<DistanciasAnoMinimo.primeiro_ano<<endl;

    /*---------------------------QUESTÂO 2 -------------------------------*/
/*2. Qual o primeiro ano em que todo o reino alcancavel a partir do palacio real?*/

    /*Usando Kruskal conseguimos montar a árvore geradora mínima em função do ano e retornar o primeiro ano no qual o grafo pode se tornar conexo*/


    long long int menor_ano = Kruskal_Menor_Ano(num_vertices,Arestas_Grafo,num_arestas);
    cout<<menor_ano<<endl;

    /*---------------------------QUESTÂO 3 -------------------------------*/
/*3. Se o projeto fosse alterado para apenas garantir que seja possıvel chegar de qualquer vila a qualquer outra, qual seria o menor custo possıvel?*/

    /*Usando Kruskal conseguimos montar a árvore geradora mínima em função do custo e retornar o menor custo total para tornar o grafo conexo*/

    long long int menor_custo = Kruskal_Menor_Custo(num_vertices,Arestas_Grafo,num_arestas);

    cout<<menor_custo<<endl;


    delete []Grafo;
    return 0;
}