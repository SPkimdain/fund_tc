//@checker FOR_LOOP_CONTROL_CHANGE_COND

bool test_a(bool *pB)
{
	int x = 3;
	*pB = (x == 5) ? true : false;
	return *pB;
}

void MISRA2008_6_5_5___f()
{
	bool bool_a = false;
	
	
	for(int x=0; (x<10)&& test_a(&bool_a); ++x)  //Non-compliant //@violation FOR_LOOP_CONTROL_CHANGE_COND
	{ }


	
	for (int x = 0; (x < 10) && !bool_a; ++x)
	{
		if (x == 5)
		{
			bool_a = true;    //compliant
		}

	}

	

	volatile bool status;
	for(int x=0; (x<10)&&status; ++x)   //compliant
	{ }
}