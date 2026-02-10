#include <string.h>

/* ODI_003 - simple memmove */
void ODI_003_function(int flag) {
  char str[] = "0123456789"; //sizeof(src) == 11
  char* temp = new char[sizeof(str)];
  if(temp == 0) {
    return;
  }

  memcpy(temp, str, sizeof(str));

  if(flag == 1) {
    memmove(temp + 5, temp + 2, 5); //It's ok.
  }
  else {
    memmove(temp + 7, temp + 2, 5); //@violation OVERRUN.DYNAMIC.IN_FUNC_CALL
  }

  delete[] temp;
}
