//@checker ONLY_MAIN_IN_GLOBAL_SCOPE


namespace
{
	void f3(int a);
	void f2(int);
	int x2;	
}

int x1; //@violation ONLY_MAIN_IN_GLOBAL_SCOPE
void f1(int); //@violation ONLY_MAIN_IN_GLOBAL_SCOPE



namespace MYAPI
{
	void b2(int);
	int x2;	
}


int main()
{
	
}