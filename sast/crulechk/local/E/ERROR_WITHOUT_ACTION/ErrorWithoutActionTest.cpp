//@checker ERROR_WITHOUT_ACTION
#include <stdio.h>

void errorWithoutActionTest1() {
  if(!putchar('a')) { //@violation ERROR_WITHOUT_ACTION
    //Emtpy handling.
  }
}
