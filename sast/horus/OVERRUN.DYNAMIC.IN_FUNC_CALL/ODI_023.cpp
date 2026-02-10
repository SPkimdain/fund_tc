#include <stdlib.h>
#include <memory.h>
#include <string.h>

/* OVERRUN.DYNAMIC.IN_FUNC_CALL */

void ODI_023_panic(char *str){
  exit(4);
}

void* ODI_023_ck_malloc(unsigned int size) {
  void *ret = calloc(1, size ? size : 1);
  if (!ret) {
    ODI_023_panic("couldn't allocate memory");
  }
  return ret;
}

int ODI_023_function1(char* ipe, char* optarg){
  ipe = (char*)ODI_023_ck_malloc(strlen(optarg) + 2);
  ipe[0] = '*';
  strcpy(ipe + 1, optarg); //It's ok.
  
  return 0;
}


int ODI_023_function2(){
  char* dst = new char[5];
  if(dst == 0) {
    return 0;
  }
  char src[] = "abcde"; //sizeof(src) == 6  
  strcpy(dst, src); //@violation OVERRUN.DYNAMIC.IN_FUNC_CALL
  delete[] dst;
  
  return 1;
}
