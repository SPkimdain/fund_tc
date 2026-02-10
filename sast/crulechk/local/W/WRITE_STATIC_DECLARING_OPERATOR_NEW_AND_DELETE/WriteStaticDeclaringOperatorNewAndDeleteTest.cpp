//@checker WRITE_STATIC_DECLARING_OPERATOR_NEW_AND_DELETE

#include <iostream>

using namespace std;

class OPNew
{
public:
	void* operator new( size_t size ) //@violation WRITE_STATIC_DECLARING_OPERATOR_NEW_AND_DELETE
	{
		cout << "OPNew::new" << endl;
		void* adr = new char[size];
		return adr;
	}

	static void operator delete( void* adr ) throw()
	{
		cout << "OPNew:delete" << endl;
		delete[]( ( char * )adr );
	}
};


int main()
{
	OPNew *opn = new OPNew;
	delete opn;
}
