#include <memory.h>

/* TOI_002 - simple memset */
struct TOI_002_Class {
  char dst[20];
};


int TOI_002_function() {
  TOI_002_Class obj;

  memset(obj.dst, 50, 20); //It's ok.

  memset(obj.dst, 20, 50); //@violation TYPE_OVERRUN.IN_FUNC_CALL

  return 0;
}
