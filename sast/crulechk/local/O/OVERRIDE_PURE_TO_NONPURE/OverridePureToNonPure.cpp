//@checker OVERRIDE_PURE_TO_NON_PURE
class A
{
	public :
	virtual void foo () = 0; 
	virtual void bar () = 0; 
	
};

class A2
{
	virtual void foo () = 0;
	virtual void bar ()
	{
		
	}
};

class A1 : public A
{
	public :
	virtual void foo () = 0; 
	
	
};



class B : public A1, public A2
{
	public :
	virtual void foo ()
	{
		
	}
	
	
};

class C : public B
{
	public:
	virtual void foo () = 0; //@violation OVERRIDE_PURE_TO_NON_PURE
	virtual void bar () = 0; //@violation OVERRIDE_PURE_TO_NON_PURE
};
