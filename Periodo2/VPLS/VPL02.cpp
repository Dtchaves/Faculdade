#include <iostream>
#include <string>

using namespace std;

int analisar(string lida, char letra)
{
    int i,contador = 0;

    for(i = 0; i<lida.size();i++)
    {
        if(lida[i]==letra)
        {
            contador++;
        }
    }

    return contador;
}


int main ()
{
    string entrada;
        cin>>entrada;
    string vogais = {"aeiou"};
    int j,x;

    for(j = 0;j<vogais.size();j++)
    {
        x = analisar(entrada, vogais[j]);
        if (x)
        {
            cout<<vogais[j]<<' '<<x<<endl;
        }

    }

    return 0;
}

