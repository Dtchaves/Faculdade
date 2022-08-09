#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int aparece(char *str, int tamanho,char c){
    int i,contador = 0;
    i = tamanho - 1;
    
    if (str[i] == c){
        contador++;
    }
    
    if (i == 0){
        return contador;
    }
    
        else {
            return contador + aparece(str,i,c);
            
        }
    
    
}


int main () {
    char str[100],caracter;
    
    scanf("%s",str);
    getchar();
    scanf("%c",&caracter);
    
    printf("%i",aparece(str,strlen(str),caracter));
    
    
return 0;
}