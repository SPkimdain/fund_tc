//@checker DO_NOT_REMOVE_CONST


int const_remove_test_function_bad(char* str) {
	return 0;
}

int const_remove_test_function_ok(const char* str) {
	return 0;
}

void const_remove_test_function2(const char* testStr) {
	char* test = (char*)testStr; //@violation DO_NOT_REMOVE_CONST

	const_remove_test_function_bad((char*)testStr); //@violation DO_NOT_REMOVE_CONST



	const_remove_test_function_bad("12345");

	const_remove_test_function_bad((char*)"12345");



	const_remove_test_function_ok("12345");
}

int main() {
	const_remove_test_function2("1234");

	return 0;
}




