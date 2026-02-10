//@checker BAD_COMPARE

//Base

int getuid()
{
	return 0;
}

int geteuid()
{
	return 0;
}

void T0084func1()
{
	int x = 0;
	//Base01 - 가이드 예시
	if( getuid == 0 || geteuid == 0 ) //@violation BAD_COMPARE
	{
		x++;
	}

	//Base02 - while 조건부
	while( getuid == 0 ) //@violation BAD_COMPARE
	{
		x++;
	}
}

void T0084func2()
{
	void *fp = 0;

	//Complex01 - 포인터 할당시
	fp = getuid; //Checking False Alarm
	
}
