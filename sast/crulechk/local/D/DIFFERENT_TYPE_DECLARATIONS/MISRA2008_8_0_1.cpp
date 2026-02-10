//@checker DIFFERENT_TYPE_DECLARATIONS

//misra 8-0-1 예제
void MISRA2008_8_0_1___f()
{
	int i1; int j1;  //compliant
	
	int i2, *j2;     //Non-compliant  //@violation DIFFERENT_TYPE_DECLARATIONS
	
	int *i3,
	    &j3 = i2;    //Non-compliant   //@violation DIFFERENT_TYPE_DECLARATIONS 
}



//추가 예제
void MISRA2008_8_0_1___g()
{
	int i2;
	int *i3,
		*j3 = &i2;    //compliant


	int *i4,
		*j4,
		&k4 = i2;      //Non-compliant   //@violation DIFFERENT_TYPE_DECLARATIONS 
}