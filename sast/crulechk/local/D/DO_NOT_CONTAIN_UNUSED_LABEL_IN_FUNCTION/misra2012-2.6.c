//@checker DO_NOT_CONTAIN_UNUSED_LABEL_IN_FUNCTION
void R_2_6 ( void )
{
	
   int x = 6;
   first: x;
goto first;   
   use_int16 ( x );
}


void use_int16(int x)
{
	
	
	second: //@violation DO_NOT_CONTAIN_UNUSED_LABEL_IN_FUNCTION
	x = x+1;
	return ;
	
}