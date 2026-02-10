//@checker UNIQUE_HEADER_FILE_NAME

/* 옵션을 켰을때만 동작함. */
#include "longname_abcdefghijklmn.h" 
#include "longname_abcd.h" 

#include "digit_after_period.1" //@violation UNIQUE_HEADER_FILE_NAME

int main()
{
	int x = 10;
	switch(x)
	{
		int y = 5;
	case 0:
		break;
	default:
		break;
	}
}
