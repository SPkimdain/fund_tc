//@checker MUST_CATCH_ALL_EXCEPTION_IN_DTOR

typedef float MYTYPE;

void zoo() throw (int){
	throw 10;
}
void bar() throw(float){
	throw 1.0f;
}
void baz() throw(MYTYPE){
	throw 1.0f;
}
void foo()
{
}

//TODO class type
class C{
public:
	~C();
	void mfunction1() throw(int);
	void mfunction2();
private:
	bool b;
};



C::~C(){
	if(b){
		throw int();	//@violation	MUST_CATCH_ALL_EXCEPTION_IN_DTOR
	}
	C a;
	a.mfunction1();	//@violation	MUST_CATCH_ALL_EXCEPTION_IN_DTOR
	a.mfunction2();

	C* b;
	b->mfunction1();	//@violation	MUST_CATCH_ALL_EXCEPTION_IN_DTOR
	b->mfunction2();
	foo();
	zoo();	//@violation	MUST_CATCH_ALL_EXCEPTION_IN_DTOR
	try{
		bar();
		zoo();	//@violation	MUST_CATCH_ALL_EXCEPTION_IN_DTOR
	}
	catch(float e)
	{
	}
	
	try{
		baz(); 
		bar();
		zoo();	//@violation	MUST_CATCH_ALL_EXCEPTION_IN_DTOR
	}
	catch(MYTYPE e)
	{
	}
	
	

	try{
		bar();
		zoo();
	}
	catch(float e)
	{
	}
	catch(...)
	{
	}
}