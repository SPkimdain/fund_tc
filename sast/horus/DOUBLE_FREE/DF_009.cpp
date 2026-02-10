#include <stdlib.h>

int DF_009_function1(int* ip){
  if(ip){
    free(ip);
    return 1;
  }
  return 0;
}

void DF_009_function2(){
  int* ip = (int*)malloc(10);
  
  if(ip == 0) {
    return;
  }

  int a = DF_009_function1(ip);
  free(ip);   //@violation DOUBLE_FREE

}
