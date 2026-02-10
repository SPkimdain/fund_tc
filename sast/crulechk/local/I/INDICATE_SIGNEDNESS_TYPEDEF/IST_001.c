//@checker INDICATE_SIGNEDNESS_TYPEDEF
typedef	short 			short_t;	//@violation INDICATE_SIGNEDNESS_TYPEDEF
typedef	int			    int_t;		//@violation INDICATE_SIGNEDNESS_TYPEDEF
typedef	char        	char_t;		//@violation INDICATE_SIGNEDNESS_TYPEDEF
typedef	long        	long_t;		//@violation INDICATE_SIGNEDNESS_TYPEDEF
typedef	long long       long_long_t;	//@violation INDICATE_SIGNEDNESS_TYPEDEF

typedef	signed short 			short_t2;
typedef	signed int			    int_t2;	
typedef	unsigned char        	char_t2;	
typedef	unsigned long        	long_t2;	
typedef	unsigned long long       long_long_t2;

void func()
{
	int a = 0;
}