//@checker OVERRIDE_ALL_OVERLOADS_OF_BASE_CLASS

class Base 
{ 
public: 
	virtual void check( short x ) {}

	virtual void foo( short x ) {} 
	virtual void foo( double x ) {}
	virtual void foo( char x, 
		char y ) {}

	virtual void doIt( short x ) {}
	virtual void doIt( double x ) {}
}; 


class Derived : public Base //@violation OVERRIDE_ALL_OVERLOADS_OF_BASE_CLASS
{ 
public: 
	virtual void foo( short ) {}
    void bar() 
    { 
        foo( 0.1 ); // calls Derived::foo( short )! 
    }
}; 

class NestedDerived : public Base
{
public:
	virtual void car( short ) {}
	virtual void car( double ) {}
};

class NestedDerived2 : public NestedDerived //@violation OVERRIDE_ALL_OVERLOADS_OF_BASE_CLASS
{
public:
	virtual void foo( short ) {}
	virtual void foo( double ) {}
	virtual void foo( char, char ) {}
	virtual void car( short ) {}
	void bar2()
	{
		foo( 0.2 );
		car( 0.5 );
	}
};

class NestedDerived3 : public NestedDerived2  //@violation OVERRIDE_ALL_OVERLOADS_OF_BASE_CLASS
{
	virtual void foo( short ) {}
	void bar3()
	{
	}
};

class NestedDerived4 : public NestedDerived
{
public:
	using NestedDerived::foo;
	using NestedDerived::car;
	void bar4()
	{
		foo( 0.3 );
		car( 0.5 );
	}
};

void OAOOBC_001_function()
{
	Derived d;
	d.bar();
}
