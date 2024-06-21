#include <iostream>
#include <vector>

using namespace std;



void read_mat(vector<vector<int>> & x, int size_line, int size_colum)
{
    for(int i = 0; i <size_line; i++)
    {
        for (int j = 0; j <size_colum;j++)
        {
            cin>> x[i][j];
        }
    }
}

void print_mat (vector<vector<int>> x, int size_line, int size_colum)
{
    for(int i = 0; i <size_line; i++)
    {
        for (int j = 0; j <size_colum;j++)
        {
            cout<<x[i][j]<<" ";
        }
        cout<<endl;
    }
}

void mult(vector<vector<int>> x, vector<vector<int>> y ,vector<vector<int>> & saida, int size, int size_line1,int size_colum2)
{
    for(int i = 0; i <size_line1; i++)
    {
        for (int j = 0; j <size_colum2;j++)
        {
            for (int k = 0; k <size;k++)
            {
                saida[i][j] += x[i][k] * y[k][j];
            }
        }
    }
}

int main ()
{
    int i,k,j;
    cin>>i>>k>>j;

    vector<vector<int>> Matriz1(i, vector<int>(k));
    read_mat(Matriz1,i, k);
    vector<vector<int>> Matriz2(k, vector<int>(j));
    read_mat(Matriz2,k, j);
    print_mat(Matriz1,i, k);
    print_mat(Matriz2,k, j);


    vector<vector<int>> saida(i, vector<int>(j));
    mult(Matriz1,Matriz2 ,saida,k,i,j);
    print_mat(saida,i,j);

    return 0;
}






