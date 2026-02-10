#include <stdlib.h>

/* UAF_009 - Function call, deep depth */
bool UAF_009_function1(bool flag, int* value) {
  if(flag == false) {
    *value = 100; 
    return true;
  }
  return false;
}


bool UAF_009_function2(int* value) {
  return UAF_009_function1(false, value); 
}

void UAF_009_function3(bool flag, int* data1, int* data2) {
  if(flag == true) {
    UAF_009_function2(data1);
  }
  else{
    UAF_009_function2(data2); 
  }
}

int UAF_009_function4() {
  int* data1 = (int*)malloc(4);

  if(data1 == 0) {
    return 0;
  }

  int* data2 = (int*)malloc(4);

  if(data2 == 0) {
    free(data1);
    return 0;
  }

  free(data2);
  UAF_009_function3(true, data1, data2); //It's ok.

  UAF_009_function3(false, data1, data2);//@violation USE_AFTER_FREE


  free(data1);
  return 0;
}


