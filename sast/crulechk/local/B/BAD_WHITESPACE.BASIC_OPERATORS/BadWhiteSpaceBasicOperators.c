//@checker BAD_WHITESPACE.BASIC_OPERATORS

int bwsbo()
{
	int a= 5+5; //@violation BAD_WHITESPACE.BASIC_OPERATORS
	int b = 3;
	int c = 4 + 4;
	int d = 5+ 4; //@violation BAD_WHITESPACE.BASIC_OPERATORS
	int e = 5 +4; //@violation BAD_WHITESPACE.BASIC_OPERATORS
	
	
	int temp  = a+b +c + d+ e;  //@violation BAD_WHITESPACE.BASIC_OPERATORS
	return temp + a;
}