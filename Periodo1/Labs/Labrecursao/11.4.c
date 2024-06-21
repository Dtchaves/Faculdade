#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tira(char *str, int tamanho,char c){
    int i,j;
    
    for(i = 0;i<tamanho;i++){
        if (str[i] == c){
            for(j = i;j<tamanho-1;j++){
                str[j] = str[j+1];
            }
            str[tamanho - 1] = '\0';
            tamanho--;
            i--;
        }
    }
    


}


int main () {
    char str[100],caracter;
    
    scanf("%s",str);
    getchar();
    scanf("%c",&caracter);
    
    tira(str,strlen(str),caracter);
    
    fputs(str,stdout);
    
    
return 0;
}