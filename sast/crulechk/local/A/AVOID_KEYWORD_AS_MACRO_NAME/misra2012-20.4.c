//@checker AVOID_KEYWORD_AS_MACRO_NAME

#define test int


#define while( E ) for ( ;  ( E ) ; ) //@violation AVOID_KEYWORD_AS_MACRO_NAME
#define unless( E ) if ( ! ( E ) )
#define test double

int avkamn()
{
	int a;
	
  return 0;
}
