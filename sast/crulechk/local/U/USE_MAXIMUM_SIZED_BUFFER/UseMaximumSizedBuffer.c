//@checker	USE_MAXIMUM_SIZED_BUFFER
extern void PathAppend(char* str1, char* str2) {};
extern char *realpath(const char *path, char *resolved_path) {};
extern int readlink(const char *path, char *buf, int bufsiz) {};

int UMSB_function()
{
	char temp[254] = "test1";
	char temp2[255] = "test2";
	char temp3[256];
	char* ptr;
	
	PathAppend(temp, temp2);	//@violation	USE_MAXIMUM_SIZED_BUFFER
	PathAppend(temp3, temp2);
	PathAppend(ptr, temp2);
	
	readlink(temp, temp2, 255);	//@violation	USE_MAXIMUM_SIZED_BUFFER
	readlink(temp, temp2, 256);	//@violation	USE_MAXIMUM_SIZED_BUFFER	
	readlink(temp, temp3, 255);	//@violation	USE_MAXIMUM_SIZED_BUFFER
	readlink(temp, temp3, 256);
	
	realpath(temp, temp2);		//@violation	USE_MAXIMUM_SIZED_BUFFER
	realpath(temp, temp3);
	
	return 0;
}

