//@checker REDUNDANT_CONDITION
void RC_function_008(){

	while ( true )
	{
		//exception 1
	}
	
	while ( 1 )
	{
		//exception 1
	}
	
	while ( 2 > 1 )
	{
		//exception 1
	}
	
	do
	{
		//exception 2
	} while ( false ) ;
	
	do
	{
		//exception 2
	} while ( 0 ) ;
	
	do
	{
		//exception 2
	} while ( 0 > 1 ) ;

}

