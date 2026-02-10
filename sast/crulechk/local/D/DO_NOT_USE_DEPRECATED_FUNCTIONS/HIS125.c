//@checker DO_NOT_USE_DEPRECATED_FUNCTIONS
extern char * strcpy ( char * destination, const char * source );
extern int atoi (const char * str);
extern double atof (const char* str);
extern long int atol ( const char * str );

void his_125(const char *msg) {
	int val;
	char str[20];
	float val_1;
	char str1[20];
	long val_2;
	char str2[20];

	strcpy(str, "98993489");//@violation DO_NOT_USE_DEPRECATED_FUNCTIONS
	val = atoi(str);	//@violation DO_NOT_USE_DEPRECATED_FUNCTIONS

	strcpy(str1, "98993489");//@violation DO_NOT_USE_DEPRECATED_FUNCTIONS
	val_1 = atof(str1);	//@violation DO_NOT_USE_DEPRECATED_FUNCTIONS
	
	strcpy(str2, "98993489");//@violation DO_NOT_USE_DEPRECATED_FUNCTIONS
	val_2 = atol(str2);	//@violation DO_NOT_USE_DEPRECATED_FUNCTIONS
} 
