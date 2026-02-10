//@checker UNUSED_VALUE

void MISRA2008_0_1_9___f(int x)
{
    if (x>3)
    {
         return;
         int z;   //@violation UNUSED_VALUE
         int b;   //@violation UNUSED_VALUE
    }
    
}

void MISRA2008_0_1_9___f2(int b)
{
  int a; //@violation UNUSED_VALUE
	if (b > 2)
	{
		a = 5;    
	}
	else
	{
		a = 6;
	}
}
