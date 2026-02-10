#include <stdio.h>
#include <stdlib.h>

/* IU_009 - fscanf4, constraint */
char IU_009_function(int flag) {
  char data = ' ';
  fscanf(stdin, "%c", &data);

  if(flag > 10) {
    if(data < 127) {
      char result = data * -20; //It's ok.
      return result;
    }
  }
  else {
    char result2 = data * -10; //@violation INTEGER_UNDERFLOW
    return result2;
  }

  return 0;
}

