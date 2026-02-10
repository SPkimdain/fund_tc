#include <memory.h>

/* TOI_012 - memcpy functions */
struct TOI_012_Class {
  char a[6];
};

void TOI_012_function1(char* src, int size) {
  TOI_012_Class obj;
  memcpy(obj.a, src, size); 
}

void TOI_012_function2(int flag) {
  char str1[] = "01234"; //sizeof(str1) == 6
  char str2[] = "0123456789"; //sizeof(str2) == 11

  if(flag > 0) {
    TOI_012_function1(str1, sizeof(str1)); //It's ok.
  }
  else {
    TOI_012_function1(str2, sizeof(str2)); //@violation TYPE_OVERRUN.IN_FUNC_CALL
  }
}
