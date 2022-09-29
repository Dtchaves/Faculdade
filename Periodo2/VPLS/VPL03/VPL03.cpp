#include <iostream>
#include <map>
#include <string>

using namespace std;


int main()
{
    map<int,string>entrada;
    string aux = "start";
    int i = 0,j=1,final=-1,contador = 0;

    //while ( aux[aux.size()-1] != '.' )
    while (cin >> aux)
    {
       // cin >> aux;
        entrada[i] = aux; 
        i++;
    }

    //entrada[entrada.size()-1].erase(aux.size()-1,1); 

    for (auto help:entrada)
    {
        if(help.second != "") 
        {
            for(i = j;i<entrada.size();i++)
            {
                if(help.second == entrada[i])
                {
                    entrada[i] = "";
                    contador ++;
                }
            }
            j++;
            if (contador > final)
            {
                aux = help.second;
                final = contador;
            }
            contador = 0;
        }
    }

        cout << aux <<endl;

    
    return 0;
}