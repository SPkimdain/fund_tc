// @checker RETURN_SHALL_NOT_HAVE_EXPRESSION
// This rule is for EDG, not crulechk

void RSNHE_001_function2()
{
	return	0;  // @violation RETURN_SHALL_NOT_HAVE_EXPRESSION
}

void RSNHE_001_function3()
{
	return	;
}

int RSNHE_001_function4()
{
	return 1; 
}
