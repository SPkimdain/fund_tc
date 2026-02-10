//@checker MISSING_COMPOUND_STATEMENT

void MISRA2008_6_4_1___f()
{
	int x = 5;
	
	if (x > 10);      //Non-compliant  //@violation MISSING_COMPOUND_STATEMENT
	{
		x = 1;
	}


	if (x > 10)       //compliant
	{
		x = 1;
	}
	else if (x >= 5)  //compliant
	{
		x = 0;
	}
	else              //Non-compliant  //@violation MISSING_COMPOUND_STATEMENT
		x = 3;
		x += 5;
}