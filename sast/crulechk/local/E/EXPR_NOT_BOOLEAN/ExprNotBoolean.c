// @checker EXPR_NOT_BOOLEAN

#include "custom_typedef.h"

struct tag_my_struct
{
	int s_bar;
	uint32_t s_bar2;
};

void foo(void)
{
	bool_t b1;
	int32_t a,i;
	uint32_t u32a;
	float32_t f1=1.0f ;
	float32_t f2 = 10.1f;
	struct tag_my_struct c;
	register int yy_act;
	
	
	do 
	{
		f2 += f1;
	} while(0);
	

	if(a)	//@violation EXPR_NOT_BOOLEAN
	{
		; /* Some codes....*/
	}

	// #1944 case
	if ( yy_act < 24 )
	{
	}

	
	if(b1){
	}


	if( f1 >= f2)
	{
	}

	if ( u32a > 1u )
	{
	}

	

	while(c.s_bar)	//@violation EXPR_NOT_BOOLEAN
	{
		; /* some codes*/
	}

	if( a != 0)
	{
	}

	if(a == 1)
	{
	}

	for(i = 0; i < 100; i++)
	{
	}
}