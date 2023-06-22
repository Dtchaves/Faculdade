#include <../include/Fecho_Convexo.hpp>
    

Fecho_Convexo::Fecho_Convexo(){
    
}

void Fecho_Convexo::Imprimir_Fecho_Convexo(){
    Pilha<Ponto> Guardar;
    Ponto Auxiliariliar;
    /*Vai desempilhando o fecho e imprimindo.Os valores são guardados em uma pilha Auxiliariliar para não serem perdidos*/
    while(!Fecho.Pilha_Vazia()){
        Auxiliariliar = Fecho.Desempilha();
        Guardar.Empilha(Auxiliariliar);
        cout<<Auxiliariliar.Retorna_Ponto()<<endl;
    }
    /*Os valores da pilha Auxiliariliar são novamente guardados na pilha "Fecho" da classe*/
    while(!Guardar.Pilha_Vazia()){
        Fecho.Empilha(Guardar.Desempilha());
    }
}


void Fecho_Convexo::Montar_Fecho_Convexo(string Algoritmo, string Ordenacao,Ponto* Vetor_Entrada,int Tamanho_Entrada){

    /*Monta o fecho convexo de acordo com o algoritmo escolhido*/
    if(Algoritmo == "Grahamscan"){ 
        return Montar_com_graham_scan(Vetor_Entrada,Tamanho_Entrada,Ordenacao);
    }
    else {
        if(Algoritmo == "Jarvismarch"){
           return Montar_com_jarvis_march(Vetor_Entrada,Tamanho_Entrada);
        }
        else{
            throw Algoritmo_Invalido{Algoritmo};
        }
    }
}

void  Fecho_Convexo::Montar_com_jarvis_march(Ponto* Vetor_Entrada,int Tamanho_Entrada){

    /*Primeiramente vamos escolher o elemento do Vetor_Entrada com a menor coordenada X para poder utilizar o algoritmo "Jarvismarch". Sua complexidade de n*/
    int i;
    int Vaga_menor_X = 0;
    for(i = 0;i<Tamanho_Entrada;i++){
        if (Vetor_Entrada[i].X < Vetor_Entrada[Vaga_menor_X].X) Vaga_menor_X = i;
        if ((Vetor_Entrada[i].X == Vetor_Entrada[Vaga_menor_X].X) && (Vetor_Entrada[i].Y < Vetor_Entrada[Vaga_menor_X].Y)) Vaga_menor_X = i;
    }

    /*Utilizando vagas do vetor, criamos valores auxiliares para podermos ir analizando as orientações entre as retas que iremos ir formando*/
    int Vaga_ultimo = Vaga_menor_X;
    int Vaga_atual = 0;
    int Vaga_analisar = 0;

    /*Loop que utiliza do algoritmo "Jarvismarch". A partir do ponto com menor x são analisadas as retas formadas entre os pontos e sua orientação para 
    determinar o feicho convexo*/
    do{
        for(Vaga_analisar = 0; Vaga_analisar< Tamanho_Entrada;Vaga_analisar++){
            /*Função utilizada para acharmos a orientação entre as retas*/
            int Ori = Orientacao(Vetor_Entrada[Vaga_ultimo],Vetor_Entrada[Vaga_atual],Vetor_Entrada[Vaga_analisar]);
            /*Se duas retas não estiverem no sentido horário é necessário atualizar as vagas*/
            if(((Ori == 1) || (Vaga_ultimo == Vaga_atual)) || ((Ori == 0) && ((Vetor_Entrada[Vaga_ultimo].Distancia(Vetor_Entrada[Vaga_analisar]) > Vetor_Entrada[Vaga_ultimo].Distancia(Vetor_Entrada[Vaga_atual])) && (Vaga_atual != Vaga_menor_X)) ) ){
                Vaga_atual = Vaga_analisar;
            }
        }

        /*Empilha o novo ponto achado*/
        Ponto Armazenar_Fecho;
        Armazenar_Fecho.Monta_Ponto(Vetor_Entrada[Vaga_ultimo].X,Vetor_Entrada[Vaga_ultimo].Y);
        Fecho.Empilha(Armazenar_Fecho);

        Vaga_ultimo = Vaga_atual;
        Vaga_atual = 0;

    }while(Vaga_ultimo != Vaga_menor_X); /*Essa condição de parada é atendida quando damos uma volta completa e chegamos no ponto de partida, significando que, de fato, achamos o fecho*/

}

void Fecho_Convexo::Montar_com_graham_scan(Ponto* Vetor_Entrada,int Tamanho_Entrada,string Ordenacao){
    /*Achar Ponto com o menor Y e guardar sua vaga*/
    int i;
    int Vaga_menor_Y = 0;
    for(i = 0;i<Tamanho_Entrada;i++){
        if (Vetor_Entrada[i].Y < Vetor_Entrada[Vaga_menor_Y].Y) Vaga_menor_Y = i;
        if ((Vetor_Entrada[i].Y == Vetor_Entrada[Vaga_menor_Y].Y) && (Vetor_Entrada[i].X < Vetor_Entrada[Vaga_menor_Y].X)) Vaga_menor_Y = i;

    }

    /*Montar Retas com o menor Y*/
    Reta Retas_origem_menor_Y[Tamanho_Entrada-1];
    Reta Montagem;
    int j;/*j é para passar as vagas do Vetor_Entrada e i do Menor_Y*/
    for(i = 0,j = 0; i<(Tamanho_Entrada-1);i++,j++){
        if(j == Vaga_menor_Y) j++;
        Montagem.Monta_Reta(Vetor_Entrada[Vaga_menor_Y],Vetor_Entrada[j]);
        Retas_origem_menor_Y[i] = Montagem;
    }
    /*Ordenar de acordo com o método escolhido*/
    if(Ordenacao == "InsertionSort") Insertion_sort_Graham_scan(Retas_origem_menor_Y,(Tamanho_Entrada-1));
    if(Ordenacao == "MergeSort") Merge_sort_Graham_scan(Retas_origem_menor_Y,0,(Tamanho_Entrada-2));
    if(Ordenacao == "BucketSort") Bucket_sort_Graham_scan(Retas_origem_menor_Y,Tamanho_Entrada-1);
    if((Ordenacao != "BucketSort")&&(Ordenacao == "InsertionSort") && (Ordenacao == "Mergesort")) throw Ordenacao_Invalida{Ordenacao};

    /*Passa as retas ordenadas para um vetor de pontos*/
    Ponto* Pontos_ordenados = new Ponto[Tamanho_Entrada];
    Pontos_ordenados[0] = Vetor_Entrada[Vaga_menor_Y];
    for(i = 1; i<Tamanho_Entrada;i++){
        Pontos_ordenados[i] = Retas_origem_menor_Y[i-1].Ponto_2;
    } 

    Ponto Ultimo_ponto;
    Ponto Atual_ponto;
    Fecho.Empilha(Pontos_ordenados[0]);
    Fecho.Empilha(Pontos_ordenados[1]);

    Reta Auxiliariliar;
    Auxiliariliar.Monta_Reta(Ultimo_ponto,Atual_ponto);

    /*Loop que utiliza do algoritmo "Grahamscan". Passando pelos pontos ordenados pelo angulo, atualizando a pilha para achar o fecho*/
    for(i = 2;i%Tamanho_Entrada!=1;i++){
        Atual_ponto = Fecho.Desempilha();
        Ultimo_ponto = Fecho.Desempilha();
        Fecho.Empilha(Ultimo_ponto);
        Fecho.Empilha(Atual_ponto);
        while((Fecho.Retorna_Tamanho() > 1) && (Orientacao(Ultimo_ponto,Atual_ponto,Pontos_ordenados[i]) != 1)){ /*-1 = horario*/
            Fecho.Desempilha();
            Atual_ponto = Fecho.Desempilha();
            if(!Fecho.Pilha_Vazia()){
                Ultimo_ponto = Fecho.Desempilha();
                Fecho.Empilha(Ultimo_ponto);
            }
            Fecho.Empilha(Atual_ponto);
        }
        Fecho.Empilha(Pontos_ordenados[i]);
    }

    delete Pontos_ordenados;
}

int Fecho_Convexo::Orientacao(Ponto Ponto_ultimo,Ponto Ponto_atual,Ponto Ponto_analise){
    /*Acha a orientação entre duas retas formadas pelos pontos de entrada analisando a diferença entre os coeficientes angulares*/
    float Resultado = ((Ponto_analise.Y - Ponto_atual.Y) * (Ponto_atual.X - Ponto_ultimo.X)) - ((Ponto_atual.Y - Ponto_ultimo.Y) * (Ponto_analise.X - Ponto_atual.X));
    if (Resultado == 0){
        return 0; /*Pontos Colineares*/
    } 
    else{
        if(Resultado < 0){
            return -1; /*Pontos sentido horário*/
        }
        else{
            return 1; /* Pontos sentido antihorário*/
        }
    }
}

void Fecho_Convexo::Bucket_sort_Graham_scan(Reta* Vetor_Entrada,int Tamanho_Entrada){
    int Numero_Baldes,i;
    if(Tamanho_Entrada>1000){
        Numero_Baldes = 1000;
    }
    else{
        Numero_Baldes = Tamanho_Entrada;
    }

    double Intervalo = M_PI/Numero_Baldes;
    Pilha<Reta>* Baldes_Entrada = new Pilha<Reta>[Numero_Baldes];
    int Auxiliar;

    for (i = 0; i<Tamanho_Entrada;i++){
        Auxiliar = round( (Vetor_Entrada[i].Angulo)/ Intervalo);
        Baldes_Entrada[Auxiliar].Empilha(Vetor_Entrada[i]);
    }

    int Vaga_do_Vetor_Entrada = 0;
    for (i = 0; i<Numero_Baldes;i++){

        if(!Baldes_Entrada[i].Pilha_Vazia()){

            int Tamanho_Balde = Baldes_Entrada[i].Retorna_Tamanho();
            Reta* Ordenar = new Reta[Tamanho_Balde];
            Auxiliar = 0;

            while(!Baldes_Entrada[i].Pilha_Vazia()){
                Ordenar[Auxiliar] = Baldes_Entrada[i].Desempilha();
                Auxiliar++;
            }

            Auxiliar = 0;
            Insertion_sort_Graham_scan(Ordenar,Tamanho_Balde);

            while(Auxiliar < Tamanho_Balde){
                Vetor_Entrada[Vaga_do_Vetor_Entrada] = Ordenar[Auxiliar];
                Auxiliar++;
                Vaga_do_Vetor_Entrada++;
            }
            

            delete[] Ordenar;
        }
    }


    delete[] Baldes_Entrada;
}

void Fecho_Convexo::Merge_sort_Graham_scan(Reta* Vetor_Entrada, int Inicio,int Fim){
    /*Mergesort bem simples que ordena o vetor de retas pelo angulo. Sua complexidade é n * log n*/
    /*Condição de parada para a função recursiva.*/
    if(Fim - Inicio < 1) return;

    /*Define a metade*/
    int Metade = (Fim+Inicio)/2;

    /*Repete o processo de divisão para cada partição até atender a condição de parada*/
    Merge_sort_Graham_scan(Vetor_Entrada,Inicio,Metade);
    Merge_sort_Graham_scan(Vetor_Entrada,Metade+1,Fim);

    /*Junta as partições já ordenadas mantendo a ordenação*/
    Merge(Vetor_Entrada,Inicio,Metade,Fim);

}
void Fecho_Convexo::Merge(Reta* Vetor_Entrada,int Inicio,int Metade, int Fim){
    /*Depois de dividido, essa função junta, em duplas, as partições do vetor já ordenadas
    sem perder a ordenação.*/
    int Tamanho = Fim-Inicio+1;
    int i = Inicio;
    int j = Metade + 1;
    int k = 0;
    /*Vetor auxiliar para ir guardando a junção ordenada*/
    Reta* Auxiliariliar = new Reta[Tamanho];

    /*Loop utilizado para juntar de forma ordenada*/
    while((i <= Metade)&&(j <= Fim)){
        if((Vetor_Entrada[i]).Angulo > (Vetor_Entrada[j]).Angulo){
            Auxiliariliar[k] = Vetor_Entrada[j];
            j++;
        }
        else{
            Auxiliariliar[k] = Vetor_Entrada[i];
            i++;
        }
        k++;
    }

    /*Loops para acabar de juntar caso uma partição já tiver sido adicionada no vetor auxiliar e a outra
    não*/
    while(i <= Metade){
        Auxiliariliar[k] = Vetor_Entrada[i];
        i++;
        k++;
    }
    while(j <= Fim){
        Auxiliariliar[k] = Vetor_Entrada[j];
        j++;
        k++;
    }

    /*Depois de juntar de forma ordenada é necessário passar os valores do vetor auxiliar para o vetor original*/
    for(int Auxiliar = Inicio; Auxiliar<=Fim; Auxiliar++){
        Vetor_Entrada[Auxiliar] = Auxiliariliar[Auxiliar - Inicio];
    }

    delete [] Auxiliariliar;

}

void Fecho_Convexo::Insertion_sort_Graham_scan(Reta* Vetor_Entrada,int Tamanho_Entrada){
    int i,j;
    Reta Auxiliar;

    /*Insertion sort bem simples que ordena utilizando os ângulos das retas.
    Ele vai movendo o vetor até achar a posição correta para inserir o elemento da vez.
    Sua complexidade é n²*/
    for(i = 1; i< Tamanho_Entrada;i++){
        Auxiliar = Vetor_Entrada[i];
        j = i;
        while((j>0)&&(Vetor_Entrada[j-1].Angulo > Auxiliar.Angulo)){
            Vetor_Entrada[j] = Vetor_Entrada[j-1];
            j = j-1;
        }
        Vetor_Entrada[j] = Auxiliar;
    }
}