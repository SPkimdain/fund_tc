//@checker IMPROPER_RANDOM_USAGE

#include <stdlib.h>
#include <time.h>
#define DWORD int
#define BYTE char
int hProvider = 0;

extern int rand();
extern void CryptGenRandom(int, const int, char*);

void T0054func1()
{
	srand( time(NULL) );
	//Base01 - 가이드 예시
	int x = 0;
	x = rand(); //@violation IMPROPER_RANDOM_USAGE

	//Linux Function Test는 제외(srandom)

	const DWORD dwLength = 8;
	BYTE pbBuffer[dwLength] = {};
	//Base02 - CryptGenRandom을 CryptAcquireContext 없이 호출	
	CryptGenRandom( hProvider, dwLength, pbBuffer ); //@violation IMPROPER_RANDOM_USAGE

}
