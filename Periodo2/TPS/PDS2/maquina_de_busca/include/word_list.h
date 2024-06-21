#ifndef WORD_LIST
#define WORD_LIST

#include <bits/stdc++.h>

using namespace std;

//Retorna os documentos dentro do arquivo
bool arch(set<string>& entrance_files);

//Palavra pesquisada é inválida
struct invalidWord
{
    vector<string> word;
};

//Retorna um map com letras sem acento
map<char,char> specialWord();

//Normaliza a palavras
void normalizeWords(string *entrance);

class WordList{
    public:

        //Construtor
        WordList(set<string> files);

        // Retorna um vector com os arquivos que contém essa palavra pesquisada
        vector<string> find_files(set<string> entrance);


    private:

        //Le os arquivos e grava as palavras em um map
        void read_files(set<string> files);

        // Retorna os arquivos em que está presente a palavra
        void organize_words_files();   

        //Um map em que armazena a palavra como chave e a lista de arquivos que ela aparece
        map<string,set<string>> words_;
        set<string> files;
};

#endif