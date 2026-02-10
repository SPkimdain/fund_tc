//@checker EXPLICIT_RETURN_IN_DTOR_CATCH

class A
{
public:
	void f();
	
	virtual void foo();
	A() {};
    ~A()
	{
        try
        {
            
		    int a = (int)1.0f;
		    
        }
        catch(...)
        {

            return;
        }
		
	}
};



class B 
{ 
public:
	void f();
	
	virtual void foo();
	B() {};
    ~B()
	{
        try
        {
            
		    int a = (int)1.0f;
		    
        }
        catch(...) //@violation EXPLICIT_RETURN_IN_DTOR_CATCH
        {

        }
		
	}
};