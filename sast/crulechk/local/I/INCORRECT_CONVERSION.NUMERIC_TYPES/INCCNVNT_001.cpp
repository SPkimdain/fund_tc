//@checker INCORRECT_CONVERSION.NUMERIC_TYPES

#include <stdio.h>
#include <stdlib.h>

extern void printFloatLine(float v);

void INCCNVNT_001_function() {
  char inputBuffer[256];
  double doubleNumber = 0;
  if(fgets(inputBuffer, 256, stdin) != NULL) {
    doubleNumber = atof(inputBuffer);
  }
  else {
    printf("fgets() failed.");
  }

  printFloatLine((float)doubleNumber); //@violation INCORRECT_CONVERSION.NUMERIC_TYPES

}

