//@checker FOR_LOOP_NONBOOL_CONTROL_CHANGED
int MISRA2008_6_5_6___fn()
{
	return 3;
}

void MISRA2008_6_5_6___f()
{
	int u8a = 5;
	bool flag = false;

	for (int x = 0; (x < 10) && (u8a != 3U) &&  flag ; ++x)  //Non-compliant Line 14 
	{
		u8a = MISRA2008_6_5_6___fn(); //@violation FOR_LOOP_NONBOOL_CONTROL_CHANGED
		flag = false;  
		
		
	}


	for (int x = 0; (x < 10) && flag; ++x)         //compliant
	{
		flag = true;
	}
	
	int j = -1;
	for (int i = 0; i != 10 && j != i; ++i) //Non-compliant Line 34
	{
		if ((i % 2) == 0)
		{
			continue;   
		}
		//...
		++j; //@violation FOR_LOOP_NONBOOL_CONTROL_CHANGED
	}
	
	
}
