//@checker USE_STRTOL
extern int atoi (const char * str);
extern int sscanf ( const char * s, const char * format, ...);

int main()
{
	char* str = "1234";
	char str2[32] = { 0 };
	
	int intValue = atoi(str); //@violation USE_STRTOL
	
	int intValue2 = 0;
		
	/* sscanf의 두번째 문자열 인자에서 %ld, %d가 포함되어 있는 경우는 알람을 냄. */
	sscanf( str, "%d", &intValue2 ); //@violation USE_STRTOL

	/* 문제 없음. */
	sscanf( str, "1%s", str2 );

	return 0;
}


