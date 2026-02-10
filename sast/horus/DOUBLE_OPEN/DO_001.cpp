#include <stdio.h>
#include <ctime>

int DO_001_function(void)
{
	FILE* pFile = fopen("test.txt", "a");
	FILE* pFile2 = fopen("test.txt", "a"); //@violation DOUBLE_OPEN
	fprintf(pFile, "test");
	fprintf(pFile2, "test");
	fclose(pFile);
	fclose(pFile2);
	return 0;
}