#include <stdio.h>

int DO_002_function(const char* s)
{
	FILE* pFile = fopen(s, "a");
	FILE* pFile2 = fopen(s, "a"); //@violation DOUBLE_OPEN
	fclose(pFile);
	fclose(pFile2);
	return 0;
}