#include <../include/ConjuntoDisjunto.hpp>

	
ConjuntoDisjunto::ConjuntoDisjunto(){
    parent = new long[size_max];
    rank = new long[size_max];

    for(int i = 0; i < size_max; i++) {
        parent[i] = i; 
        rank[i] = 0;
    }
}
ConjuntoDisjunto::~ConjuntoDisjunto(){
    delete[] parent;
    delete[] rank;
}

void ConjuntoDisjunto::makeSet(long x){
    parent[x] = x;
    rank[x] = 0;
}
void ConjuntoDisjunto::unionSet(long x, long y){
    long rootX = findSet(x);
    long rootY = findSet(y);

    if (rootX == rootY) {
        return;
    }

    if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
    } else if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else {
        parent[rootX] = rootY;
        rank[rootY]++;
    }
}

long ConjuntoDisjunto::findSet(long x){
    if (x != parent[x]) {
        parent[x] = findSet(parent[x]);
    }
    return parent[x];
}

