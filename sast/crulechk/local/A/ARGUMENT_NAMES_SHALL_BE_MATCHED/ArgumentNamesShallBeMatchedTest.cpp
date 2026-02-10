//@checker ARGUMENT_NAMES_SHALL_BE_MATCHED

void ARGNMSBM_001_function1( int x, int y );

void ARGNMSBM_001_function2( int x, int y, int z );	//@b-violation ARGUMENT_NAMES_SHALL_BE_MATCHED

void ARGNMSBM_001_function3( int x, int y, int z );	//@b-violation ARGUMENT_NAMES_SHALL_BE_MATCHED


void ARGNMSBM_001_function1( int x, int y )
{
  int ret = 0;
  ret++;
}

void ARGNMSBM_001_function2( int k, int l, int m ) //@violation ARGUMENT_NAMES_SHALL_BE_MATCHED
{
  int ret = 0;
  ret++;	
}

void ARGNMSBM_001_function3( int x, int y, int zzzz ) //@violation ARGUMENT_NAMES_SHALL_BE_MATCHED
{
	int ret = 0;
  ret++;
  ret++;
}

int ARGNMSBM_001_function4()
{
	ARGNMSBM_001_function1(10, 10);
	ARGNMSBM_001_function2(10, 12, 14);
	ARGNMSBM_001_function3(20, 22, 24);

  return 0;
}
