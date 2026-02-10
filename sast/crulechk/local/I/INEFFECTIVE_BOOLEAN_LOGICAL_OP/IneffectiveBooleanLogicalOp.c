// @checker INEFFECTIVE_BOOLEAN_LOGICAL_OP



void INEFBOOLLO_001_function()
{
	int foo1 = 1;
	int foo2 = 2;
	int foo3 = 3;
	int i;
	int x = 0;

	i = foo1 && foo2 || foo3; //@violation INEFFECTIVE_BOOLEAN_LOGICAL_OP
	i = foo1 && ((foo2 || foo3) && x ); //@violation INEFFECTIVE_BOOLEAN_LOGICAL_OP
	i = (foo1 && foo2) || foo3; //@violation INEFFECTIVE_BOOLEAN_LOGICAL_OP
	
	i = foo1 && foo2 && foo3;//@violation INEFFECTIVE_BOOLEAN_LOGICAL_OP
	i = foo1 || foo2 || foo3; //@violation INEFFECTIVE_BOOLEAN_LOGICAL_OP
	
	if( foo1 && foo2 + 10 ) //@violation INEFFECTIVE_BOOLEAN_LOGICAL_OP
	{
		x++;
	}
	
	while( foo1 == 0 )
	{
		x++;
	}
	
	while( foo1 == 0 && foo2 ) //@violation INEFFECTIVE_BOOLEAN_LOGICAL_OP
	{
		x++;
	}
	
	while( ( foo1 == 0 ) && foo2 )//@violation INEFFECTIVE_BOOLEAN_LOGICAL_OP
	{
		x++;
	}
	
	while( foo1 && ( long )foo2 )//@violation INEFFECTIVE_BOOLEAN_LOGICAL_OP
	{
		x++;
	}
	
	while( foo1 && ( long )foo2 + 10 ) //@violation INEFFECTIVE_BOOLEAN_LOGICAL_OP
	{
		x++;
	}
}
