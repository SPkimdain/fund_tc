//@checker EXPR_NOT_BOOLEAN

void MISRA2008_5_0_13___f(int x)
{
	if(x)                     //Non-compliant //@violation EXPR_NOT_BOOLEAN
	{ }

	if(x==0)                  //compliant
	{ }

	for(int x=10; x; --x)     //Non-compliant  //@violation EXPR_NOT_BOOLEAN
	{ }

	for(int x=10; x!=0; --x)  //compliant
	{ }
}

