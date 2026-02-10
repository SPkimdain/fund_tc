// @checker DO_NOT_USE_SETLOCALE

extern char* setlocale (int category, const char* locale);
extern int printf ( const char * format, ... );

int main()
{
	setlocale(1, ""); // @violation DO_NOT_USE_SETLOCALE
	
	printf("%s","Locale" );
	
}

