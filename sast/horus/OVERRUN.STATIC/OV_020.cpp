#include <string.h>

/* OV_020 - trace value */
int OV_020_function1(int arg) {
  return ++arg;
}

void OV_020_function2() {
  char ch = 'a';
  char dst1[10] = { 0, };
  char dst2[4] = { 0, };

  int index = 3;
  index = OV_020_function1(index); // 4
  index = OV_020_function1(index); // 5
  dst1[index] = ch; //It's ok.
  dst2[index] = ch; //@violation OVERRUN.STATIC
}

