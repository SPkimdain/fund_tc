#include <string.h>

/* TOI_019 - multiple strcat */
class TOI_019_Class {
public:

  void TOI_019_function(int flag) {
    char src[] = "abcde"; //sizeof(src) == 6, len = 5
    char src2[] = "fghi"; //sizeof(src2) == 5, len = 4
    char* ret = 0;
    strcpy(dst, src2); //It's ok. len = 4 + 1

    strcat(dst, src2); //It's ok. len = 4 + 4 + 1
    strcat(dst, src); //It's ok. len = 4 + 4 + 5 + 1
    strcat(dst, src); //It's ok. len = 4 + 4 + 5 + 5 + 1

    //len = 4 + 4 + 5 + 5 + 5 + 1 = 24
    strcat(dst, src); //@violation TYPE_OVERRUN.IN_FUNC_CALL

  }

private:
  char dst[20];
};

