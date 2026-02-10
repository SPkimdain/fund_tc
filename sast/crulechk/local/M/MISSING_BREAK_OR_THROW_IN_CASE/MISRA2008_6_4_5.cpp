//@checker MISSING_BREAK_OR_THROW_IN_CASE

//misra 6-4-5 예제
int MISRA2008_6_4_5___f(int x)
{
	int a = 3;
	int b = 4;
	
	switch (x)
	{
		
	case 0:      //compliant
		break;   
	case 1:      //compliant - empty drop 

	case 2:      //compliant
		break;   
	case 3:      //compliant
		throw;   
	
	case 4:      //Non-compliant - non empty drop    
		a = b;
	             //@violation MISSING_BREAK_OR_THROW_IN_CASE
	default:     //Non-compliant - default must also have "break"   
		;          //@violation MISSING_BREAK_OR_THROW_IN_CASE
	}
}


//추가 예제
int MISRA2008_6_4_5___f2(int x)
{
	int a = 3;
	int b = 4;

	switch (x)
	{

	case 0:      //compliant
		break;
	case 1:      //Non-compliant - non empty drop    
		3 + 5;     //@violation MISSING_BREAK_OR_THROW_IN_CASE 
	case 2:      //compliant
		break;
	case 3:      //compliant
	
	case 4:      //compliant
	case 5:      //Non-compliant - non empty drop   
		a = b;
               //@violation MISSING_BREAK_OR_THROW_IN_CASE
	default:     //compliant
		throw;
	}
}
