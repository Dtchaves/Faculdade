#include <../include/hash.hpp>

/*CLASS elemento_hash*/
elemento_hash_leitura::elemento_hash_leitura(){
    primeiro = NULL;
}
bool elemento_hash_leitura::vazio(){
    return (primeiro == NULL);
}
bool elemento_hash_leitura::procura_incrementa(string p){
    if(!vazio()){
        tipo_item_leitura* aux = primeiro;
        while(aux != NULL){
            /*Se achar a palavra incrementa e retorna 1, retorna 0 caso contrário*/
            if(aux->item.palavra == p){
                aux->item.ocorrencia++;
                return 1;
            }
            aux = aux->prox;
        }
    }
    return 0;
}
void elemento_hash_leitura::insere(string item){
    tipo_item_leitura* novo = new tipo_item_leitura;
    novo->item.palavra = item;
    novo->item.ocorrencia = 1;
    /*Sempre adiciona no início*/
    if(vazio()){
        novo->prox = NULL;
        primeiro = novo;
    }
    else{
        novo->prox = primeiro;
        primeiro = novo;
    }
}
palavra_ocorrencia elemento_hash_leitura::remove(){
    palavra_ocorrencia retorno;
    retorno.ocorrencia = 0;
    retorno.palavra = '\0';

    /*Com tratamento de erro caso a esteja vazio o elemento a função remove um elemento do inicio*/
    if(vazio()){
        cerr<<"ERRO vazio"<<endl;
    }
    else{
        tipo_item_leitura* aux = primeiro;
        primeiro = primeiro->prox;
        retorno = aux->item;
        delete aux;        
    }
    return retorno;

}
void elemento_hash_leitura::limpa(){

    while(!vazio()){
        remove();
    }
}
elemento_hash_leitura::~elemento_hash_leitura(){
    limpa();
}

/*OUTRA CLASSE*/

elemento_hash_escrita::elemento_hash_escrita(){
    primeiro = NULL;
}
bool elemento_hash_escrita::vazio(){
    return (primeiro == NULL);
}
dicionario elemento_hash_escrita::procura_cod(long long int cod){
    if(!vazio()){
        tipo_item_escrita* aux = primeiro;
        /*Retorna o dicionario com o codigo*/
        while(aux != NULL){
            if(aux->item.codigo == cod){
                return aux->item;
            }
            aux = aux->prox;
        }
    }
}
dicionario elemento_hash_escrita::procura_palavra(string palavra){
    if(!vazio()){
        tipo_item_escrita* aux = primeiro;
        /*Retorna o dicionario com a palavra*/
        while(aux != NULL){
            if(aux->item.palavra == palavra){
                return aux->item;
            }
            aux = aux->prox;
        }
    }
}
void elemento_hash_escrita::insere(dicionario entrada){
    tipo_item_escrita* novo = new tipo_item_escrita;
    novo->item = entrada;
    /*Sempre adiciona no início*/
    if(vazio()){
        novo->prox = NULL;
        primeiro = novo;
    }
    else{
        novo->prox = primeiro;
        primeiro = novo;
    }
}
void elemento_hash_escrita::remove(){
    /*Sempre remove no início, com tratamento de erros necessários*/
    if(vazio()){
        cerr<<"ERRO vazio"<<endl;
    }
    else{
        tipo_item_escrita* aux = primeiro;
        primeiro = primeiro->prox;
        delete aux;        
    }
    return;

}
void elemento_hash_escrita::limpa(){

    while(!vazio()){
        remove();
    }
}
elemento_hash_escrita::~elemento_hash_escrita(){
    limpa();
}


