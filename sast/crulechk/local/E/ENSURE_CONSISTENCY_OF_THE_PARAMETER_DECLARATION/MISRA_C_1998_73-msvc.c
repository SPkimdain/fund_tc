//@checker ENSURE_CONSISTENCY_OF_THE_PARAMETER_DECLARATION


int add( int x, int y )
{
	return x + y;
}

void ECOTPD_001_function1( int x, float, double y ) //@violation ENSURE_CONSISTENCY_OF_THE_PARAMETER_DECLARATION
{
	int ret = 0;
  ret++;
}

void ECOTPD_001_function2( char x, unsigned char, double ) //@violation ENSURE_CONSISTENCY_OF_THE_PARAMETER_DECLARATION
{
  int ret = 4;
  ret++;
}

void ECOTPD_001_function3( char, char, double )
{
	int x = 10;
  int ret = 0;
  ret++;
}
