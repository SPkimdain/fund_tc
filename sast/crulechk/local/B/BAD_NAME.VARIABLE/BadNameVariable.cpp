//@checker BAD_NAME.VARIABLE
#include "BadNameVariable.h"

#define SET(X) do{ int tempValue = 2; X += 10; } while(0)

int globalVar;

int BNAMEVAR_001_function1(int param, char param2) {
  int x = 0, y = 0;
  for(int i = 0; i < 10; i++) {
    x++;
  }

  int BADNAMEcheck = 10; //@violation BAD_NAME.VARIABLE
  
  SET(x);

  return 0;
}


int BNAMEVAR_001_function2(bool flag) {
  if(flag == true) {
    char x = 'x';
  }

  return 0;
}
