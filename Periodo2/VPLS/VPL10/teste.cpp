#include <bits/stdc++.h>

using namespace std;

int main()
{
    int* x = new int;
    int*y = x;

    delete[] y;
}