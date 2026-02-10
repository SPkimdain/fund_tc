//@checker BAD_PATH_MANIPULATION

//#include <stdio.h>
//#include <windows.h>
//#include "Shlwapi.h"
//#include "Shlobj.h"

#define MAX_PATH 260
#define SMALL_PATH 128
int PathAppend(char * , char *);
int getCurrentDirectory(int  , char *);
int SHCreateDirectoryEx(void *, char*, void *);
int StrDup(char*);


int BPMNPUL_001_function(char *name) {
	//MAX_PATH
	char outputDirectoryName[MAX_PATH];
	char smallOutputDirName[SMALL_PATH];
	
	//if (GetCurrentDirectory(128, outputDirectoryName) == 0) {
	//	return 0;
	//}
	if (!PathAppend(outputDirectoryName, "output")) {
		return 0;
	}
	if (!PathAppend(outputDirectoryName, name)) {

		return 0;
	}
	if (!PathAppend(smallOutputDirName, name)) { //@violation BAD_PATH_MANIPULATION

		return 0;
	}
	if (!PathAppend(smallOutputDirName, "output")) { //@violation BAD_PATH_MANIPULATION

		return 0;
	}
	
	
	if (SHCreateDirectoryEx(0, outputDirectoryName, 0) != -1) {

		return 0;
	}
	StrDup(outputDirectoryName);

  return 0;
}



