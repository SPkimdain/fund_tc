//@checker AVOID_SIDE_EFFECT_FROM_FUNCTION_CALL

char * dbp = "test test";

static char * skip_spaces(char * cp )
{
 while ((*cp))
 cp++;
 return cp;
}


void ASEFFCALL_001_function()
{
	char * test = skip_spaces(dbp);
	dbp = test;
}
