#include <string.h>

/* TOIBC_015 - strncpy functions1 */
class TOIBC_015_Class {
public:
  char* getDst(){ return dst; }
private:
  char dst[5];
};

void TOIBC_015_function1(char* dst, char* src, int size) {
  strncpy(dst, src, size);
}

int TOIBC_015_function2(int size) {
  return size + 5;
}

void TOIBC_015_function3(int size) {
  if(size < 5) { //[min, 4]
    char src[] = "0123456789"; //sizeof(src) == 11
    TOIBC_015_Class obj;

    TOIBC_015_function1(obj.getDst(), src, size); //It's ok.

    int index = TOIBC_015_function2(size); //[min, 9]

    TOIBC_015_function1(obj.getDst(), src, index); //@violation TYPE_OVERRUN.IN_FUNC_CALL.BAD_COND
  }
}


