#include <vector>

using namespace std;

void II_001_function() {
	vector<int> V;
	V.push_back(1);
	vector<int>::iterator I = V.begin();
	V.push_back(2);
	int b = *I;   //@violation INVALID_ITERATOR
}

