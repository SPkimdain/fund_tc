#include <stdio.h>
#include <stdlib.h>

/* CODEI_001 - code injection. */
void CODEI_001_function() {
  int arr[5];
  int var = 0;
  int var2 = 0;

  // read in user input
  printf("Enter index and value to write:");
  scanf("%i", &var);
  scanf("%i", &var2);

  if(var > 4) { //Wrong check. it can be -1.
    return;
  }

  // malicious user might set var to -1 and var2 to an address to execute
  // if say the 32-bit value before the stack variables is the instruction to
  // return to
  arr[var] = var2; //@violation CODE_INJECTION.RETURN_ADDRESS

  return;
}

void CODEI_001_function2() {
  int arr[5];
  int var = 0;
  int var2 = 0;

  // read in user input
  printf("Enter index and value to write:");
  scanf("%i", &var);
  scanf("%i", &var2);

  if(var > 4 || var < 0) { 
    return;
  }

  // malicious user might set var to -1 and var2 to an address to execute
  // if say the 32-bit value before the stack variables is the instruction to
  // return to
  arr[var] = var2; //It's ok.

  return;
}

