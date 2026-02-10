//@checker DO_NOT_USE_C_STYLE_CASTING

class Base 
{
public:
	virtual void foo() { int x = 0; }
};

class Derived : public Base
{
public:
	virtual void foo() { long x = 0; }
};

typedef void (*FuncPtr) ();

int doSomething()
{
	return 10;
}


int main()
{
	int x = 10;
	long yyyyyy = 5;
	const int* pcx = &x;
	int z = 0;
	int* pz = 0;

	z = ( int ) ( yyyyyy ); // @violation DO_NOT_USE_C_STYLE_CASTING
	z = static_cast<int>( yyyyyy );
	
	pz = ( int * ) pcx; // @violation DO_NOT_USE_C_STYLE_CASTING
	pz = const_cast<int *>( pcx );

	Base *b = 0;
	Derived d;
	Derived *pd = &d;
	void *v;
	
	b = ( Base * ) pd; // @violation DO_NOT_USE_C_STYLE_CASTING
	b = dynamic_cast<Base *>( pd );
	
	Base& bb = (Base&) *pd; // @violation DO_NOT_USE_C_STYLE_CASTING
	Base& bbb = dynamic_cast<Base&>( *pd ); 

	v = ( void * ) pd; // @violation DO_NOT_USE_C_STYLE_CASTING
	v = dynamic_cast<void *>( pd );
	
	FuncPtr funcPtrArray[10];
	
	funcPtrArray[0] = (FuncPtr) &doSomething; // @violation DO_NOT_USE_C_STYLE_CASTING
	funcPtrArray[1] = reinterpret_cast<FuncPtr>( &doSomething );

}
