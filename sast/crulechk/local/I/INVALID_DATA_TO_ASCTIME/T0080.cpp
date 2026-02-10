//@checker INVALID_DATA_TO_ASCTIME

struct tm {
};
//Base
extern char*   asctime  ( const struct tm* time_ptr );

void T0080func1()
{
	struct tm time_tm;

	//Base01 - 가이드 예시
	char *time = asctime( &time_tm ); //@violation INVALID_DATA_TO_ASCTIME
}

