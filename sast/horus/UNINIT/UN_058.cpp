#include <stdio.h>

/* UN_058 - unknown object field */

typedef uintptr_t VALUE;

struct UN_058_Struct {
  int a;
  int b;
  char c;
  int ntbl;
  int ntbl2;
};

extern VALUE UN_058_function1();

void UN_058_function2(int flag) {
  VALUE obj;
  obj = UN_058_function1();

  int xx = ((UN_058_Struct*)obj)->ntbl; //It's ok.

  int a;
  int b;
  b = a; //@violation UNINIT

}
