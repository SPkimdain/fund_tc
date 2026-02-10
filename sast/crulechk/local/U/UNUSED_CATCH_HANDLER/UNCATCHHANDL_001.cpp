//@checker UNUSED_CATCH_HANDLER

class FedNotExist 
{
	public:
	int e1;
};

class FedJoined
{
	public:
	int j1;
};

class Exception
{
	public:
	int x1;
};


void testRun(int a, int b,  int c)
{
	
	
	try
	{
		if( a > 5)
		{
			throw FedNotExist();
		}
		
		if( b> 5)
		{
			
		}
		
		if( c> 5)
		{
			throw Exception();
		}
	}
	catch(FedNotExist & e)
	{
		e.e1 = 1;
	}
	catch(FedJoined & e) //@violation UNUSED_CATCH_HANDLER
	{
		e.j1 = 1;
	}
	catch(Exception & e)
	{
		e.x1 = 1;
	}
	catch(...)
	{
		
	}
}


void test ()
{
	

}
