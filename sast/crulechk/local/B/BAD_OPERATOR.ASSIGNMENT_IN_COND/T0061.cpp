//@checker BAD_OPERATOR.ASSIGNMENT_IN_COND

//Base

void T0061func1()
{
	int x = 0;
	//Base01 - 가이드 예시
	if( x = 10 ) //@violation BAD_OPERATOR.ASSIGNMENT_IN_COND
	{
		x++;
	}

	//Base02 - ==연산자 사용
	if( x == 10 ) //Checking False Alarm
	{
		x++;
	}
}

//Complex

void T0061func2()
{
	int y = 10;
	int x = 0;

	//Complex02 - 복합수식절 사용
	if( x = ( long )( ( y - 3 ) + 10 ) ) //@violation BAD_OPERATOR.ASSIGNMENT_IN_COND
	{
		x++;
	}
}
