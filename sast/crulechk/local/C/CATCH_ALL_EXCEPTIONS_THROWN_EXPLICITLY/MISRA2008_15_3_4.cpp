//@checker CATCH_ALL_EXCEPTIONS_THROWN_EXPLICITLY


class MISRA_15_3_4___A {};
class MISRA_15_3_4___B {};



void MISRA_15_3_4___f(int i) throw()
{
	try
	{
		if (i > 10)
		{
			throw MISRA_15_3_4___A();  //compliant
		}
		else if(i==3)
		{
			throw MISRA_15_3_4___B();  //@violation CATCH_ALL_EXCEPTIONS_THROWN_EXPLICITLY
		}
		else if(i==4)
		{
			throw 3;                   //@violation CATCH_ALL_EXCEPTIONS_THROWN_EXPLICITLY
		}
		else if (i == 5)
		{
			throw 0.5;                
		}
		else if (i == 6)
		{
			throw "string";            //@violation CATCH_ALL_EXCEPTIONS_THROWN_EXPLICITLY
		}
		else if (i == 7)
		{
			throw 'c';                
		}

	}
	catch (MISRA_15_3_4___A const &)
	{

	}
	catch(char ch)
	{

	}
	catch(double dNum)
	{

	}
	//catch (int num)
	//{

	//}
}