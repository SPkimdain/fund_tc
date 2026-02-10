//@checker ASSIGN_STRING_TO_CONST_POINTER_CHAR


void MISRA2012_7_4___func()
{
	char *s1 = "string1";       //@violation ASSIGN_STRING_TO_CONST_POINTER_CHAR
	const char *s2 = "string2";


	char *s3;
	s3 = "string3";             //@violation ASSIGN_STRING_TO_CONST_POINTER_CHAR

	const char *s4;
	s4 = "string4";
}

void MISRA2012_7_4___f1(char *s1)
{

}

void MISRA2012_7_4___f2(const char *s2)
{

}

void MISRA2012_7_4___g()
{	
	MISRA2012_7_4___f2("string6");
}


char *MISRA2012_7_4___name1()
{
	return ("string7");              //@violation ASSIGN_STRING_TO_CONST_POINTER_CHAR
}

const char *MISRA2012_7_4___name2()
{
	return ("string8");
}