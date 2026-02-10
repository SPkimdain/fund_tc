//@checker NULL_SHALL_BE_POINTER_CONSTANT

#define MYNULL_1 0
#define MYNULL_2 ( void * ) 0

void f (void)
{
	int *p1 = ( void * ) 0; 
	int *p2 =  0; //@violation NULL_SHALL_BE_POINTER_CONSTANT
	
	
	if ( p1 == MYNULL_1 ) //@violation NULL_SHALL_BE_POINTER_CONSTANT
	{
		
	}
	if ( p2 == MYNULL_2 ) 
	{
		
	}
	
	
	p1 = p2 ? (void *)0 : p2;
	p1 = 1 ? 0 : p2; //@violation NULL_SHALL_BE_POINTER_CONSTANT
	
	
}