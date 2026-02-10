#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class CkUpload {
public :
	void AddFileReference(const char* a, const char* b) {
		return;
	}
};

class CkHttpRequest {
public :
	void AddFileForUpload(const char* a, const char* b) {
		return;
	}
};

int UUOFC_001_function(){
  char *fileName = getenv("fileName");
  
  CkUpload upload;
  upload.AddFileReference("file1",fileName);	//@violation UNRESTRICTED_UPLOAD_OF_FILE.CPP
  
  return 0;
}

