// @checker STANDARD_ESCAPE_SEQUENCE

#include <stdio.h>

int STDESCPSEQ_001_function()
{
	int  i_var = 4;
	char x = 'x';

	printf("%d\n", i_var);	
	printf("\a");
	printf("\b");
	printf("\f");
	printf("\n");
	printf("\r");
	printf("\t");
	printf("\v");
	printf("\'");
	printf("\"");
	printf("\\");
	printf("\?");
	printf("\123");
	printf("\xafaf");
	printf("\?\a\b\n\xe4");
	
	printf("\F"); // @violation STANDARD_ESCAPE_SEQUENCE
	printf("\Q"); // @violation STANDARD_ESCAPE_SEQUENCE
	printf("\X"); // @violation STANDARD_ESCAPE_SEQUENCE
	printf("\183"); // @violation STANDARD_ESCAPE_SEQUENCE
	printf("\xAQ"); // @violation STANDARD_ESCAPE_SEQUENCE
	printf("\xaqaf"); // @violation STANDARD_ESCAPE_SEQUENCE
	printf("qefwefe\Hdfqwfqw"); // @violation STANDARD_ESCAPE_SEQUENCE
	printf("\12"); // @violation STANDARD_ESCAPE_SEQUENCE
	printf("\12\n\a\b\f"); // @violation STANDARD_ESCAPE_SEQUENCE
	
	putchar('\A'); // @violation STANDARD_ESCAPE_SEQUENCE
	
	while( x != '\Q' ) // @violation STANDARD_ESCAPE_SEQUENCE
	{
	}
	
	if( x == '\xfg' ) // @violation STANDARD_ESCAPE_SEQUENCE
	{
		x = 'x';
	}
	
	switch( x )
	{
	case '\W': // @violation STANDARD_ESCAPE_SEQUENCE
	case '\E': // @violation STANDARD_ESCAPE_SEQUENCE
	case '\n':
		break;
	}
  
  printf("\\UserDump.hpp"); //It's ok.
	
	return 1;
}
