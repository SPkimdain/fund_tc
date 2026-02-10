// @checker PROHIBIT_FUNC_IN_STDLIB

#include <stdlib.h>

void PHBFISTDLIB_001_function() {
  int foo1;
  int foo2;
  int foo3;

  if(foo1 == 0) {
    abort();	//@violation PROHIBIT_FUNC_IN_STDLIB
  }
  else if(foo2 == 1) {
    exit(1);		//@violation PROHIBIT_FUNC_IN_STDLIB
  }
  else if(foo3 == 2) {
    getenv("bar");		//@violation PROHIBIT_FUNC_IN_STDLIB
  }
  else {
    system(0);         //@violation PROHIBIT_FUNC_IN_STDLIB
  }
}
