#include <string.h>

/* TOI_010 - boundary check */
class TOI_010_Class {
public:

  void TOI_010_function1(char* src) {
    strcpy(dst1, src);
  }

  void TOI_010_function2(char* src) {
    strcpy(dst2, src);
  }

private:
  char dst1[5];
  char dst2[6];
};

void TOI_010_function3() {
  char src1[] = "1234"; //sizeof(src1) == 5, len = 4
  char src2[] = "1234567"; //sizeof(src2) == 8, len = 7

  TOI_010_Class obj;
  
  obj.TOI_010_function1(src1); //It's ok.
  obj.TOI_010_function2(src2); //@violation TYPE_OVERRUN.IN_FUNC_CALL
}

