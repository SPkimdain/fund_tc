// @checker DO_NOT_USE_COMMA_OPERATOR

void func()
{
	int i = 10;
	int j = 20;
	int a = 0;
	for( i=1,j=2; i < 10; i++,j++) {             // @violation DO_NOT_USE_COMMA_OPERATOR
		a++;
	}
}
