//@checker DO_NOT_USE_REGISTER

#include <vector>

int main()
{
	using std::vector;
	
	int x = 0;

	vector<unsigned int> vectors;
	vectors.clear();
	vectors.push_back( 1 );
	
	//standard C++ 11
	//auto iter = vectors.begin();

	//non standard C++ 11

	register int intVal2; // @violation DO_NOT_USE_REGISTER
	
	return 1;
}

