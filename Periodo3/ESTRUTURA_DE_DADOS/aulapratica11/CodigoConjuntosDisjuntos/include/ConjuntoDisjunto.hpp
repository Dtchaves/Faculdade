#include <iostream>

using namespace std;

class ConjuntoDisjunto {
private:
	long size_max = 2000;
	long* rank;
	long* parent;

public:
	ConjuntoDisjunto();
	~ConjuntoDisjunto();
	void makeSet(long x);
	void unionSet(long x, long y);
	long findSet(long x);
};
