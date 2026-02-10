// @checker BAD_RETURN_TEST

extern int count;

int bar(int a)
{
	int x = 0;
	if(count > 0)
	{
		x = 1;
	}
	else {
		x = 2;
	}
	return x;
}

void func()
{
	if(!bar(3))	//@violation	BAD_RETURN_TEST
	{
		return;
	}
}
