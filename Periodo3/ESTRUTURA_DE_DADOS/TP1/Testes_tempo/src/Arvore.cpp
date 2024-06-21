#include <iostream>
#include <../include/Arvore.hpp>

using namespace std;

Arvore::Arvore(){
    Raiz = NULL;
}

bool Arvore::Arvore_Vazia(){
    return (Raiz == NULL);

}

bool Arvore::Montar_Arvore(string Entrada,bool Infixa){ //true = Infixo & false = Posfixo
    /* Essa função existe para deixar o código mais limpo*/
    if(!Infixa){
        Pilha<string> Auxiliar;
        Montar_Pilha_De_String(Entrada,&Auxiliar);
        try{
            Montar_Arvore_Pela_Entrada_Posfixa(&Auxiliar,&Raiz); 
        }
        catch(Erro_de_Montagem Mensagem){
            cout<<Mensagem.Printar<<endl;
            Limpar_Arvore();
            return false;
        }
    }

    if(Infixa){
        /*Queremos converter a string Entrada para um char**, para isso primeiro usamos a funcao c_str()
        para converter string para const char*, depois usamos const_cast<char*> para converter const char*
        em um char*.
        */
       char* Entrada_char = (const_cast<char*>(Entrada.c_str()));
        try{
            Raiz = Montar_Arvore_Pela_Entrada_Infixa(&(Entrada_char));
        }
        catch(Erro_de_Montagem Mensagem){
            cout<<Mensagem.Printar<<endl;
            Limpar_Arvore();
            return false;
        }
    }
    return true;
}

bool Arvore::Limpar_Arvore(){
    /*Essa função é usada na main, logo por questão de uma maior robustez decidi criar uma de limpeza recursiva
    para deixar essa mais "limpa"*/
    Limpa_Recursivo(&Raiz);
    if(Arvore_Vazia()){
        return true;
    }
    else{
        return false;
    }
}

string Arvore::Retorna_Infixa(){
    return Caminha_In_Ordem_Adaptada(Raiz);
}

string Arvore::Retorna_Posfixa(){
    return Caminha_Pos_Ordem_Adaptada(Raiz);
}

double Arvore::Retorna_Resultado(){
    return Resultado_Recursivo(Raiz);
}


void Arvore::Limpa_Recursivo(No** p){
    No* Auxiliar;
    /*Condição de parada*/
    if((*p) == NULL) return;

    /*Essas chamadas recursivas permitem limpar a árvore inteira*/
    Limpa_Recursivo(&((*p)->Direita));
    Limpa_Recursivo(&((*p)->Esquerda));
    Auxiliar = (*p) ;
    (*p)  = NULL;
    delete Auxiliar;

}

string Arvore::Caminha_In_Ordem_Adaptada(No* p){
    string Retorno = "";

    string Auxiliar = p->Elemento;

    /*Condição de parada das chamadas recursivas*/
    if((p->Esquerda == NULL)&&(p->Direita == NULL)){
        return Auxiliar;
    }
    /*Chamas recursivas de um caminhamento in ordem bem simples que vai adicionando os elementos lidos em uma string*/
    else{
        string Direito = "( ";
        string Esquerdo = " )";
        Retorno = Direito+ Caminha_In_Ordem_Adaptada(p->Esquerda)+ Esquerdo + " " + Auxiliar +  " " + Direito + Caminha_In_Ordem_Adaptada(p->Direita)+ Esquerdo;
        return Retorno;
    }
}

string Arvore::Caminha_Pos_Ordem_Adaptada(No* p){
    string Retorno = "";

    string Auxiliar = p->Elemento;

    /*Condição de parada das chamadas recursivas*/
    if((p->Esquerda == NULL)&&(p->Direita == NULL)){
        return Auxiliar;
    }
    /*Chamadas recursivas de um caminhamento pos ordem bem simples que vai adicionando os elementos lidos em uma string*/
    else{
        Retorno = Caminha_Pos_Ordem_Adaptada(p->Esquerda) + " " + Caminha_Pos_Ordem_Adaptada(p->Direita) + " " + Auxiliar;
        return Retorno;
    }
}


No* Arvore::Montar_Arvore_Pela_Entrada_Infixa(char** Entrada){
    /*Essa função usa da recursão para ir montando uma Pilha de No* por nível da expressão, isto é, a cada parenteses que é aberto temos
     um nível diferente e chama de forma recursiva essa função.Como uma string é um const char* ela não fucionaria nessa função, pois precisamos que o ponteiro de leitura 
    vá se alterando ao longo das chamadas recursivas. Além disso, também precisamos ir alterando o ponteiro em si, logo precisando usar um 
    ponteiro para esse ponteiro.*/
    Pilha <No*> Entrada_Adaptada,Entrada_Adaptada_Auxiliar;
    No* Auxiliar;


    while((*(*Entrada))==' '){
        (*Entrada)++;
    }

    char Parada = '\0';
    if((*(*Entrada)) == '('){
        Parada = ')';
        (*Entrada)++;
    }


    /*Um laço para ir passando por cada char da string*/
    while(((*(*Entrada)) != Parada)&&((*(*Entrada)) != '\n')){
        /* Obviamente a string contém espaços que não fazem parte da árvore, logo temos que ignora-los*/
        if((*(*Entrada)) == ' '){
        } 
        else{
            /*Se achar um operador temos que criar um 'No' para armazena-lo*/
            if(((*(*Entrada)) == '+') || (((*(*Entrada)) == '-')&&(*(*Entrada)+1) == ' ') || ((*(*Entrada)) == '/') || ((*(*Entrada)) == '*')){
                Auxiliar = new No;
                Auxiliar->Elemento = "";
                Auxiliar->Elemento = Auxiliar->Elemento+(*(*Entrada)); 
                Entrada_Adaptada.Empilha(Auxiliar);
            }
            else{
                /*Se achar um '(' temos que chamar recursivamente a função para criar um 'No' para armazenar tudo o que está dentro do '()'*/
                if((*(*Entrada)) == '('){
                    Entrada_Adaptada.Empilha(Montar_Arvore_Pela_Entrada_Infixa(Entrada));
                }
                /*Se achar um operador temos que criar um 'No' para armazena-lo*/
                else{
                    Auxiliar = new No;
                    Auxiliar->Elemento = "";
                    while(((*(*Entrada)) != '\0') && ((*(*Entrada)) != ' ')){
                        Auxiliar->Elemento = Auxiliar->Elemento +(*(*Entrada));
                        (*Entrada)++;
                    }
                    Entrada_Adaptada.Empilha(Auxiliar);
                }
            }

        }
        (*Entrada)++;
    }
    //Ajustes para que o ponteiro 'Entrada' esteja apontando para o lugar certo na chamada recursiva anterior
    while((*(*Entrada)) ==  ' '){
        (*Entrada)++;
    }
    if((*(*Entrada)) == ')') (*Entrada)++;


    /*Aqui estamos montando um No que representa o nível da expressão, isto é, ou a parte inicial de uma expressão ou tuda a parte entre '()' dentro da expressão. 
    Vale lembrar que pelo fato de nos termos uma pilha a expressão esta sendo analisada ao contrário.*/
    while (!Entrada_Adaptada.Pilha_Vazia())
    {   
         /*Como confirmamos antes que a Pilha não vai estar vazia não precisamos do try nesse desempilha*/
        Auxiliar = Entrada_Adaptada.Desempilha();

        /*Primeiramente montamos os nós das operações de multiplicação e divisão por causa da precedência de operadores.Vale lembrar que é necessário 
        conferir se esse nó achado possui nos filhos, pois se ele possuir significa que ele representa um outro nível '()' que ja foi armazenado corretamente.
        Ao acharmos um desses operadores que , primeiro precisamos do ultimo elemento que foi desempilhado antes dele, armazenado na pilha "Entrada_Adaptada_Auxiliar"
        e o proximo elemento a ser desempilhado na pilha Entrada_Adaptada. Depois, com esses três nós em mãos atribuimos esses dois nós desempilhados
        como sendo os elementos da direita e da esquerda desse nó com a operação.*/
        if(((Auxiliar->Elemento == "*")||(Auxiliar->Elemento == "/"))&&((Auxiliar->Direita == NULL)&&(Auxiliar->Esquerda == NULL))){
            /*Como confirmamos antes que a Pilha não vai estar vazia não precisamos do try nesse desempilha*/
            Auxiliar->Esquerda  = Entrada_Adaptada.Desempilha();
            /*Montar primeiro o no esquerdo e depois o direito é pelo fato da pilha representar a expressão ao contrário*/
            try{
                Auxiliar->Direita = Entrada_Adaptada_Auxiliar.Desempilha();
            }
            catch(Pilha_vazia Mesagem_de_Erro){
                cout<<Mesagem_de_Erro.Printar<<endl<<"FUNÇÃO = \"Montar_Arvore_Pela_Entrada_Infixa\""<< endl;
                throw Erro_de_Montagem{"ERRO AO MONTAR ARVORE"};
            }
            Entrada_Adaptada_Auxiliar.Empilha(Auxiliar);
        }
        else{
            Entrada_Adaptada_Auxiliar.Empilha(Auxiliar);
        }
    }
    while(!Entrada_Adaptada_Auxiliar.Pilha_Vazia()){
         /*Como confirmamos antes que a Pilha não vai estar vazia não precisamos do try nesse desempilha*/
            Auxiliar = Entrada_Adaptada_Auxiliar.Desempilha();
        /*O exato mesmo processo explicado previamente so que feito para o '+' e '-'. A única diferença é que nesse processo */
        if(((Auxiliar->Elemento == "+")||(Auxiliar->Elemento == "-"))&&((Auxiliar->Direita == NULL)&&(Auxiliar->Esquerda == NULL))){
        /*Montar primeiro o no direito e depois o esquedo é pelo fato da pilha inicial representar a expressão ao contrário e essa pilha
        ser o inverso da outra*/
        /*Como confirmamos antes que a Pilha não vai estar vazia não precisamos do try nesse desempilha*/
        Auxiliar->Direita = Entrada_Adaptada_Auxiliar.Desempilha();
        try{
            Auxiliar->Esquerda = Entrada_Adaptada.Desempilha();
        }
        catch(Pilha_vazia Mesagem_de_Erro){
            cout<<Mesagem_de_Erro.Printar<<endl<<"FUNÇÃO = \"Montar_Arvore_Pela_Entrada_Infixa\""<< endl;
            throw Erro_de_Montagem{"ERRO AO MONTAR ARVORE"};
        }
            Entrada_Adaptada.Empilha(Auxiliar);
        }
        else{
            Entrada_Adaptada.Empilha(Auxiliar);
        }
    }
    /*No retorno, temos uma pilha com somente um Nó, que de fato é o que representa o nível. Ao final das chamadas recursivas
    esse no vai representar a raiz de uma árvore construida através dos níveis*/
    try{
        Auxiliar = Entrada_Adaptada.Desempilha();
    }
    catch(Pilha_vazia Mesagem_de_Erro){
        cout<<Mesagem_de_Erro.Printar<<endl<<"FUNÇÃO = \"Montar_Arvore_Pela_Entrada_Infixa\""<< endl;
    }
    return Auxiliar;

}

void Arvore::Montar_Arvore_Pela_Entrada_Posfixa(Pilha<string>* Entrada,No** p){

    No* Novo = new No;
    
    if(!(Entrada->Pilha_Vazia())){
        /*Como confirmamos antes que a Pilha não vai estar vazia não precisamos do try nesse desempilha*/
        string Auxiliar = Entrada->Desempilha();
        /*De forma bem simples, através de uma pilha a expressão posfixa é armazenada na arvore.Quando temos um operador chamamos a 
        funcao novamente de forma recursiva pois os próximos dois elementos da pilha são seus filhos e eles,por sua vez, podem ou não possuir 
        fihos.*/
        if((Auxiliar == "+")||(Auxiliar == "-")||(Auxiliar == "*")||(Auxiliar == "/")){
            Novo->Elemento = Auxiliar;
            (*p) = Novo;
            Montar_Arvore_Pela_Entrada_Posfixa(Entrada,&((*p)->Direita));
            Montar_Arvore_Pela_Entrada_Posfixa(Entrada,&((*p)->Esquerda));
        }
        /*Se for um numero colocamos ele na arvore, ele não vai possuir filhos pois os numeros sempre ficam nas folhas*/
        else{
            Novo->Elemento = Auxiliar;
            (*p) = Novo;
        }
        return;
    }
    else throw Erro_de_Montagem{"ERRO AO MONTAR ARVORE"};
    return;

}

double Arvore::Resultado_Recursivo(No* p){
    /*Com a árvore montada achar o resultado é bem simples. Usando da recursão podemos ir fazendo as contas a partir das folhas até a raiz*/
    if((p->Direita == NULL)&&(p->Esquerda == NULL)) return stod(p->Elemento);

    if(p->Elemento == "+") return Resultado_Recursivo(p->Esquerda) + Resultado_Recursivo(p->Direita);

    if(p->Elemento == "-") return Resultado_Recursivo(p->Esquerda) - Resultado_Recursivo(p->Direita);

    if(p->Elemento == "*") return Resultado_Recursivo(p->Esquerda) * Resultado_Recursivo(p->Direita);

    if(p->Elemento == "/") return (Resultado_Recursivo(p->Esquerda))/(Resultado_Recursivo(p->Direita));
 
    
    return 0.0;
}
Arvore::~Arvore(){
    Limpar_Arvore();
}
