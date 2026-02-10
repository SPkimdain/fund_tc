// @checker BAD_INITIALIZATION.ARRAY

void foo()
{
	const char s[3] = "abc";	// @violation BAD_INITIALIZATION.ARRAY
}

