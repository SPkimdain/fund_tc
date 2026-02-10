#include <string.h>

/* TOIBC_017 - strcat functions */
class TOIBC_017_Class {
public:
  char* TOIBC_017_function1(char* src) {
    return strcat(dst, src);
  }

  void TOIBC_017_function2(int flag, int size, char* src) {
    if(size < 6) {
      char* temp = new char[size];
      if(temp == 0) {
        return;
      }
      strcpy(temp, src);

      char src2[] = "fghi"; //sizeof(src2) == 5
      char src3[] = "1"; //sizeof(src3) == 2
      char* ret = 0;

      strcpy(dst, src2); //It's ok. , last offset is 4.

      if(flag > 0) {
        ret = TOIBC_017_function1(src3); //It's ok
      }
      else {
        ret = TOIBC_017_function1(temp); //@violation TYPE_OVERRUN.IN_FUNC_CALL.BAD_COND
      }

      delete[] temp;
    }
  }

private:
  char dst[6];
};
