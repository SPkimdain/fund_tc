#include <string.h>

/* ODIBC_003 - simple memmove */
void ODIBC_003_function(int flag, int index) {
  char str[] = "0123456789"; //sizeof(src) == 11
  char* temp = new char[sizeof(str)];
  if(temp == 0) {
    return;
  }

  memcpy(temp, str, sizeof(str));

  if(flag == 1) {
    if(index < 6) {
      memmove(temp + index, temp + 2, 5); //It's ok.
    }
  }
  else {
    if(index < 10) {
      memmove(temp + index, temp + 2, 5); //@violation OVERRUN.DYNAMIC.IN_FUNC_CALL.BAD_COND
    }
  }

  delete[] temp;
}
