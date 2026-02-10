//@checker DO_NOT_USE_VARIABLE_LENGTH_ARRAY


void DNUVLA_002_function(int n) {
	int vla[ n ]; //@violation DO_NOT_USE_VARIABLE_LENGTH_ARRAY
}

void DNUVLA_002_function2(void) {
	DNUVLA_002_function (0);
	DNUVLA_002_function(-1);
	DNUVLA_002_function(10);
	
} 

void DNUVLA_002_function2(int n,
		int a[10][n]) { //@violation DO_NOT_USE_VARIABLE_LENGTH_ARRAY
	int (*p)[20];
	
	p = a;
}
