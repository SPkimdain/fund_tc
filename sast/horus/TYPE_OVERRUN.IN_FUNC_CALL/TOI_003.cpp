#include <string.h>

/* TOI_003 - simple memmove */
struct TOI_003_Class {
  char str[11];
};

void TOI_003_function(int flag) {
  TOI_003_Class obj;
  memcpy(obj.str, "0123456789", 11);

  if(flag == 1) {
    memmove(obj.str + 5, obj.str + 2, 5); //It's ok.
  }
  else {
    memmove(obj.str + 7, obj.str + 2, 5); //@violation TYPE_OVERRUN.IN_FUNC_CALL
  }
}
