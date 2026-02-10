//@checker STANDARD_CHARACTERS

extern int strcmp ( const char * str1, const char * str2 );

void STDCHS_001_function()
{
	char* str = "\a"; //@violation STANDARD_CHARACTERS

	char* str2 = "Not Problem!#%!%#$%";

	char* str3 = "\t";
	
	int x = 0;

	if( strcmp( str, "\v" ) == 0 ) //@violation STANDARD_CHARACTERS
	{
		x++;
	}
}
