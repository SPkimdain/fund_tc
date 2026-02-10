// @checker CONST_VALUE_MODIFICATION

int main()
{

	const char s[] = "foo";

	*(char*)s = '\0';	//@violation	CONST_VALUE_MODIFICATION
	
	
	return 0;
}
