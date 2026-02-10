// @checker NO_GLOBAL_VARIABLES_BETWEEN_FUNCTIONS

extern int printf ( const char * format, ... );
extern char * strcat ( char * destination, const char * source );
extern void * memset ( void * ptr, int value, int num );
extern int g_extern_valid_global;
int g_valid_global;

#define IS_DECL_B(A)  \
	int __tempa; \
	char __arr_testa;

#define IS_DECL(A)  \
	int __temp; \
	char __arr_test;

#define BKM_TS_CM_CALL(_CM_NAME_) \
{ \
	_CM_NAME_##Req i_##CM_NAME_; \
	_CM_NAME_##Res o_##CM_NAME_; \
	memset(&i_##CM_NAME_, 0x00, sizeof(i_##CM_NAME_) );\
}
int g_valid_global1; 
int g_valid_global2; 
int g_valid_global3; 

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

	printf(strcat("aa", "bb"));
	printf("f2 called!\n");

	int b = 10;

	printf("f2 called!\n");
}

int g_invalid_global; // @violation NO_GLOBAL_VARIABLES_BETWEEN_FUNCTIONS
int g_invalid_global2; // @violation NO_GLOBAL_VARIABLES_BETWEEN_FUNCTIONS
int g_invalid_global3; // @violation NO_GLOBAL_VARIABLES_BETWEEN_FUNCTIONS

int main() {
	const int a = 0;
	int i = 0;
	int b = 0;
	char str[32];

	while( b < 10)
	{
		b++;
	}

	int d = 10; 

	IS_DECL(10);

	for(i = 0; i < 10; i++)
	{
		b++;
	}

	{
		int var_in_block = 10; 
		int bb = 0; 
		if( bb == 0)
			return;

		IS_DECL_B(10);

		char ccd = 'a'; 
		BKM_TS_CM_CALL(bb);
	}

	return a;
}
