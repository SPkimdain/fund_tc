//@checker DO_NOT_DECLARE_IN_LOOPS

void DoNotDeclearInLoops()
{
	int i;
	for(i=0; i<100; i++) {
		int a = i + 1; //@violation DO_NOT_DECLARE_IN_LOOPS
	}
}

void nestedLoop()
{
	for(int i = 0; i < 100; i++)
	{
		for(int j = i; j < 200; j++)
		{
			int k = 10;	//@violation DO_NOT_DECLARE_IN_LOOPS
		}
		int kk = 20; //@violation DO_NOT_DECLARE_IN_LOOPS
	}
}


void complexLoop(int x)
{
	for(int i = 0; i < 100; i++)
	{
		switch(x)
		{
		case 0:		
			for(int j = 0; j < 10; j++)
			{
				int abc = j + 1; //@violation DO_NOT_DECLARE_IN_LOOPS
			}
			break;
		case 1:
			break;
		default:
			break;
		}
	}
}

