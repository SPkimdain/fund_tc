#include <stdio.h>

/* IO_005 - fscanf, constraint */
void IO_005_function(int flag) {
  char data = ' ';
  fscanf(stdin, "%c", &data);
  if(flag < 10) {
    if(data < 127) {
      char result = data + 1; //It's ok.
    }
  }
  else {
    char result = data + 1; //@violation INTEGER_OVERFLOW
  }
}

