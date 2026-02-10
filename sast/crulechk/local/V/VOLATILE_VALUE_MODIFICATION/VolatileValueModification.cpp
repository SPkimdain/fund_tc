// @checker VOLATILE_VALUE_MODIFICATION

int volatileValueModificationTest()
{
	char c = 'c';
	volatile char &p = c;
	p = 'p';		//@violation VOLATILE_VALUE_MODIFICATION
	
	return 0;
}
