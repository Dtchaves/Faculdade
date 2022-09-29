#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> x(2,3);
    x.push_back(4);
    vector<int>::iterator it;
    it=x.begin();
    cout<<*it<<endl;
    it=x.end()--;
    cout<<*it<<endl;
    it--;
    cout<<*it<<endl;

    string teste = "teste";
    string tes = "teste";
    if(teste == tes)
    {
        cout<<"certo";
    }


}