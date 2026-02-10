//@checker EXPR_NOT_BOOLEAN

void MISRA2008_5_3_1___f()
{
	int a = 100;
	int b = 100;
	int c = 100;
	int d = 100;
	int u8_a = 100;
	int *ptr = &a;

	if((a<b) && (c<d))       //compliant
	{ }

	if(100 && (c<d))          
	{ }

	if ((a < b) && (c + d))  //Non-compliant    //@violation EXPR_NOT_BOOLEAN
	{}

	if(u8_a && (c+d))        //Non-compliant    //@violation EXPR_NOT_BOOLEAN
	{ }
   
	if(!100)                   
	{ }

	if(!ptr)                 //Non-compliant     //@violation EXPR_NOT_BOOLEAN
	{ }

	if(!false)               //compliant
	{ }
}