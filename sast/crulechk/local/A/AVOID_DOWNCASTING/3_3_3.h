
class A
{ 
public:
	virtual void bar() 
	{ 
		//cout << "a::bar" << endl; 
	}
	
	virtual ~A() {}
}; 
class B : public A 
{ 
public:
	virtual void bar() 
	{ 
		//cout << "b::bar" << endl; 
	}
	virtual void foo() 
	{ 
		//cout << "b::foo" << endl;
	}
	void car( int a )
	{
	}

	int x;
}; 

class C
{
};
