#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* TOI_008 -  */
class TOI_008_Class {
public:
  void TOI_008_function1(char *source, int size) {
    strncpy(ntbs, source, size);
  }

private:
  char ntbs[5];
};

void TOI_008_function2() {
  TOI_008_Class obj;
  char *b = "123456789";
  obj.TOI_008_function1(b, 6); //@violation TYPE_OVERRUN.IN_FUNC_CALL
}
