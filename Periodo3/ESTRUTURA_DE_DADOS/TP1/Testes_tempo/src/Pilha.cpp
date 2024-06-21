#include <iostream>

#include <../include/Pilha.hpp>

using namespace std;


void Montar_Pilha_De_String(string Entrada,Pilha<string>* Retorno){
    int i = 0;
    if (Entrada[i] == ' ') i++;
    string Auxiliar = "";

    while(Entrada[i] != '\0'){
        //Loop para ir dividindo a expressão pelos espaços
        while((Entrada[i] != '\0') && (Entrada[i] != ' ')){
            Auxiliar = Auxiliar + Entrada[i];
            i++;
        }
        //Empilhando os elementos da expressão
        Retorno->Empilha(Auxiliar);
        Auxiliar = "";
        if(Entrada[i] != '\0'){
            while(Entrada[i] == ' '){
                i++;
            }
        }
    }
}
