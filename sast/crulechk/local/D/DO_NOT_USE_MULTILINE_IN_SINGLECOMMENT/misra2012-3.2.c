//@checker DO_NOT_USE_MULTILINE_IN_SINGLECOMMENT
extern int b;

void f ( void )
{
	int x = -1;
	int a = 0 ;  // comment \
	if ( b ) //@violation DO_NOT_USE_MULTILINE_IN_SINGLECOMMENT
	{
		++ x;
	}
	
	a = 0 ;  /* comment \ 
	if ( b ) */
	{
		++ x;
	}
		
		
		
}