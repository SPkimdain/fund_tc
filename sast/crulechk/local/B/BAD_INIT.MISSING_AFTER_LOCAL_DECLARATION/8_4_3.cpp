// @checker BAD_INIT.MISSING_AFTER_LOCAL_DECLARATION
//
#define IS_DECL_B(A)  \
	int __tempa; \
	char __arr_testa;

#define IS_DECL(A)  \
	int __temp; \
	char __arr_test;

extern int printf ( const char * format, ... );

typedef struct A {
	char a;
	char b;
	long c;
} A;

typedef struct bbRes {
	char a;
	char b;
	long c;
} bbRes;

typedef struct bbReq {
	char a;
	char b;
	long c;
} bbReq;

void f2() {
	int a = 10;
	int b; // @violation BAD_INIT.MISSING_AFTER_LOCAL_DECLARATION

	printf("f2 called!\n");
}

int hicpp_8_4_3() {
	const int a = 0;
	int b = 0;
	char str[32]; // @violation BAD_INIT.MISSING_AFTER_LOCAL_DECLARATION

	while( b < 10)
	{
		b++;
	}

	int d = 10; 

	IS_DECL(10);  //ignore  macro

	for(int i = 0; i < 10; i++)
	{
		b++;
	}

	{
		int var_in_block; // @violation BAD_INIT.MISSING_AFTER_LOCAL_DECLARATION
		int bb = 0;
		if( bb == 0)
			return 10;

		IS_DECL_B(10); //ignore  macro

		char ccd = 'a';
	}

	return a;
}
