// @checker USE_CONST_POINTER_FOR_STRING_VAR

typedef char	char_t;

void foo(){
	char_t *ptr = "char string";	//@violation		USE_CONST_POINTER_FOR_STRING_VAR	
	const char_t cstr[] = "char string";	
	wchar_t *wchar_test = L"aaaaaaaa";	//@violation		USE_CONST_POINTER_FOR_STRING_VAR
	const wchar_t* test = L"asdf";
}