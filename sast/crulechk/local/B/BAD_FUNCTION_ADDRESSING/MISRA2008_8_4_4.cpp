// @checker BAD_FUNCTION_ADDRESSING

int MISRA2008_8_4_4___f1()
{
	return 0;
}

void MISRA2008_8_4_4___f2()
{
	if (0 == MISRA2008_8_4_4___f1)           //Non-compliant  // @violation BAD_FUNCTION_ADDRESSING
	{
		//...
	}


	int(*p)(void) = MISRA2008_8_4_4___f1;    //Non-compliant  // @violation BAD_FUNCTION_ADDRESSING

	if (0 == &MISRA2008_8_4_4___f1)          //compliant
	{
		MISRA2008_8_4_4___f1();              //compliant
	}

	int(*p2)(void) = &MISRA2008_8_4_4___f1;   //compliant
}