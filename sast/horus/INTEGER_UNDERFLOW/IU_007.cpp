#include <stdio.h>

/* IU_007 - fscanf, constraint */
void IU_007_function(int flag) {
  char data = ' ';
  fscanf(stdin, "%c", &data);
  if(flag < 10) {
    if(data > -128) {
      char result = data - 1; //It's ok.
    }
  }
  else {
    char result = data - 1; //@violation INTEGER_UNDERFLOW
  }
}

