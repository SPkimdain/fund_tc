//@checker USE_CONST_POINTER_FOR_STRING_VAR

int foo(int x)
{
	int a;

	char *  account = "123-12-123456";           //@violation USE_CONST_POINTER_FOR_STRING_VAR 
	char *  credit_card = "1234-1234-1234-1234"; //@violation USE_CONST_POINTER_FOR_STRING_VAR
	char *  email = "aaa@gmail.com";	         //@violation USE_CONST_POINTER_FOR_STRING_VAR
	char *  foreigner_id = "110101-5111171";     //@violation USE_CONST_POINTER_FOR_STRING_VAR
	char * national_id = "110101-3456789";       //@violation USE_CONST_POINTER_FOR_STRING_VAR
	char *  phone = "02)123-1234";	             //@violation USE_CONST_POINTER_FOR_STRING_VAR
	char *  ip = "127.0.0.1";			         //@violation USE_CONST_POINTER_FOR_STRING_VAR
	char *  passport = "AB1234567";              //@violation USE_CONST_POINTER_FOR_STRING_VAR
	a++;
	a = 0;
	x / a;

}