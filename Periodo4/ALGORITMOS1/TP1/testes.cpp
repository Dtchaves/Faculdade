  cout<<"Numero de arestas = "<<num_arestas<<" Numero de vertices = "<<num_vertices<<endl;
    for(i=0;i<num_vertices;i++){
        cout<<"Localizacao = ("<<vertices_grafo[i].localizacao.x<<","<<vertices_grafo[i].localizacao.y<<")"<<endl;
        cout<<"Grau = "<< vertices_grafo[i].grau <<endl;
        for(j=0;j<vertices_grafo[i].grau;j++){
            cout<<"Aresta = "<<vertices_grafo[i].arestas[j].vertice_destino<<endl;
            cout<<"Angulo = "<<vertices_grafo[i].arestas[j].angulo<<endl;

        }
    }

                    int aux = i;
                    while(vertices_grafo[vert_atual].arestas[i].visitada == true){
                        i = (i+1)%vertices_grafo[vert_atual].grau;
                        if(i == aux){
                            return;
                        }
                    }
//////////////////////////////////////////////////////////////////////////////

               if((vertices_grafo[vert_atual].arestas[i].vertice_destino-1) == vert_pai){
                    if(i == (vertices_grafo[vert_atual].grau-1)){
                        i = 0;
                        while(vertices_grafo[vert_atual].arestas[i].visitada == true){
                            i++;
                            if(i == vertices_grafo[vert_atual].grau-1){
                                return;
                            }
                        }   
                    }
                    else{
                        int aux = i;
                        while(vertices_grafo[vert_atual].arestas[i].visitada == true){
                            i++;
                            if(i == aux){
                                return;
                            }
                            if(i == (vertices_grafo[vert_atual].grau-1)) i = 0;
                        }
                    }
                    break;
                }
///////////////////////////////////////////////////////////////////////////
    Ponto pontoA = {1,1};
    Ponto pontoB = {2,2};;
    Ponto pontoC = {3,1};


    cout<<"InclinacaoRelativa= "<<InclinacaoRelativa(pontoB,pontoA)<<endl;
    cout<<"TipoCurva= "<<TipoCurva(pontoC,pontoA,pontoB)<<endl;

/////////////////////////////////////////////////////////////////////////////// 

/*Distancia euclidiana de a para b.*/
double Distancia(Ponto a, Ponto b) {
    double x = (a.x - b.x), y = (a.y - b.y);
    return sqrt(x*x + y*y);
}

/* Coeficiente da reta que passa na origem e p. */
double Inclinacao(Ponto p) {
    return atan2(p.y, p.x);
}

/* Determina se ao caminhar de a para b e depois de b para c 
estamos fazendo uma curva `a esquerda, `a direita, ou seguindo em frente.*/
int TipoCurva(Ponto a, Ponto b, Ponto c) {
    double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; // esquerda.
    if (v > 0) return +1; // direita.
    return 0; // em frente.
}

    