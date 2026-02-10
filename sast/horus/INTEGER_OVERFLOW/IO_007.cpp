#include <stdio.h>
#include <stdlib.h>

/* IO_007 - fscanf4, constraint */
char IO_007_function(int flag) {
  char data = ' ';
  fscanf(stdin, "%c", &data);

  if(flag > 10) {
    if(data < 127) {
      char result = data * 50; //It's ok.
      return result;
    }
  }
  else {
    char result2 = data * 50; //@violation INTEGER_OVERFLOW
    return result2;
  }

  return 0;
}



