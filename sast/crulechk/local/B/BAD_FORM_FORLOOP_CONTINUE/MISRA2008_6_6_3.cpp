//@checker BAD_FORM_FORLOOP_CONTINUE
void MISRA2008_6_6_3___f()
{
	
	int j = -1;
	for (int i = 0; i != 10 && j != i; ++i)
	{
		if ((i % 2) == 0)
		{
			continue;   //Non-compliant - loop is not well-formed //@violation BAD_FORM_FORLOOP_CONTINUE
		}
		//...
		++j;
	}
	
	
	for (int i = 0; i != 10; ++i)
	{
		if ((i % 2) == 0)
		{
			continue;    //compliant
		}
		//...
	}

	
}