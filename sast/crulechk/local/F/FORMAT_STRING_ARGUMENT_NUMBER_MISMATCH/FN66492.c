//@checker FORMAT_STRING_ARGUMENT_NUMBER_MISMATCH
#include <stdio.h>

int main(){
	printf("%*.*f\n", 4,3,12345.12345);
	printf("%*.*s\n", 4,3, "TEST");
	printf("%*.*f\n", 4,3,123.12345);
	return 0;
}
