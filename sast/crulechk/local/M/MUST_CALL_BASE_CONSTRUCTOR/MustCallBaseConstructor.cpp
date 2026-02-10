//@checker MUST_CALL_BASE_CONSTRUCTOR
class A
{
	public :
	A ()
	{
		
	}
	
};

class B : public A
{
	public:
	B() //@violation MUST_CALL_BASE_CONSTRUCTOR
	{
		
	}
};


class C : public B
{
	public:
	C() : B()
	{
		
	}
};




class V
{
	public : 
	V()
	{
		
	}
	V(int i)
	{
		
	}
};

class C1 : public virtual V
{
	public :
	C1() : V(21)
	{
		
	}
};

class C2 : public virtual V
{
	public :
	C2() : V(42)
	{
		
	}
};



class D : public C1, public C2
{
	public :
	D() //@violation MUST_CALL_BASE_CONSTRUCTOR
	{
		
	}
};


	