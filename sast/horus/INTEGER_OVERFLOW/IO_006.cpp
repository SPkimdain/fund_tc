#include <stdio.h>
#include <stdlib.h>

/* IO_006 - fscanf3 */
void IO_006_function() {
  char data = ' ';
  fscanf(stdin, "%c", &data);

  char result = data * 5; //@violation INTEGER_OVERFLOW
}

