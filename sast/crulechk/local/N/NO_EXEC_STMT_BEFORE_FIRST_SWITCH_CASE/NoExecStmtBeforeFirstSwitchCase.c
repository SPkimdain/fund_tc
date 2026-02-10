// @checker NO_EXEC_STMT_BEFORE_FIRST_SWITCH_CASE
extern int printf ( const char * format, ... );

int f(int a)
{
	return a+1;
}

int foo(int p1){
	int k = 10;
	int y = 10;
	switch(p1)
	{
	case 1:
		{
			switch(k)
			{
				f(k);	//@violation	NO_EXEC_STMT_BEFORE_FIRST_SWITCH_CASE
				int aa = 100;	//@violation	NO_EXEC_STMT_BEFORE_FIRST_SWITCH_CASE
			case 0:
				y = 0;
				break;
			case 2:
				y = 1;
				break;
			default:
				break;
			}
		}
	default:
		k = 11;
		break;
	}
	return 1;
}

int bar(int expr) {
  switch(expr){
    int i = 4;		//@violation	NO_EXEC_STMT_BEFORE_FIRST_SWITCH_CASE
    f(i);				//@violation NO_EXEC_STMT_BEFORE_FIRST_SWITCH_CASE
  case 0:
    i = 17;
  /* Falls through into default code */
  default:
	  printf("aaa : %d", i);
  }
  return 0;
}
