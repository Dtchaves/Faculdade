#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

struct Ponto {
    double x, y;
};

struct Aresta {
    int vertice_destino;
    double angulo;
    bool visitada;
};

struct Vertice{
    Ponto localizacao;
    int grau;
    int grau_disponivel;
    vector<Aresta> arestas;
};

bool Comparacao_arestas_do_vertice(Aresta& a,Aresta& b){
    return a.angulo < b.angulo;
}

/* Coeficiente da reta orientada de p para q. */
double InclinacaoRelativa(Ponto p, Ponto q) {
    return atan2(q.y - p.y, q.x - p.x);
}

void DFS_face(int vert_inicio,int aresta_inicio,int vert_pai,int vert_atual,Vertice vertices_grafo[],int num_vertices,vector<int>& face){
    int aresta_destino;
    int i;
    face.push_back(vert_atual+1);
    if(vert_atual == vert_pai){
        i = 0;
        while(vertices_grafo[vert_atual].arestas[i].visitada == true){
            i++;
            if(i == vertices_grafo[vert_atual].grau){
                return;
            }
        }
        aresta_destino = vertices_grafo[vert_atual].arestas[i].vertice_destino-1;
        vertices_grafo[vert_atual].arestas[i].visitada = true;
        vertices_grafo[vert_atual].grau_disponivel--;
        DFS_face(vert_inicio,aresta_destino,vert_atual,aresta_destino,vertices_grafo,num_vertices,face);
    }
    else{
        for(i = 0; i<vertices_grafo[vert_atual].grau;i++){
            if((vertices_grafo[vert_atual].arestas[i].vertice_destino-1) == vert_pai){
                i = (i+1)%vertices_grafo[vert_atual].grau;
                int aux = i;
                if(vert_atual == vert_inicio){
                    while(face.end() != find(face.begin(),face.end(),vertices_grafo[vert_atual].arestas[i].vertice_destino)){
                        if((vertices_grafo[vert_atual].arestas[i].vertice_destino-1) == aresta_inicio){
                            return;
                        }
                        i = (i+1)%vertices_grafo[vert_atual].grau;
                    }
                }
                while(vertices_grafo[vert_atual].arestas[i].visitada == true){
                    i = (i+1)%vertices_grafo[vert_atual].grau;
                    if(i == aux){
                        return;
                    }
                }
                if(vert_atual == vert_inicio){
                    while(face.end() != find(face.begin(),face.end(),vertices_grafo[vert_atual].arestas[i].vertice_destino)){
                        if((vertices_grafo[vert_atual].arestas[i].vertice_destino-1) == aresta_inicio){
                            return;
                        }
                        i = (i+1)%vertices_grafo[vert_atual].grau;
                    }
                }
                break;
            }
        }
        aresta_destino = vertices_grafo[vert_atual].arestas[i].vertice_destino-1;
        vertices_grafo[vert_atual].arestas[i].visitada = true;
        vertices_grafo[vert_atual].grau_disponivel--;
        DFS_face(vert_inicio,aresta_inicio,vert_atual,aresta_destino,vertices_grafo,num_vertices,face);
    }

    return;
}


int main(){

    int num_vertices;
    int num_arestas;
        cin>>num_vertices>>num_arestas;
    
    int i;
    int j;
    int aux_int;
    Aresta aux_aresta;

    Vertice* vertices_grafo = new Vertice[num_vertices];


    i = 0;
    while(cin>>vertices_grafo[i].localizacao.x>>vertices_grafo[i].localizacao.y>>vertices_grafo[i].grau){
        for(j = 0;j<vertices_grafo[i].grau;j++){
            vertices_grafo[i].grau_disponivel = vertices_grafo[i].grau;
            cin>>aux_int;
            aux_aresta.vertice_destino = aux_int;
            aux_aresta.visitada = false;
            vertices_grafo[i].arestas.push_back(aux_aresta);
        }
        i++;
    }

    for(i = 0;i< num_vertices;i++){
        for(j = 0;j<vertices_grafo[i].grau;j++){
            vertices_grafo[i].arestas[j].angulo = InclinacaoRelativa(vertices_grafo[i].localizacao, vertices_grafo[vertices_grafo[i].arestas[j].vertice_destino - 1].localizacao);
        }
        sort(vertices_grafo[i].arestas.begin(),vertices_grafo[i].arestas.end(),Comparacao_arestas_do_vertice);
    }


    vector<vector<int>> Faces;
    vector<int> face;

    for(i = 0; i< num_vertices; i++){
        while(vertices_grafo[i].grau_disponivel != 0){
            DFS_face(i,-1,i,i,vertices_grafo,num_vertices,face);
            Faces.push_back(face);
            face.clear();
        }
    }

    /*IMPRESSÃO*/
    cout<<Faces.size()<<endl;

    for(i=0;i<Faces.size();i++){
        cout<<Faces[i].size()<<" ";
        for(j=0;j<Faces[i].size();j++){
            cout<<Faces[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}