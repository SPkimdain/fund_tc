#include <string.h>

/* TOI_015 - strcpy functions */
struct TOI_015_Class {
public:
  void TOI_015_function1(char* src) {
    strcpy(dst, src);
  }

  void TOI_015_function2() {
    char src[] = "abcde"; //sizeof(src) == 6
    char src2[] = "fghi"; //sizeof(src2) == 5

    TOI_015_function1(src2); //It's ok.

    TOI_015_function1(src); //@violation TYPE_OVERRUN.IN_FUNC_CALL
  }

private:
  char dst[5];

};
