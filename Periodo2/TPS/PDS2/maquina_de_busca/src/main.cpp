#include <bits/stdc++.h>
#include "../include/word_list.h"

using namespace std;


int main(){

    set<string> entrance_files;
    arch(entrance_files);
    WordList Words_files(entrance_files);

    while(true){

        string help;
        cout<<endl<<"Digite o 'pesquisar' para realizar a pesquisa ou 'sair' para parar o programa seguidos da tecla enter:"<<endl;
        cin>>help;
        getchar();
        normalizeWords(&help);
        if(help == "sair"){
            cout<<"Programa finalizado!"<<endl;
            break;
        }else{
            if(help == "pesquisar"){
                cout<<"Digite o conjunto de palavras:"<<endl;
                set<string> entrance;
                string word,aux;
                getline(cin,aux);
                stringstream sentence(aux);
                while(getline(sentence,word,' ')){
                    normalizeWords(&word);
                    entrance.insert(word);
                }
                if(entrance.find("") != entrance.end()) entrance.erase(entrance.find(""));
                if(entrance.empty()){
                    cout<<"Pesquisa inválida, necessário letras do alfabeto ou números!"<<endl;
                }
                else{
                    vector<string> Files_exit;
                    try {
                        Files_exit = Words_files.find_files(entrance);
                    } catch(invalidWord exception) 
                        {
                            for(auto it=exception.word.begin();it!=exception.word.end();it++){
                                    cout <<"Palavra \"" << *it <<"\" não aparece nos arquivos"<<endl; 
                                }
                        }
                    if(!Files_exit.empty()) cout<<"Os seguintes arquivos possuem a(s) palavra(s) pesquisada(s):"<<endl;
                    for(int i=0; i<Files_exit.size();i++){
                        cout<<Files_exit[i]<<endl;
                    }
                }

            }else cout<<"Palavra chave inválida"<<endl;
        }
    }
    
    return 0;
}