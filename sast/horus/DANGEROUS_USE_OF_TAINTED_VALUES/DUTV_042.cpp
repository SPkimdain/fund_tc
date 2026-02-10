#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
  int len;
  char data[20];
}DUTV_042_WebPacket;

extern void strcpy_sptest(char* dst, char* src);
extern void hw_memcpy(char* dst, char* src, int size);
extern void callByRef_TaintGen_sptest(void *buf);

int DUTV_042_function(DUTV_042_WebPacket* buf, DUTV_042_WebPacket* dst)
{
	unsigned int a = 0;
	char dst1[10];
	
  callByRef_TaintGen_sptest(buf);
	
	dst = (DUTV_042_WebPacket*)malloc(sizeof(DUTV_042_WebPacket));
	if (dst == NULL)
		return 0;
	
	strcpy_sptest((char*)dst,(char*)buf); //taint_propagate
	hw_memcpy(dst1 + ((DUTV_042_WebPacket*)dst)->len, "aaaa", 5); //@violation DANGEROUS_USE_OF_TAINTED_VALUES
	
	free(dst);
	return 0;
}
