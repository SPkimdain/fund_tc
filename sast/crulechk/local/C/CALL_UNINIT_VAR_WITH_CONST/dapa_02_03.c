//@checker CALL_UNINIT_VAR_WITH_CONST
extern int call_uninit_foo(const int *p);

void call_uninit_bar_alter(void)
{
	int *y3;
	int x3;
	x3 = call_uninit_foo(y3);//@violation CALL_UNINIT_VAR_WITH_CONST
}

void call_uninit_bar_good(void)
{
	int y1;
	int x1 = 0;
	y1 = 100;
	x1 = call_uninit_foo(&y1);
}

void call_uninit_bar_bad(void)
{
	int y2;
	int x2 = 0;
	x2 = call_uninit_foo(&y2);//@violation CALL_UNINIT_VAR_WITH_CONST
}


void call_uninit_bar_ex(int* p)
{
	int y2;
	int x2 = 0;
	x2 = call_uninit_foo(p);
}