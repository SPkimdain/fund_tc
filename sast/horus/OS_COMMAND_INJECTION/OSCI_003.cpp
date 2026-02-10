#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* OSCI_003 - sanitize call */

int OSCI_003_function1(char* check) {
  if(strpbrk(check, ";\"'.")) {
    return 0;
  }
  return 1;
}

void OSCI_003_function2(int flag) {
  char arg[80];
  char cat[] = "cat ";
  int commandLength = 0;
  
  fgets(arg,80,stdin);

  if(flag > 10) {
    if(OSCI_003_function1(arg) == 0) {
      return;
    }
    system(arg); //It's ok.
  }
  else {
    system(arg); //@violation OS_COMMAND_INJECTION
  } 
  
  return;
}

