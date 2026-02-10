//@checker JUMP_OVER_SCOPE
void f2(int a)
{
	int b = 0;
	if(a <= 0)
	{
		goto L2;	//@violation JUMP_OVER_SCOPE
	}

	goto L1;

	if(a == 0)
	{
		goto L1;
	}

	goto L2;//@violation JUMP_OVER_SCOPE
L1:
	if(a > 0)
	{
L2://@b-violation JUMP_OVER_SCOPE
		;
	}
}
void f1(int x)
{
	int y  = 1;
	switch(x)
	{
	case 0:
		if (x == y)
		{
			goto L11;//@violation JUMP_OVER_SCOPE
		}
		else
		{
			goto L12;
			
		}
		L12:
		break;
	case 1:
		y = x;
L11://@b-violation JUMP_OVER_SCOPE
		++x;
		break;
	default:
		break;
	}
}