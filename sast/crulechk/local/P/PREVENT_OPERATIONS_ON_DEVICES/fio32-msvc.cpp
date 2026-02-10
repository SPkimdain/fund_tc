// @checker PREVENT_OPERATIONS_ON_DEVICES
#include <cstddef>
#define HANDLE int
extern int CreateFile(const char*, int, int, int*, int, int, int*) {return 1;}
extern int GetFileType(int a){return a;}
extern void CloseHandle(int a);
extern int GENERIC_READ;
extern int GENERIC_WRITE;
extern int OPEN_EXISTING;
extern int FILE_ATTRIBUTE_NORMAL;
extern int INVALID_HANDLE_VALUE;
extern int FILE_TYPE_DISK;

void POOD_func_msvc(const char* fileName)
{
	HANDLE hFile = CreateFile(fileName, GENERIC_READ | GENERIC_WRITE, 
		0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	
	if (hFile == INVALID_HANDLE_VALUE)
	{
		// Handle error 
	}   //GetFileType 함수를 사용한 경우
	else if (GetFileType(hFile) != FILE_TYPE_DISK) //@violation PREVENT_OPERATIONS_ON_DEVICES
	{
		//Handle error
		CloseHandle(hFile);
	} else 
	{
		//Operate on the file 
		CloseHandle(hFile);
	}
}
