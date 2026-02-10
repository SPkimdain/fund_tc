//@checker DO_NOT_USE_PRAGMA

#pragma pack(push, 1) //@violation DO_NOT_USE_PRAGMA
typedef struct _TEST2{   
    char cData;   
    int iData;   
    short sData;   
}TEST2;   
#pragma pack(pop) //@violation DO_NOT_USE_PRAGMA

int main()
{
	TEST2 test;
	int x = 0;
	return 0;
}

