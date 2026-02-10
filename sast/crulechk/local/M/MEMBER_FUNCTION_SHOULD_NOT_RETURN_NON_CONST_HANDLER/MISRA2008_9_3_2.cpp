//@checker MEMBER_FUNCTION_SHOULD_NOT_RETURN_NON_CONST_HANDLER

//misra 9-3-2 예제 1
class MISRA2008_9_3_2___C
{
public:
	int &getA()
	{
		return a;   //Non-compliant //@violation MEMBER_FUNCTION_SHOULD_NOT_RETURN_NON_CONST_HANDLER
	}

private:
	int a;

};


void MISRA2008_9_3_2___b(MISRA2008_9_3_2___C &c)
{
	int &a_ref = c.getA();
	a_ref = 10;
}




//misra 9-3-2 예제 2
class misra2008_9_3_2___D
{
public:
	misra2008_9_3_2___D(int *shared) : m_shared(shared)
	{

	}
	int *getD()
	{
		return m_shared;  //compliant 
	}
private:
	int *m_shared;
};




//예제 3
class MISRA2008_9_3_2___E
{
public:
	int &getA()    
	{
		int d;

		if(1)
		{
			return a;   //Non-compliant //@violation MEMBER_FUNCTION_SHOULD_NOT_RETURN_NON_CONST_HANDLER
		}
		else
		{
			return d;
		}
	}

   int getB()   
   {
	
		return b;
   }

   int getC()
   {
		int c;

		return c;
   }

   int &getD()
   {
		return e;    //Non-compliant //@violation MEMBER_FUNCTION_SHOULD_NOT_RETURN_NON_CONST_HANDLER
   }

private:
	int a;
	int b;
	int e;
};






