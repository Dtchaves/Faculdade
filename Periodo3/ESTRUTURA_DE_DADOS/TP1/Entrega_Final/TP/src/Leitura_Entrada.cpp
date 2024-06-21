#include <iostream>
#include <../include/Leitura_Entrada.hpp>

using namespace std;


FILE* Abre_Arquivo(int argc,char ** argv){

    /*Ao ir tentando abrir o arquivo a função usa o throw para informar os diferentes erros possíveis*/
    char* Nome_do_Arquivo_de_Entrada;
    if(argc == 3) Nome_do_Arquivo_de_Entrada = argv[2];
    if(argc > 3) throw Muitos_Argumentos{argc};
    if(argc < 3) throw Poucos_Argumentos{argc};

    FILE *Arquivo_de_Entrada;
    Arquivo_de_Entrada = fopen(Nome_do_Arquivo_de_Entrada,"r");
    if(Arquivo_de_Entrada == NULL)throw Arquivo_Invalido{Nome_do_Arquivo_de_Entrada};

    return Arquivo_de_Entrada;
}

string Retorna_Funcao(string* Entrada, int *i){
    /*Simplesmente retorna uma string de uma palavra que representa a operação que tem que ser realizada*/
    string Funcao;
    while(((*Entrada)[*i] != '\0') && ((*Entrada)[*i] != '\n') && ((*Entrada)[*i] != ' ')){
        Funcao = Funcao + (*Entrada)[*i];
        (*i)++;
    }
    (*i)++;
    return Funcao;
}

int Conta_Tamanho_Entrada(string Expressao){
    int Retorno = 0;
    /*Serve para contar o tamanho de forma bem simples*/
    while(Expressao[Retorno]!='\0'){
        Retorno++;
    }
    /*A string de fato tem tamanho Retorno pois ele começa no 0 mas a ultima vez q foi usado representava a casa do '\0 na string*/
    return (Retorno);
}


bool Expressao_Valida(string Tipo_da_Expressao,string Expressao){

    /*Tamanho limite definido*/
    if(Conta_Tamanho_Entrada(Expressao)>1020)return false;
    /*Análise para a expressão posfixa*/
    if(Tipo_da_Expressao == "POSFIXA"){
            /* Por ser uma pilha a expressão vai estar ao contrário*/
            Pilha<string> Auxiliar;
            Montar_Pilha_De_String(Expressao,&Auxiliar);

        string Analise;

        int Quantidade_de_Numeros = 0;
        int Quantidade_de_Operadores = 0;
        int Quantidade_de_Pontos = 0;
        int Quantidade_de_Vezes = 0;
        int i = 0;

        /*Para cada elemento da expressão o código dentro desse if vai percorrer cada char e se ele não for um algorismo ou
        um operador vai retornar false. */
        while(!Auxiliar.Pilha_Vazia()){
            /*Como confirmamos antes que a Pilha não vai estar vazia não precisamos do try nesse desempilha*/
            Analise = Auxiliar.Desempilha();
            Quantidade_de_Vezes++;
            i = 0;
            Quantidade_de_Pontos = 0;

            while (Analise[i] != '\0'){
                /*Cada número não pode ter mais que um '.' pois isso seria inválido. Se o '.' estiver na primeira vaga do número
                 a expressão também é inválida */
                if(Analise[i] == '.'){
                    Quantidade_de_Pontos++;
                    if(i == 0) return false;
                }
                /*Nenhum char pode ser diferente desses*/
                if((((Analise[i] < '0')||(Analise[i] > '9'))&&(Analise[i] != '+')&&(Analise[i] != '-')&&(Analise[i] != '*')&&(Analise[i] != '/')&&(Analise[i] != '.'))||(Quantidade_de_Pontos > 1)){
                    return false;
                }
                /*Um numero não pode conter um char diferente desses apresentados. Um número pode começar com '-', sendo um número negativo, logo ele está incluso aqui*/
                if(((Analise[0] >= '0')&&(Analise[0] <= '9'))||((Analise[0] == '-')&&(Analise[1] != '\0'))){
                    if(i>0){
                        if(((Analise[i] < '0')||(Analise[i] > '9'))&&(Analise[i] != '.'))return false;
                    }
                }
                /*Um operador não pode conter nada alem do operador*/
                if((Analise[0] == '+')||(Analise[0] == '*')||((Analise[0] == '-')&&(Analise[1] == '\0'))||(Analise[0] == '/')){
                    if(i>0){
                        if((Analise[i] != '\0')&&(Analise[i] != ' ')&&(Analise[i] != '\n')) return false;
                    }
                }
                i++;
            }

            //Fazendo as contagens
            if(((Analise[0] >= '0')&&(Analise[0] <= '9'))||((Analise[0] == '-')&&(Analise[1] != '\0'))) Quantidade_de_Numeros++;
            if((Analise[0] == '+')||((Analise[0] == '-')&&(Analise[1] == '\0'))||(Analise[0] == '*')||(Analise[0] == '/'))Quantidade_de_Operadores++;
            /*A quantidade de numeros menos a quantidade de operadores ao longo do código tem que ser igual ou menor que dois, pois se nao faltariam
            operadores para os numeros, tornando a expressão inválida. */
            if(Quantidade_de_Numeros - Quantidade_de_Operadores > 2)return false;
            /*O ultimo elemento da expressão não pode ser um numero*/
            if((Quantidade_de_Vezes == 1)&&(((Analise[0] >= '0')&&(Analise[0] <= '9'))||((Analise[0] == '-')&&(Analise[1] != '\0'))))return false;
        }
        /*A expressão não faz sentido se não tiver um operador a menos do que a quantidade de números*/
        if(Quantidade_de_Numeros == (Quantidade_de_Operadores+1)){
            return true;
        }
        else{
            return false;
        }
    }

    /*Análise para a expressão infixa*/
    else{
        if(Tipo_da_Expressao == "INFIXA"){
            Pilha<string> Auxiliar;
            /* Por ser uma pilha a expressão vai estar ao contrário*/
            Montar_Pilha_De_String(Expressao,&Auxiliar);

            string Analise;
            string Proximo = "";

            int Quantidade_de_Numeros = 0;
            int Quantidade_de_Operadores = 0;
            int Quantidade_Parenteses_Abrem = 0; //'('
            int Quantidade_Parenteses_Fecham= 0;//')'
            int Quantidade_de_Pontos = 0;
            int i = 0;


            while(!Auxiliar.Pilha_Vazia()){
                /*Como confirmamos antes que a Pilha não vai estar vazia não precisamos do try nesse desempilha*/
                Analise = Auxiliar.Desempilha();
                i = 0;
                Quantidade_de_Pontos = 0;

                /**/
                while (Analise[i] != '\0'){

                    /*Cada número não pode ter mais que um '.' pois isso seria inválido. Se o '.' estiver na primeira vaga do número
                    a expressão também é inválida */
                    if(Analise[i] == '.'){
                        Quantidade_de_Pontos++;
                        if(i == 0) return false;
                    }                        
                    /*Nenhum char pode ser diferente desses*/
                    if((((Analise[i] < '0')||(Analise[i] > '9'))&&(Analise[i] != '+')&&(Analise[i] != '-')&&(Analise[i] != '*')&&(Analise[i] != '/')&&(Analise[i] != '.')&&(Analise[i] != ')')&&(Analise[i] != '('))||(Quantidade_de_Pontos > 1)){
                        return false;
                    }
                    /*Um numero não pode conter um char diferente desses apresentados. Um número pode começar com -, sendo um número negativo, logo ele está incluso aqui*/
                    if(((Analise[0] >= '0')&&(Analise[0] <= '9'))||((Analise[0] == '-')&&(Analise[1] != '\0'))){
                        if(i>0){
                            if(((Analise[i] < '0')||(Analise[i] > '9'))&&(Analise[i] != '.')) return false;
                        }
                    }
                    /*Um operador não pode conter nada alem do operador*/
                    if((Analise[0] == '+')||(Analise[0] == '*')||((Analise[0] == '-')&&(Analise[1] == '\0'))||(Analise[0] == '/')){
                        if(i>0){
                            if((Analise[i] != '\0')&&(Analise[i] != ' ')&&(Analise[i] != '\n')) return false;
                        }
                }
                        i++;
                }
                //Fazendo as contagens
                if(((Analise[0] >= '0')&&(Analise[0] <= '9'))||((Analise[0] == '-')&&(Analise[1] != '\0'))) Quantidade_de_Numeros++;
                if((Analise[0] == '+')||((Analise[0] == '-')&&(Analise[1] == '\0'))||(Analise[0] == '*')||(Analise[0] == '/'))Quantidade_de_Operadores++;
                if(Proximo[0] == '(') Quantidade_Parenteses_Abrem++;
                if(Analise[0] == ')')Quantidade_Parenteses_Fecham++;

                /*Se o "Proximo" for "" significa que ele o "Analise" ainda é o primeiro elemento da pilha, ou seja, o ultimo elemento da expressão*/
                if(Proximo != ""){
                    /*Se um elemento for um numero o proximo não pode ser um numero, pois é necessário um operador entre os dois e nem o '(' pois também é necessário 
                    um operador entre eles*/
                    if(((Analise[0] >= '0')&&(Analise[0] <= '9'))||((Analise[0] == '-')&&(Analise[1] != '\0'))){
                        if(((Proximo[0] >= '0')&&(Proximo[0] <= '9'))||((Proximo[0] == '-')&&(Proximo[1] != '\0'))||(Proximo[0]=='('))return false;
                    }
                    /*Se um elemento for um operador o proximo não pode ser um operador, pois é necessário um número entre os dois e nem o ')' pois também é necessário 
                    um numero entre eles*/
                    if((Analise[0] == '+')||((Analise[0] == '-')&&(Analise[1] == '\0'))||(Analise[0] == '*')||(Analise[0] == '/')){
                        if(((Proximo[0] == '+')||((Proximo[0] == '-')&&(Proximo[1] == '\0'))||(Proximo[0] == '*')||(Proximo[0] == '/'))||(Proximo[0] == ')'))return false;
                    }
                    /*Se um elemento for um '(' o proximo não pode ser um operador, pois é necessário um número entre os dois e nem o ')' pois também é necessário pelo menos
                    um numero entre eles*/
                    if(Proximo[0] == '('){
                        if(((Proximo[0] == '+')||((Proximo[0] == '-')&&(Proximo[1] == '\0'))||(Proximo[0] == '*')||(Proximo[0] == '/'))||(Proximo[0] == ')'))return false;
                    }
                    /*Se um elemento for um ')' o proximo não pode ser um numero, pois é necessário um operador entre os dois e nem o '(' pois também é necessário 
                    um operador entre eles*/
                    if(Analise[0] == ')'){
                        if(((Proximo[0] >= '0')&&(Proximo[0] <= '9'))||((Proximo[0] == '-')&&(Proximo[1] != '\0'))||(Proximo[0]=='('))return false;
                    }
                }
                /* Se a qualquer momento na análise tiver mais parenteses que fecham do que abrem a expressão obviamente não é válida*/
                if(Quantidade_Parenteses_Fecham<Quantidade_Parenteses_Abrem)return false;
                /* Por a pilha ir desempilhando a expressão ao contrario ao final da iteração a string que estava no "Analise" vem depois na expressão
                do que o próximo element a ser desempilhado, logo podemos fazer essa atribuição*/
                Proximo = Analise;

            }
            if(Quantidade_Parenteses_Abrem != Quantidade_Parenteses_Fecham) return false;
            if(Quantidade_de_Numeros == (Quantidade_de_Operadores+1)){
                return true;
            }
            else{
                return false;          
            }
        }
        
        else{
            cout<<"ERRO: Não existe uma expressão do tipo \'"<<Tipo_da_Expressao<<"\'"<<endl;
            return false;
        }
    }
}

bool Armazenar(Arvore* Armazenamento,string Expressao,string Tipo_da_Expressao){

    /*Transforma o Tipo_da_Expressao em um valor booleano q simplesmente chama o Arvore::Montar_Arvore para
    fazer todo o armazenamento*/
    bool Infixa; 
    if(Tipo_da_Expressao == "POSFIXA")Infixa = false;
    if(Tipo_da_Expressao == "INFIXA")Infixa = true;

    return Armazenamento->Montar_Arvore(Expressao,Infixa);
}

bool Ler_Expressao(int i,string Entrada,Arvore* Armazenamento){
    if(!Armazenamento->Arvore_Vazia()) Armazenamento->Limpar_Arvore();
    string Tipo_da_Expressao;
    /*Esse while serve para retornar o tipo da expressão de entrada que no caso pode ser posfixo ou infixo*/
    while((Entrada[i] != '\0') && (Entrada[i] != ' ')){
        Tipo_da_Expressao = Tipo_da_Expressao + Entrada[i];
        i++;
    }
    string Expressao;
    /*Esse while serve para retornar a expressão de entrada */
    while((Entrada[i] != '\0') && (Entrada[i] != '\n')){
        Expressao = Expressao + Entrada[i];
        i++;
    }    
    if(Expressao_Valida(Tipo_da_Expressao,Expressao)){
        if(Armazenar(Armazenamento,Expressao,Tipo_da_Expressao)){
            cout<<"EXPRESSAO OK: \""<<Expressao<< "\""<< endl;
            return true;
        }
        else{
            cout<<"ERRO: \""<<Expressao<< "\" NAO VALIDA"<<endl;
            return false;
        }
    }
    else{
        cout<<"ERRO: \""<<Expressao<< "\" NAO VALIDA"<<endl;
        return false;

    }
}

void Retornar_Posfixa(bool Expressao_Valida,Arvore* Armazenamento){
    if(Expressao_Valida){
        if(!(Armazenamento->Arvore_Vazia())){
            cout<<"POSFIXA: "<<Armazenamento->Retorna_Posfixa()<<endl;
        }
        else{
            cout<<"ERRO: Ainda não foi fornecido nenhuma expressão para ser armazenada"<<endl;
        }
    }
    else{
        cout<<"ERRO: Ultima expressão fornecida era inválida, logo não é possível retornar a expressão posfixa"<<endl;
        }
}

void Retornar_Infixa(bool Expressao_Valida,Arvore* Armazenamento){
    if(Expressao_Valida){
        if(!(Armazenamento->Arvore_Vazia())){
            cout<<"INFIXA: ( "<<Armazenamento->Retorna_Infixa()<<" )"<<endl;
        }
        else{
            cout<<"ERRO: Ainda não foi fornecido nenhuma expressão para ser armazenada"<<endl;
        }
    }
    else{
        cout<<"ERRO: Ultima expressão fornecida era inválida, logo não é possível retornar a expressão infixa"<<endl;
        }
}

void Retornar_Resultado(bool Expressao_Valida,Arvore* Armazenamento){
    if(Expressao_Valida){
        if(!(Armazenamento->Arvore_Vazia())){
            bool Auxiliar = true;
            double Resultado;
            try{
                Resultado = Armazenamento->Retorna_Resultado();
            }
            catch(Divisão_Por_Zero Invalido){
                cout<<Invalido.Printar<<endl;
                Auxiliar = false;
            }
            if(Auxiliar) cout<<setprecision(6)<<"VAL: "<<Resultado<<endl;
        }
        else{
            cout<<"ERRO: Ainda não foi fornecido nenhuma expressão para ser armazenada"<<endl;
        }
    }
    else{
        cout<<"ERRO: Ultima expressão fornecida era inválida, logo não é possível retornar o resultado"<<endl;
        }
}